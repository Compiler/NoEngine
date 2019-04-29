#pragma once
#include <GL/glew.h>



namespace noe{
	class VertexBuffer{

	private:
		unsigned int _bufferID;
		unsigned int _bufferSize;

	public:
		VertexBuffer(const void* data, unsigned int dataSize, unsigned int hint = GL_STATIC_DRAW);
		VertexBuffer();

		void init(const void* data, unsigned int dataSize, unsigned int hint = GL_STATIC_DRAW);



		~VertexBuffer();

		void bind() const ;
		void unbind() const ;

		unsigned int getBufferSize() const{ return _bufferSize; }


	};

}