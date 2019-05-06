#pragma once
#include "Camera.h"


namespace noe{
	class PerspectiveCamera: Camera{

	public:
		PerspectiveCamera(float viewportWidth, float viewportHeight, glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), float near = 0.1f, float far = 100.0f);
		

		void rotate(float angleDegrees, const glm::vec3& axisOfRotation);
		void translate(const glm::vec3& translation);


		glm::mat4 getWorldToViewMatrix();
		glm::mat4 getProjectionMatrices();


	private:

		glm::vec3 _cameraUp, _cameraRight, _worldUp;
		float _yaw, _pitch;
	};
}

