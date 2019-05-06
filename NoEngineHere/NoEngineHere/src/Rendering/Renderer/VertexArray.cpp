#include "VertexArray.h"
#include "VertexArray.h"
#include <iostream>

namespace noe{

	VertexArray::VertexArray(){
		glGenVertexArrays(1, &_vertexArrayID);
		glBindVertexArray(_vertexArrayID);
	}

	void VertexArray::addBuffer(VertexBuffer& buffer, const VertexBufferLayout& dataLayout){
		if(_bufferCache.find(buffer.getBufferID()) == _bufferCache.end())
			_bufferCache[buffer.getBufferID()] = 1;
		
		const std::vector<VertexBufferElement>& elements = dataLayout.getElements();

		unsigned int offset = 0;

		if(_bufferCache.size() == 2){
			glBindVertexArray(_vertexArrayID);
			glBindBuffer(GL_ARRAY_BUFFER, 1);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);//f f f  c c c  c c c  c c c
			glEnableVertexAttribArray(0);

			glBindBuffer(GL_ARRAY_BUFFER, 2);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);//f f f  c c c  c c c  c c c
			glEnableVertexAttribArray(1);
		}
		
	//	for(unsigned int i = 0; i < elements.size(); i++){
			//const VertexBufferElement& element = elements[i];
			//glEnableVertexAttribArray(i);
			//glVertexAttribPointer(i, element.count, element.type, element.normalized, 0, (const void*)offset);//f f f  c c c  c c c  c c c
			//offset += element.count * VertexBufferElement::sizeOfType(element.type);
		//}

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