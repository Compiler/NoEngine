#pragma once
#include <GL/glew.h>



namespace noe{
	class IndexBuffer{

	private:
		unsigned int _bufferID;
		unsigned int _indexCount;


	public:
		//data and element count
		IndexBuffer(const unsigned int* data, unsigned int count);
		~IndexBuffer();

		void bind();
		void unbind();


	};

}