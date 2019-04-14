#pragma once
#include <vector>
#include <glm/vec3.hpp>
namespace noe{
	class Shape{
	public:
		virtual void setVertices(std::vector<glm::vec3> vertices) = 0;
	protected:
		std::vector<glm::vec3> shapeVertices;
	};

}