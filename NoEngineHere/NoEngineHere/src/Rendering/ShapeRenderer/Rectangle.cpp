#include "Rectangle.h"


namespace noe{


	Rectangle::Rectangle(){
		this->p_shapeVertices.reserve(_VERT_COUNT); //6 vertices in rectangle (pending index buffer)
		p_shapeVertices.emplace_back(glm::vec3()); p_shapeVertices.emplace_back(glm::vec3());
		p_shapeVertices.emplace_back(glm::vec3()); p_shapeVertices.emplace_back(glm::vec3());
		p_shapeVertices.emplace_back(glm::vec3()); p_shapeVertices.emplace_back(glm::vec3());

	}



	Rectangle::Rectangle(const glm::vec3& bottomLeftPos, float width, float height): _width(width), _height(height), _bottomLeftPosition(bottomLeftPos){
		this->p_shapeVertices.reserve(_VERT_COUNT);
		this->p_shapeVertices.emplace_back(this->_bottomLeftPosition);
		this->p_shapeVertices.emplace_back(glm::vec3(this->_bottomLeftPosition.x + this->_width, this->_bottomLeftPosition.y, this->_bottomLeftPosition.z));
		this->p_shapeVertices.emplace_back(glm::vec3(this->_bottomLeftPosition.x , this->_bottomLeftPosition.y + this->_height, this->_bottomLeftPosition.z));
		this->p_shapeVertices.emplace_back(glm::vec3(this->_bottomLeftPosition.x + this->_width, this->_bottomLeftPosition.y + this->_height, this->_bottomLeftPosition.z));
		this->p_shapeVertices.emplace_back(glm::vec3(this->_bottomLeftPosition.x + this->_width, this->_bottomLeftPosition.y, this->_bottomLeftPosition.z));
		this->p_shapeVertices.emplace_back(glm::vec3(this->_bottomLeftPosition.x, this->_bottomLeftPosition.y + this->_height, this->_bottomLeftPosition.z));
	}


	void Rectangle::setPosition(const glm::vec3& bottomLeftPos){
		glm::vec3 difference = bottomLeftPos - this->_bottomLeftPosition;
		this->_bottomLeftPosition = bottomLeftPos;
		this->translate(difference.x, difference.y, difference.z);
	}


	void Rectangle::setDimensions(float width, float height){
		this->_width = width; this->_height = height;
	}



	void Rectangle::setVertices(const std::vector<glm::vec3>& vertices){
		if(vertices.size() != 6){
			exit(-4);
		}
		p_shapeVertices[0].x = vertices[0].x; p_shapeVertices[0].y = vertices[0].y; p_shapeVertices[0].z = vertices[0].z;
		p_shapeVertices[1].x = vertices[1].x; p_shapeVertices[1].y = vertices[1].y; p_shapeVertices[1].z = vertices[1].z;
		p_shapeVertices[2].x = vertices[2].x; p_shapeVertices[2].y = vertices[2].y; p_shapeVertices[2].z = vertices[2].z;
		p_shapeVertices[3].x = vertices[3].x; p_shapeVertices[3].y = vertices[3].y; p_shapeVertices[3].z = vertices[3].z;
		p_shapeVertices[4].x = vertices[4].x; p_shapeVertices[4].y = vertices[4].y; p_shapeVertices[4].z = vertices[4].z;
		p_shapeVertices[5].x = vertices[5].x; p_shapeVertices[5].y = vertices[5].y; p_shapeVertices[5].z = vertices[5].z;
	}



	void Rectangle::translate(float xAmount, float yAmount, float zAmount){
		this->p_shapeVertices.at(0).x += xAmount; this->p_shapeVertices.at(0).y += yAmount; this->p_shapeVertices.at(0).z += zAmount;
		this->p_shapeVertices.at(1).x += xAmount; this->p_shapeVertices.at(1).y += yAmount; this->p_shapeVertices.at(1).z += zAmount;
		this->p_shapeVertices.at(2).x += xAmount; this->p_shapeVertices.at(2).y += yAmount; this->p_shapeVertices.at(2).z += zAmount;
		this->p_shapeVertices.at(3).x += xAmount; this->p_shapeVertices.at(3).y += yAmount; this->p_shapeVertices.at(3).z += zAmount;
		this->p_shapeVertices.at(4).x += xAmount; this->p_shapeVertices.at(4).y += yAmount; this->p_shapeVertices.at(4).z += zAmount;
		this->p_shapeVertices.at(5).x += xAmount; this->p_shapeVertices.at(5).y += yAmount; this->p_shapeVertices.at(5).z += zAmount;
	}

	void Rectangle::translateX(float amount){
		this->p_shapeVertices.at(0).x += amount; this->p_shapeVertices.at(1).x += amount; this->p_shapeVertices.at(2).x += amount;
		this->p_shapeVertices.at(3).x += amount; this->p_shapeVertices.at(4).x += amount; this->p_shapeVertices.at(5).x += amount;
	}
	void Rectangle::translateY(float amount){
		this->p_shapeVertices.at(0).y += amount; this->p_shapeVertices.at(1).y += amount; this->p_shapeVertices.at(2).y += amount;
		this->p_shapeVertices.at(3).y += amount; this->p_shapeVertices.at(4).y += amount; this->p_shapeVertices.at(5).y += amount;
	}
	void Rectangle::translateZ(float amount){
		this->p_shapeVertices.at(0).z += amount; this->p_shapeVertices.at(1).z += amount; this->p_shapeVertices.at(2).z += amount;
		this->p_shapeVertices.at(3).z += amount; this->p_shapeVertices.at(4).z += amount; this->p_shapeVertices.at(5).z += amount;



	}

}