#include "VertexBuffer.h"

namespace noe{

	VertexBuffer::VertexBuffer(const void* data, unsigned int dataSize, unsigned int hint){
		glGenBuffers(1, &_bufferID);
		glBindBuffer(GL_ARRAY_BUFFER, _bufferID);
		glBufferData(GL_ARRAY_BUFFER, dataSize, data, hint);

	}



	void VertexBuffer::bind(){
		glBindBuffer(GL_ARRAY_BUFFER, _bufferID);
	}



	void VertexBuffer::unbind(){
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}


	VertexBuffer::~VertexBuffer(){
	}
}