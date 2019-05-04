#include "Triangle.h"
#include <iostream>


namespace noe{

	Triangle::Triangle(){
		this->p_shapeVertices.reserve(_VERT_COUNT); //3 vertices in triangle
		p_shapeVertices.emplace_back(glm::vec3());
		p_shapeVertices.emplace_back(glm::vec3());
		p_shapeVertices.emplace_back(glm::vec3());

	}

	Triangle::Triangle(glm::vec3 vertex1, glm::vec3 vertex2, glm::vec3 vertex3){
		this->p_shapeVertices.reserve(_VERT_COUNT);
		p_shapeVertices.emplace_back(vertex1);
		p_shapeVertices.emplace_back(vertex2);
		p_shapeVertices.emplace_back(vertex3);

	}

	void Triangle::translate(float xAmount, float yAmount, float zAmount){
		this->p_shapeVertices.at(0).x += xAmount; this->p_shapeVertices.at(0).y += yAmount; this->p_shapeVertices.at(0).z += zAmount;
		this->p_shapeVertices.at(1).x += xAmount; this->p_shapeVertices.at(1).y += yAmount; this->p_shapeVertices.at(1).z += zAmount;
		this->p_shapeVertices.at(2).x += xAmount; this->p_shapeVertices.at(2).y += yAmount; this->p_shapeVertices.at(2).z += zAmount;
	}

	void Triangle::translateX(float amount){
		this->p_shapeVertices.at(0).x += amount; this->p_shapeVertices.at(1).x += amount; this->p_shapeVertices.at(2).x += amount;
	}
	void Triangle::translateY(float amount){
		this->p_shapeVertices.at(0).y += amount; this->p_shapeVertices.at(1).y += amount; this->p_shapeVertices.at(2).y += amount;
	}
	void Triangle::translateZ(float amount){
		this->p_shapeVertices.at(0).z += amount; this->p_shapeVertices.at(1).z += amount; this->p_shapeVertices.at(2).z += amount;
	}


	void Triangle::setVertices(const std::vector<glm::vec3>& vertices){
		if(vertices.size() != 4){
			exit(-4);
		}
		p_shapeVertices[0].x = vertices[0].x; p_shapeVertices[0].y = vertices[0].y; p_shapeVertices[0].z = vertices[0].z;
		p_shapeVertices[1].x = vertices[1].x; p_shapeVertices[1].y = vertices[1].y; p_shapeVertices[1].z = vertices[1].z;
		p_shapeVertices[2].x = vertices[2].x; p_shapeVertices[2].y = vertices[2].y; p_shapeVertices[2].z = vertices[2].z;
	}

	void Triangle::setVertices(glm::vec3 vertex1, glm::vec3 vertex2, glm::vec3 vertex3){
		p_shapeVertices[0].x = vertex1.x, p_shapeVertices[0].y = vertex1.y; p_shapeVertices[0].z = vertex1.z;
		p_shapeVertices[1].x = vertex2.x, p_shapeVertices[1].y = vertex2.y; p_shapeVertices[1].z = vertex2.z;
		p_shapeVertices[2].x = vertex3.x, p_shapeVertices[2].y = vertex3.y; p_shapeVertices[2].z = vertex3.z;
	}


	Triangle::~Triangle(){
		std::cout << "triangle destoryed yeet" << std::endl;
	}

}
