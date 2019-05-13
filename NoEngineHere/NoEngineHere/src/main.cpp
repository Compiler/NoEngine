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


#include "externs/imgui/imgui.h"
#include "externs/imgui/imgui_impl_glfw.h"
#include "externs/imgui/imgui_impl_opengl3.h"

bool w_pressed, s_pressed, a_pressed, d_pressed, rotToggle;


// timing
static float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;


bool firstMouse = true;
float lastX = 1280 / 2.0f;
float lastY = 720 / 2.0f;

int myWidth = 1280;
int myHeight = 720;

noe::PerspectiveCamera camera(myWidth, myHeight, glm::vec3(0.0f, 0.0f, 3.0f));

void cameraControl(noe::PerspectiveCamera& camera, glm::mat4 &_projection, float _speed);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);


void framebuffer_size_callback(GLFWwindow* window, int width, int height){
	myWidth = width;
	myHeight = height;
	glViewport(0, 0, width, height);
}

// glfw: whenever the mouse moves, this callback is called
void mouse_callback(GLFWwindow* window, double xpos, double ypos){
	if(firstMouse){
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}


	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
	lastX = xpos;
	lastY = ypos;

	//camera.control3DHeadMovement(xoffset, yoffset);
}

void applyStyle();


int main(){
	glfwInit(); //start glfw
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//setting context to 3.?
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//setting context to ?.3      = 3.3
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	GLFWwindow *window = glfwCreateWindow(myWidth, myHeight, "NoEngine ", nullptr, nullptr);//returns pointer to GLFWwindow object
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


	//int width, height;
	//glfwGetFramebufferSize(window, &width, &height);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glViewport(0, 0, myWidth, myHeight);
	std::cout << myWidth;


	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetKeyCallback(window, key_callback);
	//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);


	std::string vertexShaderPath = "../NoEngineHere/src/Rendering/Shaders/glsl/shader_v.glsl";
	std::string fragmentShaderPath = "../NoEngineHere/src/Rendering/Shaders/glsl/shader_f.glsl";


	glm::mat4 projection = camera.getProjectionMatrices();



	GLfloat speed = 2.5f;


	noe::ShapeRenderer shapeRenderer;

	noe::Triangle triangle1;
	triangle1.setVertices(glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	triangle1.setColor(noe::Color(1.0f,1.0f,1.0f));//white
	
	noe::Rectangle rectangle1(glm::vec3(2.0f, 1.0f, 0.0f), 1, 1);
	rectangle1.setColor(noe::Color(0.0f, 1.0f, 0.0f));
	rectangle1.setPosition(glm::vec3(-1,-1,0));
	





	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	//io.ConfigFlags = 
	
	ImGui::StyleColorsDark();


	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");

	bool show_demo_window = true;
	bool show_another_window = false;
	glm::vec4 clearColor = glm::vec4(0.086f, 0.376f, 0.529f, 1);

	const char* thing = "Camera";
	
	applyStyle();

	
	while(!glfwWindowShouldClose(window)){
		shapeRenderer.clear();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();


		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		
		cameraControl(camera, projection, speed * deltaTime);
	


		glfwPollEvents();

		shapeRenderer.clear(clearColor.r, clearColor.g, clearColor.b, clearColor.a);

		//shapeRenderer.begin();
		//shapeRenderer.drawTriangle(glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
		//shapeRenderer.drawTriangle(glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));
		//shapeRenderer.end();
		//std::cout << "(" << camera.getYaw() << ", " << camera.getPitch() << ")]" << std::endl;
		camera.update();
		shapeRenderer.setMatrices(glm::mat4(1.0f), glm::mat4(1.0f), camera.getProjectionMatrices());


		ImGui::ShowDemoWindow(&show_demo_window);
		if(true){
			static float f = 0.0f;
			static int counter = 0;


			//menu
			ImGui::BeginMainMenuBar();
			float mainHeight = ImGui::GetWindowHeight();
			float ratioAllowed = 6;
			float bottomPad = (myHeight / ratioAllowed);

			if(ImGui::BeginMenu("File")){
				if(ImGui::MenuItem("New", "ctrl + n", false, true)){
				
				}
				if(ImGui::MenuItem("Save", "ctrl + s", false, true)){
				
				}


				ImGui::EndMenu();
			
			}

			ImGui::EndMainMenuBar();
			ImGui::SetNextWindowPos(ImVec2(0, myHeight - bottomPad));
			ImGui::SetNextWindowSize(ImVec2(myWidth, bottomPad));
			ImGui::Begin("Console", 0, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);
			ImGui::End();

			ImGui::SetNextWindowPos(ImVec2(0, mainHeight));
			ImGui::SetNextWindowSize(ImVec2(myWidth / ratioAllowed, myHeight - mainHeight - bottomPad));

			ImGui::Begin("Toolbar", 0, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);
			if(ImGui::CollapsingHeader("ShapeRenderer")){
				ImGui::Button("ShapeRenderer");
				if(ImGui::IsItemActive())
					thing = "ShapeRenderer\0";

			}


			if(ImGui::CollapsingHeader("Renderer")){
				ImGui::Button("Renderer");
				if(ImGui::IsItemActive())
					thing = "Renderer\0";
				ImGuiStyle& style = ImGui::GetStyle();

				ImGui::BeginChild("##colors", ImVec2(0, 0), true);
				//ImGui::PushItemWidth(-160);
				ImGui::ColorEdit4("Clear color", &clearColor.x, ImGuiColorEditFlags_AlphaBar);
				ImGui::SameLine(0.0f, style.ItemInnerSpacing.x); ImGui::SameLine(0.0f, style.ItemInnerSpacing.x);


				ImGui::SameLine(0.0f, style.ItemInnerSpacing.x);
				//ImGui::TextUnformatted("dude fuck");
				//ImGui::PopItemWidth();
				ImGui::EndChild();
			}

			ImGui::End();



			ImGui::SetNextWindowPos(ImVec2(myWidth - (myWidth / ratioAllowed), mainHeight));
			ImGui::SetNextWindowSize(ImVec2((myWidth / ratioAllowed), myHeight - mainHeight - bottomPad));

			char name[100] = "Properties - ";
			int i = 0;
			for(i = 0; i < 80; i++) if(thing[i] != '\0') name[i + 13] = thing[i];
			name[i + 13] = '\0';
			ImGui::Begin(name, 0, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);
			ImGui::Text(thing);
			
			

			ImGui::End();
			

		}


		//int display_w, display_h;
		ImGui::Render();
		glfwMakeContextCurrent(window);
		//glfwGetFramebufferSize(window, &display_w, &display_h);
		
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());







		glfwSwapBuffers(window);
	}




	// terminate GLFW
	glfwTerminate();

	std::cout << "uh";


	return 0;
}

void applyStyle(){

	ImGuiStyle* style = &ImGui::GetStyle();
	style->Colors[ImGuiCol_WindowBg] = ImVec4(0.039f, 0.039f, 0.039f, 1);
	style->Colors[ImGuiCol_TitleBg] = ImVec4(0.094f, 0.024f, 0.302f, 1);
	style->Colors[ImGuiCol_TitleBgActive] = ImVec4(0.129f, 0.094f, 0.58f, 1);
	style->Colors[ImGuiCol_MenuBarBg] = ImVec4(0.475f, 0.031f, 1, 1);

	style->Colors[ImGuiCol_Header] = ImVec4(0.478f, 0.094f, 0.635f, 1);
	style->Colors[ImGuiCol_Border] = ImVec4(0.325f, 0, 0.73f, 0.5f);




	style->WindowRounding = 0.0f;




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
		}
		if(a_pressed){
			std::cout << "a action" << std::endl;
			camera.translate(noe::Camera::DIRECTION::LEFT, deltaTime);

		}
		if(d_pressed){
			std::cout << "d action" << std::endl;
			camera.translate(noe::Camera::DIRECTION::RIGHT, deltaTime);
		}
	} else{
		if(w_pressed){
			std::cout << "t_w action" << std::endl;
		}
		if(s_pressed){
			std::cout << "t_s action" << std::endl;
		}
		if(a_pressed){
			std::cout << "t_a action" << std::endl;

		}
		if(d_pressed){
			std::cout << "t_d action" << std::endl;
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
