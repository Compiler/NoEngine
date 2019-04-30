#pragma once
#include <GL/glew.h>
#include <iostream>
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

		unsigned int getBufferID() const{ return _bufferID;  }
		unsigned int getBufferSize() const{ return _bufferSize; }

		VertexBuffer& operator=(const VertexBuffer& copy) = delete;
		
		
		/*{
			this->_bufferID = copy._bufferID;
			this->_bufferSize = copy._bufferSize;
			std::cout << "buffer copied" << std::endl;
		}*/

	};

}