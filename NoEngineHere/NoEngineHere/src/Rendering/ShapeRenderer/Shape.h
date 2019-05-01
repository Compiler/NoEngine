#pragma once
#include <vector>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include "Color.h"


namespace noe{
	class Shape{
	public:

		//Shape(){}

		virtual void translate(float xAmount, float yAmount, float zAmount) = 0;
		virtual void setVertices(const std::vector<glm::vec3>& vertices) = 0;
		virtual void translateX(float amount) = 0;
		virtual void translateY(float amount) = 0;
		virtual void translateZ(float amount) = 0;


		float getX(){
			if(shapeVertices.empty() != true)
				return shapeVertices.at(0).x;
		}

		std::vector<glm::vec3> getVertices() {
			return shapeVertices;
		}

		Color getColor() const{ return this->shapeColor; }
		glm::vec4 getColorVec() const{ return glm::vec4(this->shapeColor.r, this->shapeColor.g, this->shapeColor.b, this->shapeColor.a); }

		void setColor(const Color& newColor){ this->shapeColor = newColor; }
		void setColor(float r, float g, float b, float a = 1){ 
			this->shapeColor.r = r; this->shapeColor.g = g; this->shapeColor.b = b; this->shapeColor.a = a;
		}

	protected:
		std::vector<glm::vec3> shapeVertices;
		Color shapeColor;
	};

}