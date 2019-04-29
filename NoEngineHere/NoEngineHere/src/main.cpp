#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <glm/vec3.hpp>
#include "Rendering/Shaders/Shader.h"
#include "Rendering/ShapeRenderer/Triangle.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Rendering/Renderer/IndexBuffer.h"
#include "Rendering/Renderer/VertexBuffer.h"
#include "Rendering/Renderer/VertexArray.h"
#include "Rendering/Renderer/VertexBufferLayout.h"
#include "Rendering/Renderer/Renderer.h"

#include "Rendering/ShapeRenderer/ShapeRenderer.h"

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
	if(window == nullptr){
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	//create context from the window
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	glewExperimental = GL_TRUE;
	if(glewInit() != GLEW_OK){
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	std::cout << width;
	glfwSetKeyCallback(window, key_callback);
	std::string vertexShaderPath = "../NoEngineHere/src/Rendering/Shaders/glsl/shader_v.glsl";
	std::string fragmentShaderPath = "../NoEngineHere/src/Rendering/Shaders/glsl/shader_f.glsl";
	//noe::Shader ourShader(vertexShaderPath, fragmentShaderPath);
	noe::Shader ourShader;
	ourShader.init(vertexShaderPath, fragmentShaderPath);



	GLfloat vertices[] = {
		 0, 0, 1,	1, 0, 0,	0, 0, -1,
		//-1, 0, 0,
		// 0, 1, 0
	};

	GLfloat colors[] = {
		 0,0,1,1,  0,0,1,1,  0,0,1,1   //  1,0,0, 1,0,0, 1,0,0,    0,1,0, 0,1,0, 0,1,0,
	};

	//unsigned int indices[] = {
	//	0, 1, 2,	0, 2, 3,	3, 1, 4
	//};


	GLuint VAO, VBO, cBO;
	GLuint EBO;


	//noe::VertexBuffer colorBuffer(colors, 9 * 3 * sizeof(float));
	noe::VertexBuffer verticesBuffer, colorBuffer;
	verticesBuffer.init(vertices, 3 * 3 * sizeof(float));
	colorBuffer.init(colors, 12 * 4);
	//noe::IndexBuffer indexBuffer(indices, 3*3);



	noe::VertexArray vao;
	noe::VertexBufferLayout layout;

	layout.push<float>(3);
	vao.addBuffer(verticesBuffer, layout);

	layout.push<float>(4);
	vao.addBuffer(colorBuffer, layout);

	


	//indexBuffer.bind();


	glm::mat4 model = glm::mat4(1.0f);
	model = glm::rotate(model, glm::radians(45.f), glm::vec3(1.0f, -1.0f, 0.0f));
	glm::mat4 view = glm::mat4(1.0f);


	// note that we're translating the scene in the reverse direction of where we want to move
	glm::vec3 cpos = glm::vec3(0.0f, 0.0f, -3.0f);
	view = glm::translate(view, cpos);

	glm::mat4 projection = glm::mat4(1.0f);
	projection = glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.0f);



	GLfloat speed = 0.005f;


	noe::ShapeRenderer shapeRenderer;


	while(!glfwWindowShouldClose(window)){
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
		} 
		else{
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
		
		shapeRenderer.clear();
		shapeRenderer.setMatrices(model, view, projection);


		shapeRenderer.begin();
		shapeRenderer.drawTriangle(glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec4(1.0f, 1.0f, 0.0f, 1.0f));
		shapeRenderer.end();



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