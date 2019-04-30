#pragma once

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

namespace noe{

	class VertexArray{


	private:
		unsigned int _vertexArrayID;
		VertexBuffer* _buffers[2];
	public:
		VertexArray();

		void addBuffer(VertexBuffer& buffer, const VertexBufferLayout& dataLayout);
		void bind() const;
		void unbind() const;

		~VertexArray();
	};

}