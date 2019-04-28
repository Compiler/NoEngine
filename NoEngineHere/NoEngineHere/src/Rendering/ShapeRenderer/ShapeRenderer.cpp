#include "ShapeRenderer.h"

namespace noe{

	ShapeRenderer::ShapeRenderer(){
		_shapeShader.init((std::string&)"../Shaders/glsl/shapeRenderer_passthrough_v.glsl", (std::string&)"../Shaders/glsl/shapeRenderer_passthrough_f.glsl");
	}

	void ShapeRenderer::drawTriangle(const glm::vec3& firstVertex, const glm::vec3& secondVertex, const glm::vec3& thirdVertex, const glm::vec3& color){
	
	}

}