#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <glm/vec3.hpp>
#include "Rendering/Shaders/Shader.h"
#include "Rendering/ShapeRenderer/Triangle.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

bool w_pressed, s_pressed, a_pressed, d_pressed, rotToggle;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode){
	if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if(key == GLFW_KEY_W && action == GLFW_PRESS)
		w_pressed = true;
	if(key == GLFW_KEY_W && action == GLFW_RELEASE)
		w_pressed = false;

	if(key == GLFW_KEY_S && action == GLFW_PRESS)
		s_pressed = true;
	if(key == GLFW_KEY_S && action == GLFW_RELEASE)
		s_pressed = false;

	if(key == GLFW_KEY_A && action == GLFW_PRESS)
		a_pressed = true;
	if(key == GLFW_KEY_A && action == GLFW_RELEASE)
		a_pressed = false;

	if(key == GLFW_KEY_D && action == GLFW_PRESS)
		d_pressed = true;
	if(key == GLFW_KEY_D && action == GLFW_RELEASE)
		d_pressed = false;

	if(key == GLFW_KEY_LEFT_SHIFT && action == GLFW_PRESS)
		rotToggle = !rotToggle;

}


int main(){
	glfwInit(); //start glfw
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//setting context to 3.?
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//setting context to ?.3      = 3.3
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	GLFWwindow *window = glfwCreateWindow(800, 600, "NoEngine ", nullptr, nullptr);//returns pointer to GLFWwindow object
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);
	//make sure window creation worked
	if (window == nullptr){
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	//create context from the window
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
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

	Shader ourShader("../NoEngineHere/src/Rendering/Shaders/glsl/shader_v.glsl", "../NoEngineHere/src/Rendering/Shaders/glsl/shader_f.glsl");
	//Shader movement("shader_v.glsl", "shader_f.glsl");
	
	

	GLfloat vertices[] = {
		// cubic : spot

		 0, 0, 1,	1, 0, 0,	0, 0, -1,		
		-1, 0, 0,		
		 0, 1, 0
	};

	GLfloat colors[] = {
		// positions	
		 1,0,0,	1,0,0, 1,0,0,    0,1,0, 0,1,0, 0,1,0,	0,0,1, 0,0,1, 0,0,1,
	};

	unsigned int indices[] = {
		0, 1, 2,	0, 2, 3,	3, 1, 4
	};

	

	//fhg

	GLuint VAO, VBO, cBO;
	GLuint EBO;
	


	glGenBuffers(1, &VBO);
	glGenBuffers(1, &cBO);
	glGenBuffers(1, &EBO);

	glGenVertexArrays(1, &VAO);


	glBindBuffer(GL_ARRAY_BUFFER, cBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

	// bind vertex array object to current
	glBindVertexArray(VAO);

	

	
	//bind ebo to vao and give element indices
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


	// bind vbo to vao and give vertices
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// set position of data of attribute pointers (only one here)
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0 * sizeof(GL_FLOAT), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	
	glBindBuffer(GL_ARRAY_BUFFER, cBO);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0 * sizeof(GL_FLOAT), (GLvoid*)(0 * sizeof(GL_FLOAT)));
	glEnableVertexAttribArray(1);
	// unbind the vertex array object
	//glBindVertexArray(0);



	



	glm::mat4 model = glm::mat4(1.0f);
	model = glm::rotate(model, glm::radians(45.f), glm::vec3(1.0f, -1.0f, 0.0f));
	glm::mat4 view = glm::mat4(1.0f);


	// note that we're translating the scene in the reverse direction of where we want to move
	glm::vec3 cpos = glm::vec3(0.0f, 0.0f, -3.0f);
	view = glm::translate(view, cpos);

	glm::mat4 projection = glm::mat4(1.0f);
	projection = glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.0f);


	
	GLfloat speed = 0.005f;
	int modelLoc = glGetUniformLocation(ourShader.program, "model");
	int viewLoc = glGetUniformLocation(ourShader.program, "view");
	int projLoc = glGetUniformLocation(ourShader.program, "projection");
	if(modelLoc == -1)std::cout << "model uniform not found" << std::endl;
	if(viewLoc == -1)std::cout << "view uniform not found" << std::endl;
	if(projLoc == -1)std::cout << "proj uniform not found" << std::endl;

	while (!glfwWindowShouldClose(window))
	{
		if(rotToggle){
			if(w_pressed){
				std::cout << "w action" << std::endl;
				view = glm::translate(view, glm::vec3(0, 0, speed));
			}
			if(s_pressed){
				std::cout << "s action" << std::endl;
				view = glm::translate(view, glm::vec3(0, 0, -speed * 8));
			}
			if(a_pressed){
				std::cout << "a action" << std::endl;
				projection = glm::rotate(projection, glm::radians(speed * 100), glm::vec3(0.0f, -1.0f, 0.0f));

			}
			if(d_pressed){
				std::cout << "d action" << std::endl;
				model = glm::rotate(model, glm::radians(speed * 100), glm::vec3(0.0f, 1.0f, 0.0f));

			}
		} else{
			if(w_pressed){
				std::cout << "t_w action" << std::endl;
				model = glm::rotate(model, glm::radians(speed * 100), glm::vec3(1.0f, 0.0f, -1.0f));
			}
			if(s_pressed){
				std::cout << "t_s action" << std::endl;
				model = glm::rotate(model, glm::radians(speed * 100), glm::vec3(-1.0f, 0.0f, 1.0f));
			}
			if(a_pressed){
				std::cout << "t_a action" << std::endl;
				model = glm::rotate(model, glm::radians(speed * 100), glm::vec3(1.0f, 1.0f, -1.0f));

			}
			if(d_pressed){
				std::cout << "t_d action" << std::endl;
				model = glm::rotate(model, glm::radians(speed * 100), glm::vec3(-1.0f, -1.0f, 1.0f));

			}
		
		}

		glfwPollEvents();
		glClearColor(.1f, .1f, .1f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		//model = glm::rotate(model, (float)glfwGetTime() / 1000.0f, glm::vec3(1.0f, 0.0f, 1.0f));
		
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

		
		
		// use shader program
		ourShader.Use();


		

		// draw
		//glBindVertexArray(VAO);
	//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
		//glBindVertexArray(0);

		glfwSwapBuffers(window);
	}

	// deallocate all resources
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	// terminate GLFW
	glfwTerminate();

	std::cout << "uh";


	return 0;
}