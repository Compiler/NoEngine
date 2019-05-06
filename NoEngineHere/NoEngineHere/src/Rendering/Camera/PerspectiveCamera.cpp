#include "PerspectiveCamera.h"

namespace noe{

	PerspectiveCamera::PerspectiveCamera(float viewportWidth, float viewportHeight, glm::vec3 position, float near, float far): _cameraUp(glm::vec3(0.0f, 1.0f, 0.0f)){
		this->p_cameraPosition = position;
		this->p_cameraDirection = glm::vec3(0.0f, 0.0f, -1.0f);
		this->_worldUp = glm::vec3(0, 1, 0);


		p_projection = glm::perspective(glm::radians(45.0f), (float)(viewportWidth / viewportHeight), near, far);
	}




	void PerspectiveCamera::rotate(float angleDegrees, const glm::vec3& axisOfRotation){
		//p_cameraDirection.x = cos(glm::radians(angleDegrees)) * axisOfRotation.x; //* cos(glm::radians(Pitch));
		p_cameraDirection.y = sin(glm::radians(angleDegrees)) * axisOfRotation.y;
		//p_cameraDirection.z = sin(glm::radians(angleDegrees)) * axisOfRotation.z; //* cos(glm::radians(Pitch));
		p_cameraDirection = glm::normalize(p_cameraDirection);


		_cameraRight = glm::normalize(glm::cross(p_cameraDirection, _worldUp));
		_cameraUp = glm::normalize(glm::cross(_cameraRight, p_cameraDirection));
		//p_cameraDirection = glm::rotate(p_cameraDirection, glm::radians(angleDegrees), axisOfRotation);
		//p_projection = glm::rotate(p_projection, glm::radians(angleDegrees), axisOfRotation);
	}


	void PerspectiveCamera::translate(const glm::vec3& translation){
	
	
	
	}



	glm::mat4 PerspectiveCamera::getWorldToViewMatrix(){
		p_view = glm::lookAt(p_cameraPosition, p_cameraPosition + p_cameraDirection, this->p_cameraUp);
		return p_view;
	}
	


	glm::mat4 PerspectiveCamera::getProjectionMatrices(){
		return p_projection * getWorldToViewMatrix();
	
	}

	


}