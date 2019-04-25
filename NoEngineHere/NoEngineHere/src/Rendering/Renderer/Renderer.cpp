#include "Renderer.h"

namespace noe{

	Renderer::Renderer(){
	}


	void Renderer::draw(const VertexArray& vertexArray, const IndexBuffer& indexBuffer, const Shader& shader) const{

		shader.bind();
		vertexArray.bind();
		indexBuffer.bind();

		glDrawElements(GL_TRIANGLES, indexBuffer.getCount() , GL_UNSIGNED_INT, 0);
	
	}

	void Renderer::clear() const{
		glClearColor(.1f, .1f, .1f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}


	Renderer::~Renderer(){
	}
}