#pragma once

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "../Shaders/Shader.h"

namespace noe{
	class Renderer{
	public:
		Renderer();

		void clear(float r = 0.3f, float g = 0.3f, float b = 0.3f, float a = 1.0f) const;
		void draw(const VertexArray& vertexArray, const IndexBuffer& indexBuffer, const Shader& shader) const;
		void drawTriangles(const VertexArray& vertexArray, unsigned int count, const Shader& shader) const;


		~Renderer();
	};

}