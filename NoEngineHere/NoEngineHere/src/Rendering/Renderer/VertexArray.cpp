#include "VertexArray.h"
#include "VertexArray.h"
#include <iostream>

namespace noe{

	VertexArray::VertexArray(){
		glGenVertexArrays(1, &_vertexArrayID);
		glBindVertexArray(_vertexArrayID);
	}

	void VertexArray::addBuffer(const VertexBuffer& buffer, const VertexBufferLayout& dataLayout){
		buffer.bind();

		const std::vector<VertexBufferElement>& elements = dataLayout.getElements();
		unsigned int offset = 0;

		for(unsigned int i = 0; i < elements.size(); i++){
			const VertexBufferElement& element = elements[i];
			glEnableVertexAttribArray(i);
			std::cout << "glVertexAttribPointer(" << i << ", " << element.count << ", " << element.normalized << ", " << dataLayout.getStride() << ", " << offset << std::endl;
			glVertexAttribPointer(i, element.count, element.type, element.normalized, dataLayout.getStride(), (const void*) offset);//f f f  c c c  c c c  c c c
			offset += element.count * VertexBufferElement::sizeOfType(element.type);
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