#pragma once
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera{

public:

	//	translate x,y,z amount
	virtual void translate(glm::vec3 translation) = 0;

	/*	rotate angleRadians around axisOfRotation
		example: 45, (1,0,0) = 45 degrees around x axis	*/
	virtual void rotate(float angleRadians, glm::vec3 axisOfRotation) = 0;


protected:

	glm::mat4 projection, view;
	glm::vec3 cameraPosition, cameraTarget, cameraDirection;


};