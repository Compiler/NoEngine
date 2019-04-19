#pragma once

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

namespace noe{

	class VertexArray{


	private:
		unsigned int _vertexArrayID;
	public:
		VertexArray();

		void addBuffer(const VertexBuffer& buffer, const VertexBufferLayout& dataLayout);
		void bind() const;
		void unbind() const;

		~VertexArray();
	};

}