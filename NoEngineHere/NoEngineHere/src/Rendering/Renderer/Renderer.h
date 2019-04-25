#pragma once

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "../Shaders/Shader.h"

namespace noe{
	class Renderer{
	public:
		Renderer();

		void clear() const;
		void draw(const VertexArray& vertexArray, const IndexBuffer& indexBuffer, const Shader& shader) const;


		~Renderer();
	};

}