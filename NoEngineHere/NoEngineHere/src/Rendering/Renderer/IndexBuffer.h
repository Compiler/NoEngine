#pragma once
#include <GL/glew.h>



namespace noe{
	class IndexBuffer{

	private:
		unsigned int _bufferID;
		unsigned int _indexCount;


	public:
		//data and element count
		IndexBuffer(const unsigned int* data, unsigned int count, unsigned int hint = GL_STATIC_DRAW);
		~IndexBuffer();

		void bind() const;
		void unbind() const;

		inline unsigned int getCount() const{ return _indexCount;  }


	};

}