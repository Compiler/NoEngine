#include "Triangle.h"
#include <iostream>



Triangle::Triangle(){
	*positions = glm::vec3(0.0,0.0,0.0); positions += sizeof(glm::vec3);
	*positions = glm::vec3(0.0, 0.0, 0.0); positions += sizeof(glm::vec3);
	*positions = glm::vec3(0.0, 0.0, 0.0); positions -= 2*sizeof(glm::vec3);

}

Triangle::Triangle(glm::vec3 vertex1, glm::vec3 vertex2, glm::vec3 vertex3){
	*positions = vertex1; positions += sizeof(glm::vec3);
	*positions = vertex2; positions += sizeof(glm::vec3);
	*positions = vertex3; positions -= 2*sizeof(glm::vec3);

}



Triangle::~Triangle(){

	delete []positions;
	positions = NULL;

	

	
}
