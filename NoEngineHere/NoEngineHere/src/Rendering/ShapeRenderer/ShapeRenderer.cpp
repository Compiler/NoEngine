#include "ShapeRenderer.h"

namespace noe{

	ShapeRenderer::ShapeRenderer(){
		std::string vs = "../NoEngineHere/src/Rendering/Shaders/glsl/shapeRenderer_passthrough_v.glsl";
		std::string fs = "../NoEngineHere/src/Rendering/Shaders/glsl/shapeRenderer_passthrough_f.glsl";

		_shapeShader.init(vs, fs);

		_shapeLayout.push<float>(3);
		_shapeLayout.push<float>(4);
	}


	void ShapeRenderer::begin(){


		_shapeShader.bind();

		_trianglePositions.clear();
		_triangleColors.clear();
		_packedData.clear();
	}

	void ShapeRenderer::drawTriangle(const glm::vec3& firstVertex, const glm::vec3& secondVertex, const glm::vec3& thirdVertex, const glm::vec3& color){
		//_trianglePositions.emplace_back(firstVertex, secondVertex, thirdVertex);
		//_triangleColors.emplace_back(color.x, color.y, color.z, 1.0f);
	}


	void ShapeRenderer::drawTriangle(Triangle& triangle){
		std::vector<glm::vec3> vertices = triangle.getVertices();
		Color color = triangle.getColor();
		_trianglePositions.emplace_back(vertices.at(0).x); _trianglePositions.emplace_back(vertices.at(0).y); _trianglePositions.emplace_back(vertices.at(0).z);
		_trianglePositions.emplace_back(vertices.at(1).x); _trianglePositions.emplace_back(vertices.at(1).y); _trianglePositions.emplace_back(vertices.at(1).z);
		_trianglePositions.emplace_back(vertices.at(2).x); _trianglePositions.emplace_back(vertices.at(2).y); _trianglePositions.emplace_back(vertices.at(2).z);
		_triangleColors.emplace_back(color.r); _triangleColors.emplace_back(color.g); _triangleColors.emplace_back(color.b); _triangleColors.emplace_back(color.a);
		_triangleColors.emplace_back(color.r); _triangleColors.emplace_back(color.g); _triangleColors.emplace_back(color.b); _triangleColors.emplace_back(color.a);
		_triangleColors.emplace_back(color.r); _triangleColors.emplace_back(color.g); _triangleColors.emplace_back(color.b); _triangleColors.emplace_back(color.a);
	}
	void ShapeRenderer::drawTriangle(const glm::vec3& firstVertex, const glm::vec3& secondVertex, const glm::vec3& thirdVertex, const glm::vec4& color){
		_trianglePositions.emplace_back(firstVertex.x); _trianglePositions.emplace_back(firstVertex.y); _trianglePositions.emplace_back(firstVertex.z);
		_trianglePositions.emplace_back(secondVertex.x); _trianglePositions.emplace_back(secondVertex.y); _trianglePositions.emplace_back(secondVertex.z);
		_trianglePositions.emplace_back(thirdVertex.x); _trianglePositions.emplace_back(thirdVertex.y); _trianglePositions.emplace_back(thirdVertex.z);
		_triangleColors.emplace_back(color.x); _triangleColors.emplace_back(color.y); _triangleColors.emplace_back(color.z); _triangleColors.emplace_back(color.w);
		_triangleColors.emplace_back(color.x); _triangleColors.emplace_back(color.y); _triangleColors.emplace_back(color.z); _triangleColors.emplace_back(color.w);
		_triangleColors.emplace_back(color.x); _triangleColors.emplace_back(color.y); _triangleColors.emplace_back(color.z); _triangleColors.emplace_back(color.w);
	}

	void ShapeRenderer::end(){
		_shapeVerticesBuffer.init(reinterpret_cast<void*>(_trianglePositions.data()), _trianglePositions.size() * 4, GL_DYNAMIC_DRAW);
		_shapeColorBuffer.init(reinterpret_cast<void*>(_triangleColors.data()), _triangleColors.size() * 4, GL_DYNAMIC_DRAW);

		_shapeVertexArray.addBuffer(_shapeVerticesBuffer, _shapeLayout);
		_shapeVertexArray.addBuffer(_shapeColorBuffer, _shapeLayout);


		_renderer.drawTriangles(_shapeVertexArray, (unsigned int)_trianglePositions.size(), _shapeShader);

	}


	void ShapeRenderer::drawRect(Rectangle& rectangle){
		std::vector<glm::vec3> vertices = rectangle.getVertices();
		Color color = rectangle.getColor();
		_trianglePositions.emplace_back(vertices.at(0).x); _trianglePositions.emplace_back(vertices.at(0).y); _trianglePositions.emplace_back(vertices.at(0).z);
		_trianglePositions.emplace_back(vertices.at(1).x); _trianglePositions.emplace_back(vertices.at(1).y); _trianglePositions.emplace_back(vertices.at(1).z);
		_trianglePositions.emplace_back(vertices.at(2).x); _trianglePositions.emplace_back(vertices.at(2).y); _trianglePositions.emplace_back(vertices.at(2).z);
		_triangleColors.emplace_back(color.r); _triangleColors.emplace_back(color.g); _triangleColors.emplace_back(color.b); _triangleColors.emplace_back(color.a);
		_triangleColors.emplace_back(color.r); _triangleColors.emplace_back(color.g); _triangleColors.emplace_back(color.b); _triangleColors.emplace_back(color.a);
		_triangleColors.emplace_back(color.r); _triangleColors.emplace_back(color.g); _triangleColors.emplace_back(color.b); _triangleColors.emplace_back(color.a);
		_trianglePositions.emplace_back(vertices.at(3).x); _trianglePositions.emplace_back(vertices.at(3).y); _trianglePositions.emplace_back(vertices.at(3).z);
		_trianglePositions.emplace_back(vertices.at(4).x); _trianglePositions.emplace_back(vertices.at(4).y); _trianglePositions.emplace_back(vertices.at(4).z);
		_trianglePositions.emplace_back(vertices.at(5).x); _trianglePositions.emplace_back(vertices.at(5).y); _trianglePositions.emplace_back(vertices.at(5).z);
		_triangleColors.emplace_back(color.r); _triangleColors.emplace_back(color.g); _triangleColors.emplace_back(color.b); _triangleColors.emplace_back(color.a);
		_triangleColors.emplace_back(color.r); _triangleColors.emplace_back(color.g); _triangleColors.emplace_back(color.b); _triangleColors.emplace_back(color.a);
		_triangleColors.emplace_back(color.r); _triangleColors.emplace_back(color.g); _triangleColors.emplace_back(color.b); _triangleColors.emplace_back(color.a);
	}

	void ShapeRenderer::drawRect(const glm::vec3& bottomLeftPos, float width, float height){
		Rectangle drawn(bottomLeftPos, width, height);
		drawRect(drawn);
	}


	void ShapeRenderer::clear(float r, float g, float b, float a) const {
		_renderer.clear(r, g, b, a);
	}




	void ShapeRenderer::doSomeFuckingShit(){

		float vertices[] = {
			-1, 0, 0,
			 1, 0, 0,
			 0, 1, 1,
		};

		float colors[] = {
			 1, 0, 0, 1,
			 1, 0, 0, 1,
			 1, 0, 0, 1,
		};
	
		GLuint vao;

		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);

		GLuint vb, cb;

		/*glGenBuffers(1, &vb);
		glBindBuffer(GL_ARRAY_BUFFER, vb);
		glBufferData(GL_ARRAY_BUFFER, 4 * 3 * sizeof(float), vertices, GL_STATIC_DRAW);*/

		_shapeVerticesBuffer.init(vertices, 3 * 3 * sizeof(float), GL_STATIC_DRAW);
		_shapeVerticesBuffer.bind();
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
		glEnableVertexAttribArray(0);
	
		/*glGenBuffers(1, &cb);
		glBindBuffer(GL_ARRAY_BUFFER, cb);
		glBufferData(GL_ARRAY_BUFFER, 4 * 4 * sizeof(float), colors, GL_STATIC_DRAW);*/
		_shapeColorBuffer.init(colors, 3 * 4 * sizeof(float), GL_STATIC_DRAW);
		_shapeColorBuffer.bind();

		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);
		glEnableVertexAttribArray(1);


		glDrawArrays(GL_TRIANGLES, 0, 3);

	}





	void ShapeRenderer::setMatrices(glm::mat4 model, glm::mat4 view, glm::mat4 projection){
		_shapeShader.setUniformMatrix4fv("model", false, glm::value_ptr(model));
		_shapeShader.setUniformMatrix4fv("view", false, glm::value_ptr(view));
		_shapeShader.setUniformMatrix4fv("projection", false, glm::value_ptr(projection));
	
	}

}