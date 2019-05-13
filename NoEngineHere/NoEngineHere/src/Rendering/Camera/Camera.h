#pragma once
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>

namespace noe{

	class Camera{

	public:

		static enum DIRECTION{ FORWARD, BACKWARD, LEFT, RIGHT };

		Camera(){}
		Camera(float viewportWidth, float viewportHeight, glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f));

		//	translate x,y,z amount
		virtual void translate(const glm::vec3& translation) = 0;
		virtual void translate(DIRECTION direction, float deltaTime) = 0;

		/*	rotate angleDegrees around axisOfRotation
			example: 45, (1,0,0) = 45 degrees around x axis	*/


		// lookAt the position.. duh
		//virtual void lookAt(const glm::vec3& position) = 0;


		virtual glm::mat4 getProjectionMatrices() const = 0;
		virtual glm::mat4 getWorldToViewMatrix() const = 0;



	protected:

		glm::mat4 p_projection, p_view;
		glm::vec3 p_cameraPosition, p_cameraDirection;

		glm::vec2 p_viewport;

	};

}