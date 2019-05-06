#include "PerspectiveCamera.h"

namespace noe{

	PerspectiveCamera::PerspectiveCamera(float viewportWidth, float viewportHeight, glm::vec3 position, float near, float far, float yaw, float pitch)
		:_cameraUp(glm::vec3(0.0f, 1.0f, 0.0f)), _yaw(yaw), _pitch(pitch){

		this->p_cameraPosition = position;
		this->p_cameraDirection = glm::vec3(0.0f, 0.0f, -1.0f);
		this->_worldUp = glm::vec3(0, 1, 0);
		this->_cameraUp = glm::vec3(0, 1, 0);

		p_projection = glm::perspective(glm::radians(45.0f), (float)(viewportWidth / viewportHeight), near, far);
		update();
	}




	void PerspectiveCamera::rotate(float angleDegrees, const glm::vec3& axisOfRotation){
		//p_cameraDirection.x = cos(glm::radians(angleDegrees)) * cos(glm::radians(Pitch));
		//p_cameraDirection.y = sin(glm::radians(angleDegrees));
		//p_cameraDirection.z = sin(glm::radians(angleDegrees)) *  cos(glm::radians(Pitch));
		
		//p_cameraDirection = glm::rotate(p_cameraDirection, glm::radians(angleDegrees), axisOfRotation);
		//p_projection = glm::rotate(p_projection, glm::radians(angleDegrees), axisOfRotation);
	}

	void PerspectiveCamera::update(){

		glm::vec3 front;
		front.x = cos(glm::radians(_yaw)) * cos(glm::radians(_pitch));
		front.y = sin(glm::radians(_pitch));
		front.z = sin(glm::radians(_yaw)) * cos(glm::radians(_pitch));
		//p_cameraDirection.x = cos(glm::radians(_yaw)) * cos(glm::radians(_pitch));
		//p_cameraDirection.y = sin(glm::radians(_pitch));
		//p_cameraDirection.z = sin(glm::radians(_yaw)) *  cos(glm::radians(_pitch));


		//p_cameraDirection = glm::normalize(p_cameraDirection);
		p_cameraDirection = glm::normalize(front);
		_cameraRight = glm::normalize(glm::cross(p_cameraDirection, _worldUp));
		_cameraUp = glm::normalize(glm::cross(_cameraRight, p_cameraDirection));
	}


	void PerspectiveCamera::translate(DIRECTION direction, float deltaTime){
		float velocity = 2.5f * deltaTime;
		if(direction == FORWARD)
			p_cameraPosition += p_cameraDirection * velocity;
		if(direction == BACKWARD)
			p_cameraPosition -= p_cameraDirection * velocity;
		if(direction == LEFT)
			p_cameraPosition -= _cameraRight * velocity;
		if(direction == RIGHT)
			p_cameraPosition += _cameraRight * velocity;
	}


	void PerspectiveCamera::control3DHeadMovement(float xoffset, float yoffset, bool constrainPitch){
		xoffset *= 0.1f;
		yoffset *= 0.1f;



		_yaw += xoffset;
		_pitch += yoffset;

		if(constrainPitch){
			if(_pitch > 89.0f)
				_pitch = 89.0f;
			if(_pitch < -89.0f)
				_pitch = -89.0f;
		}

		
		update();
	}



	glm::mat4 PerspectiveCamera::getWorldToViewMatrix() const{
		return glm::lookAt(p_cameraPosition, p_cameraPosition + p_cameraDirection, this->_cameraUp);;
	}
	


	glm::mat4 PerspectiveCamera::getProjectionMatrices() const{
		return p_projection * getWorldToViewMatrix();
	
	}

	


}