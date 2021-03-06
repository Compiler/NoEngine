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

	void Renderer::drawTriangles(const VertexArray& vertexArray, unsigned int count, const Shader& shader) const{

		shader.bind();
		vertexArray.bind();

		glDrawArrays(GL_TRIANGLES, 0, count/3);

	}

	void Renderer::clear(float r, float g, float b, float a) const{
		glClearColor(r,g,b,a);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}


	Renderer::~Renderer(){
	}
}