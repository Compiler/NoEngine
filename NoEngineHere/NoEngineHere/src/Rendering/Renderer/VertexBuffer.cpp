#include "VertexBuffer.h"

namespace noe{

	VertexBuffer::VertexBuffer(const void* data, unsigned int dataSize, unsigned int hint): _bufferSize(dataSize)
	{

	
		glGenBuffers(1, &_bufferID);
		glBindBuffer(GL_ARRAY_BUFFER, _bufferID);
		glBufferData(GL_ARRAY_BUFFER, dataSize, data, hint);
		

	}


	VertexBuffer::VertexBuffer(){
		glGenBuffers(1, &_bufferID);
		glBindBuffer(GL_ARRAY_BUFFER, _bufferID);
	}

	void VertexBuffer::init(const void* data, unsigned int dataSize, unsigned int hint){
		glBufferData(GL_ARRAY_BUFFER, dataSize, data, hint);
		_bufferSize = dataSize;
	}



	void VertexBuffer::bind() const{
		std::cout << "binding: " << _bufferID << std::endl;
		glBindBuffer(GL_ARRAY_BUFFER, _bufferID);
	}



	void VertexBuffer::unbind() const{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}


	VertexBuffer::~VertexBuffer(){
		glDeleteBuffers(1, &_bufferID);
	}
}