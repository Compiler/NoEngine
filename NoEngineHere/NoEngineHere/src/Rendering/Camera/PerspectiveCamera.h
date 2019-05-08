#pragma once
#include "Camera.h"

#include <iostream>

namespace noe{
	class PerspectiveCamera : Camera{


	public:

		

		PerspectiveCamera(float viewportWidth, float viewportHeight, glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), float near = 0.1f, float far = 100.0f, float yaw = -90, float pitch = 0);
		

		void rotate(float angleDegrees, const glm::vec3& axisOfRotation);
		void translate(DIRECTION direction, float deltaTime);
		void translate(const glm::vec3& translation);
		void control3DHeadMovement(float xoffset, float yoffset, bool constrainPitch = true);
		void setYaw(float yaw){ _yaw += yaw; }
		void setPitch(float pitch){ _pitch += pitch; }

		float getYaw(){ return _yaw; }
		float getPitch(){ return _pitch; }


		glm::mat4 getWorldToViewMatrix()const;
		glm::mat4 getProjectionMatrices()const;

		void update();

	private:

		glm::vec3 _cameraUp, _cameraRight, _worldUp;
		float _yaw, _pitch;


	};
}

