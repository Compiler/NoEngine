#include "VertexArray.h"
#include "VertexArray.h"
#include <iostream>

namespace noe{

	VertexArray::VertexArray(){
		glGenVertexArrays(1, &_vertexArrayID);
		glBindVertexArray(_vertexArrayID);
	}

	void VertexArray::addBuffer(const VertexBuffer& buffer, const VertexBufferLayout& dataLayout){
		static int __cunt__ = 0;
		std::cout << __cunt__;
		
		//buffer.bind();
		_buffers[__cunt__] = buffer;
		
		const std::vector<VertexBufferElement>& elements = dataLayout.getElements();
		if(__cunt__ == elements.size()) __cunt__ = -1; else __cunt__++;

		unsigned int offset = 0;

		if(__cunt__ == -1){
			_buffers[0].bind();
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);//f f f  c c c  c c c  c c c
			_buffers[1].bind();
			glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);//f f f  c c c  c c c  c c c
		}

		for(unsigned int i = 0; i < elements.size(); i++){
			//_buffers[i].bind();
			//_buffers[1].bind();
			const VertexBufferElement& element = elements[i];
			glEnableVertexAttribArray(i);
			std::cout << "glVertexAttribPointer(" << i << ", " << element.count << ", " << element.normalized << ", " << dataLayout.getStride() << ", " << offset << std::endl;
			//glVertexAttribPointer(i, element.count, element.type, element.normalized, 0, (const void*)offset);//f f f  c c c  c c c  c c c
			//glVertexAttribPointer(i, element.count, element.type, element.normalized, 0, (const void*)offset);//f f f  c c c  c c c  c c c
			//offset += element.count * VertexBufferElement::sizeOfType(element.type);
		}

	}



	void VertexArray::bind() const{
		glBindVertexArray(_vertexArrayID);
	}
	void VertexArray::unbind() const{
		glBindVertexArray(0);
	}

	VertexArray::~VertexArray(){
		glDeleteVertexArrays(1, &_vertexArrayID);
	}

}