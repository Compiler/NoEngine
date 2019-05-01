#pragma once

#include <glm/vec3.hpp>
#include "Shape.h"
namespace noe{

	class Triangle : public Shape{
	public:
		Triangle();
		Triangle(glm::vec3 vertex1, glm::vec3 vertex2, glm::vec3 vertex3);

		//void setVertices(std::vector<glm::vec3> vertices);
		void setVertices(glm::vec3 vertex1, glm::vec3 vertex2, glm::vec3 vertex3);


		
		
		


		~Triangle();


	private:
		const char _VERT_COUNT = 3;



	public:
		//overrides


		void translate(float xAmount, float yAmount, float zAmount);
		void setVertices(const std::vector<glm::vec3>& vertices);
		void translateX(float amount);
		void translateY(float amount);
		void translateZ(float amount);

	};

}

