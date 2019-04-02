#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <glm/vec3.hpp>
#include "Shader.h"
#include "Triangle.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

bool w_pressed;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode){
	if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if(key == GLFW_KEY_W && action == GLFW_PRESS)
		w_pressed = true;
	if(key == GLFW_KEY_W && action == GLFW_RELEASE)
		w_pressed = false;
}


int main(){
	glfwInit(); //start glfw
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//setting context to 3.?
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//setting context to ?.3      = 3.3
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	GLFWwindow *window = glfwCreateWindow(800, 600, "NoEngine ", nullptr, nullptr);//returns pointer to GLFWwindow object

	//make sure window creation worked
	if (window == nullptr){
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	//create context from the window
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK){
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	std::cout << width;
	glfwSetKeyCallback(window, key_callback);

	Shader ourShader("shader_v.glsl", "shader_f.glsl");
	//Shader movement("shader_v.glsl", "shader_f.glsl");
	
	

	GLfloat vertices[] = {
		// positions	
		 -0.5f, -0.5f, 0.0f,	0.0f, -0.5f, 0.0f,	0.0f, 0.5f, 0.25f,
		 -0.5f, -0.5f, 0.0f,	0.0f, 0.5f, 0.5f,	0.0f, 0.5f, 0.25f,
		 0.0f, -0.5f, 0.0f,		0.5f, -0.5f, 0.0f,	0.0f, 0.5f, 0.25f,
		 0.5f, -0.5f, 0.0f,		0.0f, 0.5f, 0.5f,	0.0f, 0.5f, 0.25f,
		 -0.5f, -0.5f, 0.0f,	0.5f, -0.5f, 0.0f,	0.0f, 0.5f, 0.5f
		 //0.75f, 0.75f, 0.0f,	1.0f, 0.75f, 0.0f,	0.875f, 1.0f, 0.0f
	};




	GLuint VAO, VBO;
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);

	// bind vertex array object
	glBindVertexArray(VAO);

	// copy the vertices in a buffer
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// set position attribute pointers
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
	glEnableVertexAttribArray(0);

	// unbind the vertex array object
	glBindVertexArray(0);


	glm::mat4 model = glm::mat4(1.0f);
	model = glm::rotate(model, glm::radians(45.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	glm::mat4 view = glm::mat4(1.0f);
	// note that we're translating the scene in the reverse direction of where we want to move
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

	glm::mat4 projection = glm::mat4(1.0f);
	projection = glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.0f);


	

	while (!glfwWindowShouldClose(window))
	{
		if(w_pressed)
			std::cout << "w action" << std::endl;
		glfwPollEvents();
		glClearColor(.1f, .1f, .1f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);

		//model = glm::rotate(model, (float)glfwGetTime() / 1000.0f, glm::vec3(1.0f, 0.0f, 0.0f));
		int modelLoc = glGetUniformLocation(ourShader.program, "model");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		int viewLoc = glGetUniformLocation(ourShader.program, "view");
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		int projLoc = glGetUniformLocation(ourShader.program, "projection");
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

		
		
		// use shader program
		ourShader.Use();


		

		// draw
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 15);
		glBindVertexArray(0);

		glfwSwapBuffers(window);
	}

	// deallocate all resources
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	// terminate GLFW
	glfwTerminate();

	std::cout << "uh";


	return 0;
}