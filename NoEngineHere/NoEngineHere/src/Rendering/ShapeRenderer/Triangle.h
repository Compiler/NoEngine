#pragma once

#include <glm/vec3.hpp>
#include "Shape.h"
namespace noe{

	class Triangle : Shape{
	public:
		Triangle();
		Triangle(glm::vec3 vertex1, glm::vec3 vertex2, glm::vec3 vertex3);

		void setVertices(std::vector<glm::vec3> vertices);




		~Triangle();


	private:
		const char VERT_COUNT = 3;

	};

}

