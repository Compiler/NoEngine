#pragma once

#include <vector>
#include <GL/glew.h>

namespace noe{

	struct VertexBufferElement{
		unsigned int type;
		unsigned int count;
		unsigned int normalized;

		static unsigned int sizeOfType(unsigned int type){
			//supported types--tobe updated
			switch(type){
				case GL_FLOAT:			return 4;
				case GL_UNSIGNED_INT:	return 4;
			}
			
		
		}

	};

	class VertexBufferLayout{

	private:
		std::vector<VertexBufferElement> _elements;
		unsigned int _stride;

	public:
		VertexBufferLayout(): _stride(0){}

		template<typename T>
		void push(unsigned int count){
			static_assert(false);
		}

		template<>
		void push<float>(unsigned int count){
			_elements.push_back({GL_FLOAT, count, GL_FALSE});
			_stride += VertexBufferElement::sizeOfType(GL_FLOAT) * count;
		}


		template<>
		void push<unsigned int>(unsigned int count){
			_elements.push_back({GL_UNSIGNED_INT, count, GL_FALSE});
			_stride += VertexBufferElement::sizeOfType(GL_UNSIGNED_INT) * count;

		}
		inline unsigned int getStride() const { return _stride; }
		inline const std::vector<VertexBufferElement> getElements() const { return _elements; }

		~VertexBufferLayout(){
		}
	};

}