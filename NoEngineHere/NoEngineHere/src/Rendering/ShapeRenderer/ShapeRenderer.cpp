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

		_trianglePositions.clear();
		_triangleColors.clear();
	}

	void ShapeRenderer::drawTriangle(const glm::vec3& firstVertex, const glm::vec3& secondVertex, const glm::vec3& thirdVertex, const glm::vec3& color){
		//_trianglePositions.emplace_back(firstVertex, secondVertex, thirdVertex);
		//_triangleColors.emplace_back(color.x, color.y, color.z, 1.0f);
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

		_shapeVerticesBuffer.init(static_cast<void*>(_trianglePositions.data()), _trianglePositions.size() * 4);
		_shapeColorBuffer.init(static_cast<void*>(_triangleColors.data()), _triangleColors.size() * 4);
		for(int i = 0; i < _trianglePositions.size(); i++) std::cout << _trianglePositions[i] << std::endl;
		_shapeVertexArray.addBuffer(_shapeVerticesBuffer, _shapeLayout);

		_shapeVertexArray.addBuffer(_shapeColorBuffer, _shapeLayout);

		_renderer.drawTriangles(_shapeVertexArray, (unsigned int)_trianglePositions.size(), _shapeShader);

	}


	void ShapeRenderer::clear() const {
		_renderer.clear();
	}





	void ShapeRenderer::setMatrices(glm::mat4 model, glm::mat4 view, glm::mat4 projection){
		_shapeShader.setUniformMatrix4fv("model", false, glm::value_ptr(model));
		_shapeShader.setUniformMatrix4fv("view", false, glm::value_ptr(view));
		_shapeShader.setUniformMatrix4fv("projection", false, glm::value_ptr(projection));
	
	}

}