#pragma once

#include "Shape.h"



namespace noe{

	class Rectangle: public Shape{
	public:
		Rectangle();
		Rectangle(const glm::vec3& bottomLeftPos, float width, float height);

		void setPosition(const glm::vec3& bottomLeftPos);
		void setDimensions(float width, float height);








		~Rectangle(){}


	private:
		const char _VERT_COUNT = 6;
		float _width, _height;
		glm::vec3 _bottomLeftPosition;


	public:
		//overrides


		void translate(float xAmount, float yAmount, float zAmount);
		void setVertices(const std::vector<glm::vec3>& vertices);
		void translateX(float amount);
		void translateY(float amount);
		void translateZ(float amount);

	};

}
