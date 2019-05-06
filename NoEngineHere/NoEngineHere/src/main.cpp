#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <glm/vec3.hpp>
#include "Rendering/Shaders/Shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Rendering/Renderer/IndexBuffer.h"
#include "Rendering/Renderer/VertexBuffer.h"
#include "Rendering/Renderer/VertexArray.h"
#include "Rendering/Renderer/VertexBufferLayout.h"
#include "Rendering/Renderer/Renderer.h"

#include "Rendering/ShapeRenderer/ShapeRenderer.h"
#include "Rendering/ShapeRenderer/Triangle.h"
#include "Rendering/ShapeRenderer/Rectangle.h"

#include "Rendering/Camera/PerspectiveCamera.h"

bool w_pressed, s_pressed, a_pressed, d_pressed, rotToggle;


// timing
static float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;


bool firstMouse = true;
float lastX = 800 / 2.0f;
float lastY = 600 / 2.0f;


noe::PerspectiveCamera camera(800, 600, glm::vec3(0.0f, 0.0f, 3.0f));

void cameraControl(noe::PerspectiveCamera& camera, glm::mat4 &_projection, float _speed);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

// glfw: whenever the mouse moves, this callback is called
void mouse_callback(GLFWwindow* window, double xpos, double ypos){
	if(firstMouse){
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	std::cout << "[(" << xpos << ", " << ypos << "), ";

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
	lastX = xpos;
	lastY = ypos;

	std::cout << "(" << xoffset << ", " << yoffset << ")]" << std::endl;
	camera.control3DHeadMovement(xoffset, yoffset);
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


	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetKeyCallback(window, key_callback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);


	std::string vertexShaderPath = "../NoEngineHere/src/Rendering/Shaders/glsl/shader_v.glsl";
	std::string fragmentShaderPath = "../NoEngineHere/src/Rendering/Shaders/glsl/shader_f.glsl";


	noe::PerspectiveCamera camera(800, 600, glm::vec3(0.0f, 0.0f, 3.0f));
	//camera.translate(noe::Camera::DIRECTION::FORWARD, deltaTime);


	//camera.rotate(0, glm::vec3(0, 0, 0));
	//(float)800 / (float)600
	//1920, 1080

	glm::mat4 model = glm::mat4(1.0f);
	//model = glm::rotate(model, glm::radians(45.f), glm::vec3(1.0f, -1.0f, 0.0f));
	glm::mat4 view = glm::mat4(1.0f);


	// note that we're translating the scene in the reverse direction of where we want to move
	//glm::vec3 cpos = glm::vec3(0.0f, 0.0f, -3.0f);
	//view = camera.getWorldToViewMatrix(); //*glm::translate(view, cpos);
	//view = glm::translate(view, cpos);
	glm::mat4 projection = camera.getProjectionMatrices();
	//glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)(800 / 600), 0.1f, 100.0f);



	GLfloat speed = 2.5f;


	noe::ShapeRenderer shapeRenderer;


	noe::Triangle triangle1;
	triangle1.setVertices(glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	triangle1.setColor(noe::Color(1.0f,1.0f,1.0f));//white
	
	noe::Rectangle rectangle1(glm::vec3(2.0f, 1.0f, 0.0f), 1, 1);
	rectangle1.setColor(noe::Color(0.0f, 1.0f, 0.0f));
	rectangle1.setPosition(glm::vec3(-1,-1,0));
	

	while(!glfwWindowShouldClose(window)){


		

		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		
		cameraControl(camera, projection, speed * deltaTime);
	


		glfwPollEvents();

		shapeRenderer.clear();

		shapeRenderer.begin();
		//shapeRenderer.drawTriangle(triangle1);
		shapeRenderer.drawTriangle(glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
		shapeRenderer.drawTriangle(glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));
		//shapeRenderer.drawRect(rectangle1);
		shapeRenderer.end();
		//camera.update();
		shapeRenderer.setMatrices(model, view, camera.getProjectionMatrices());


		glfwSwapBuffers(window);
	}




	// terminate GLFW
	glfwTerminate();

	std::cout << "uh";


	return 0;
}


void cameraControl(noe::PerspectiveCamera& camera, glm::mat4 &_projection, float _speed){


	if(!rotToggle){
		if(w_pressed){
			std::cout << "w action" << std::endl;
			camera.translate(noe::Camera::DIRECTION::FORWARD, deltaTime);
		}
		if(s_pressed){
			std::cout << "s action" << std::endl;
			camera.translate(noe::Camera::DIRECTION::BACKWARD, deltaTime);

			//_view = glm::translate(_view, glm::vec3(0, 0, -_speed * 8));
		}
		if(a_pressed){
			std::cout << "a action" << std::endl;
			camera.translate(noe::Camera::DIRECTION::LEFT, deltaTime);
			//_projection = glm::rotate(_projection, glm::radians(_speed * 100), glm::vec3(0.0f, -1.0f, 0.0f));

		}
		if(d_pressed){
			std::cout << "d action" << std::endl;
			camera.translate(noe::Camera::DIRECTION::RIGHT, deltaTime);
			//_model = glm::rotate(_model, glm::radians(_speed * 100), glm::vec3(0.0f, 1.0f, 0.0f));

		}
	} else{
		if(w_pressed){
			std::cout << "t_w action" << std::endl;
			//_model = glm::rotate(_model, glm::radians(_speed * 100), glm::vec3(1.0f, 0.0f, -1.0f));
		}
		if(s_pressed){
			std::cout << "t_s action" << std::endl;
			//_model = glm::rotate(_model, glm::radians(_speed * 100), glm::vec3(-1.0f, 0.0f, 1.0f));
		}
		if(a_pressed){
			std::cout << "t_a action" << std::endl;
			//_model = glm::rotate(_model, glm::radians(_speed * 100), glm::vec3(1.0f, 1.0f, -1.0f));

		}
		if(d_pressed){
			std::cout << "t_d action" << std::endl;
			//_model = glm::rotate(_model, glm::radians(_speed * 100), glm::vec3(-1.0f, -1.0f, 1.0f));

		}

	}

}

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
