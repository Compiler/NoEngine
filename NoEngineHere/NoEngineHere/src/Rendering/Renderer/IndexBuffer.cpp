#include "IndexBuffer.h"

namespace noe{

	IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count){
		glGenBuffers(1, &_bufferID);
		glBindBuffer(GL_ARRAY_BUFFER, _bufferID);
		glBufferData(GL_ARRAY_BUFFER, count, data, hint);

	}



	void IndexBuffer::bind(){
		glBindBuffer(GL_ARRAY_BUFFER, _bufferID);
	}



	void IndexBuffer::unbind(){
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}


	IndexBuffer::~IndexBuffer(){
	}
}