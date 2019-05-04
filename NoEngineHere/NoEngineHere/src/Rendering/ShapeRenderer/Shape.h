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
			if(p_shapeVertices.empty() != true)
				return p_shapeVertices.at(0).x;
			return -4;
		}

		std::vector<glm::vec3> getVertices() {
			return p_shapeVertices;
		}

		Color getColor() const{ return this->p_shapeColor; }
		glm::vec4 getColorVec() const{ return glm::vec4(this->p_shapeColor.r, this->p_shapeColor.g, this->p_shapeColor.b, this->p_shapeColor.a); }

		void setColor(const Color& newColor){ this->p_shapeColor = newColor; }
		void setColor(float r, float g, float b, float a = 1){ 
			this->p_shapeColor.r = r; this->p_shapeColor.g = g; this->p_shapeColor.b = b; this->p_shapeColor.a = a;
		}

	protected:
		std::vector<glm::vec3> p_shapeVertices;
		Color p_shapeColor;
	};

}