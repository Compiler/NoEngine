#pragma once

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

#include <unordered_map>

namespace noe{

	class VertexArray{


	private:

		std::unordered_map<unsigned short, unsigned char> _bufferCache;
		
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