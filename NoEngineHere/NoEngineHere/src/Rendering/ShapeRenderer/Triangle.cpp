#include "Triangle.h"
#include <iostream>


namespace noe{

	Triangle::Triangle(){
		this->shapeVertices.reserve(_VERT_COUNT); //3 vertices in triangle
		shapeVertices.emplace_back(glm::vec3());
		shapeVertices.emplace_back(glm::vec3());
		shapeVertices.emplace_back(glm::vec3());

	}

	Triangle::Triangle(glm::vec3 vertex1, glm::vec3 vertex2, glm::vec3 vertex3){
		this->shapeVertices.reserve(_VERT_COUNT);
		shapeVertices.emplace_back(vertex1);
		shapeVertices.emplace_back(vertex2);
		shapeVertices.emplace_back(vertex3);

	}

	void Triangle::translate(float xAmount, float yAmount, float zAmount){
		//shapeVertices
	
	}

	void Triangle::setVertices(std::vector<glm::vec3> vertices){
		for(int i = 0; i < _VERT_COUNT; i++)
			shapeVertices[i] = vertices[i];
		

	}

}
