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
		this->shapeVertices.at(0).x += xAmount; this->shapeVertices.at(0).y += yAmount; this->shapeVertices.at(0).z += zAmount;
		this->shapeVertices.at(1).x += xAmount; this->shapeVertices.at(1).y += yAmount; this->shapeVertices.at(1).z += zAmount;
		this->shapeVertices.at(2).x += xAmount; this->shapeVertices.at(2).y += yAmount; this->shapeVertices.at(2).z += zAmount;
	}

	void Triangle::translateX(float amount){
		this->shapeVertices.at(0).x += amount; this->shapeVertices.at(1).x += amount; this->shapeVertices.at(2).x += amount;
	}
	void Triangle::translateY(float amount){
		this->shapeVertices.at(0).y += amount; this->shapeVertices.at(1).y += amount; this->shapeVertices.at(2).y += amount;
	}
	void Triangle::translateZ(float amount){
		this->shapeVertices.at(0).z += amount; this->shapeVertices.at(1).z += amount; this->shapeVertices.at(2).z += amount;
	}


	void Triangle::setVertices(const std::vector<glm::vec3>& vertices){
		if(vertices.size() != 4){
			exit(-4);
		}
		shapeVertices[0].x = vertices[0].x; shapeVertices[0].y = vertices[0].y; shapeVertices[0].z = vertices[0].z;
		shapeVertices[1].x = vertices[1].x; shapeVertices[1].y = vertices[1].y; shapeVertices[1].z = vertices[1].z;
		shapeVertices[2].x = vertices[2].x; shapeVertices[2].y = vertices[2].y; shapeVertices[2].z = vertices[2].z;
	}

	void Triangle::setVertices(glm::vec3 vertex1, glm::vec3 vertex2, glm::vec3 vertex3){
		shapeVertices[0].x = vertex1.x, shapeVertices[0].y = vertex1.y; shapeVertices[0].z = vertex1.z;
		shapeVertices[1].x = vertex2.x, shapeVertices[1].y = vertex2.y; shapeVertices[1].z = vertex2.z;
		shapeVertices[2].x = vertex3.x, shapeVertices[2].y = vertex3.y; shapeVertices[2].z = vertex3.z;
	}


	Triangle::~Triangle(){
		std::cout << "triangle destoryed yeet" << std::endl;
	}

}
