#pragma once

#include <glm/vec3.hpp>

class Triangle
{
public:
	Triangle();
	Triangle(glm::vec3 vertex1, glm::vec3 vertex2, glm::vec3 vertex3);




	~Triangle();


private:
	
	glm::vec3* positions = new glm::vec3[3];

};

