#pragma once

#include <glm/vec3.hpp>


namespace noe{


	class ShapeBatch{

	public:

		void addTriangle(const glm::vec3& firstVertex, const glm::vec3& secondVertex, const glm::vec3& thirdVertex);
		void addRectangle(const glm::vec3& firstVertex, const glm::vec3& secondVertex, const glm::vec3& thirdVertex, const glm::vec3& fourthVertex);





	};


}