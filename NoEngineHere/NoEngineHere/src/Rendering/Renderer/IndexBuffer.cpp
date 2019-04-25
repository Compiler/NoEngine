#include "IndexBuffer.h"

namespace noe{

	IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count, unsigned int hint): _indexCount(count){

		glGenBuffers(1, &_bufferID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _bufferID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, hint);

	}



	void IndexBuffer::bind() const {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _bufferID);
	}



	void IndexBuffer::unbind() const {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}


	IndexBuffer::~IndexBuffer(){
		glDeleteBuffers(1, &_bufferID);
	}
}