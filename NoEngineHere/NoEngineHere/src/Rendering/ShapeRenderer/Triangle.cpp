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


	void Triangle::setVertices(std::vector<glm::vec3> vertices){
		shapeVertices[0] = vertices[0]; shapeVertices[1] = vertices[1]; shapeVertices[2] = vertices[2];
	}

	void Triangle::setVertices(glm::vec3 vertex1, glm::vec3 vertex2, glm::vec3 vertex3){
		shapeVertices[0] = vertex1; shapeVertices[1] = vertex2; shapeVertices[2] = vertex3;
	}


	Triangle::~Triangle(){
		std::cout << "triangle destoryed yeet" << std::endl;
	}

}
