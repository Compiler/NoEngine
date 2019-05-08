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
	}

	void PerspectiveCamera::update(){

		glm::vec3 front;
		front.x = cos(glm::radians(_yaw)) * cos(glm::radians(_pitch));
		front.y = sin(glm::radians(_pitch));
		front.z = sin(glm::radians(_yaw)) * cos(glm::radians(_pitch));

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

	void PerspectiveCamera::translate(const glm::vec3& translation){
		p_cameraPosition += translation;
	}


	void PerspectiveCamera::control3DHeadMovement(float xoffset, float yoffset, bool constrainPitch){
		xoffset *= 0.1f;
		yoffset *= 0.1f;

		//std::cout << _yaw << " + " << xoffset << " = ";
		this->_yaw += xoffset;
		this->_pitch += yoffset;
		//std::cout << _yaw << std::endl;

		if(constrainPitch){
			if(this->_pitch > 89.0f)
				this->_pitch = 89.0f;
			if(this->_pitch < -89.0f)
				this->_pitch = -89.0f;
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