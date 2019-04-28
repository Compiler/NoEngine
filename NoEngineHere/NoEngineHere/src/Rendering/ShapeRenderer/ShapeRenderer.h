#pragma once

#include <glm/vec3.hpp>
#include "../Renderer/VertexArray.h"
#include "../Renderer/IndexBuffer.h"
#include "../Renderer/VertexBuffer.h"
#include "../Renderer/Renderer.h"
#include "../Shaders/Shader.h"
#include <string>
#include <vector>

namespace noe{


	struct TriangleData{
		glm::vec3 v1, v2, v3;
		glm::vec3 color;
		float alpha;
	
	
	};


	class ShapeRenderer{

	private:

		VertexArray _shapeVertexArray;
		VertexBuffer _shapeVerticesBuffer, _shapeColorBuffer;
		VertexBufferLayout _shapeLayout;
		Shader _shapeShader;


		std::vector<TriangleData> _triangleData;



	public:

		ShapeRenderer();

		void begin();

		void drawTriangle(const glm::vec3& firstVertex, const glm::vec3& secondVertex, const glm::vec3& thirdVertex, const glm::vec3& color);

		void end();


	};


}