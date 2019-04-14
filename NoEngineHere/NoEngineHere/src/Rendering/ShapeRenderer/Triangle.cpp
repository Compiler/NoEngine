#include "Triangle.h"
#include <iostream>


namespace noe{

	Triangle::Triangle(){
		this->shapeVertices.reserve(VERT_COUNT); //3 vertices in triangle
		shapeVertices.emplace_back(glm::vec3(), glm::vec3(), glm::vec3());

	}

	Triangle::Triangle(glm::vec3 vertex1, glm::vec3 vertex2, glm::vec3 vertex3){
		this->shapeVertices.reserve(VERT_COUNT);
		shapeVertices.emplace_back(vertex1, vertex2, vertex3);

	}

	void Triangle::setVertices(std::vector<glm::vec3> vertices){
		for(int i = 0; i < VERT_COUNT; i++)
			shapeVertices[i] = vertices[i];
		

	}

}
