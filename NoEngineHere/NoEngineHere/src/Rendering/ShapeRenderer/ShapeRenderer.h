#pragma once

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../Renderer/VertexArray.h"
#include "../Renderer/IndexBuffer.h"
#include "../Renderer/VertexBuffer.h"
#include "../Renderer/Renderer.h"
#include "../Shaders/Shader.h"
#include <string>
#include "Triangle.h"
#include "Rectangle.h"
#include <vector>

namespace noe{


	class ShapeRenderer{

	private:

		

		VertexArray _shapeVertexArray;
		VertexBuffer _shapeVerticesBuffer, _shapeColorBuffer;
		VertexBufferLayout _shapeLayout;
		Shader _shapeShader;

		Renderer _renderer;

		std::vector<float> _trianglePositions;
		std::vector<float> _triangleColors;
		std::vector<float> _packedData;



	public:

		ShapeRenderer();

		void begin();

		void drawTriangle(const glm::vec3& firstVertex, const glm::vec3& secondVertex, const glm::vec3& thirdVertex, const glm::vec3& color);
		void drawTriangle(const glm::vec3& firstVertex, const glm::vec3& secondVertex, const glm::vec3& thirdVertex, const glm::vec4& color);
		void drawTriangle(Triangle& triangle);


		void drawRect(Rectangle& rectangle);
		void drawRect(const glm::vec3& bottomLeftPos, float width, float height);

		void end();

		void doSomeFuckingShit();

		void clear(float r = 0.3f, float g = 0.3f, float b = 0.3f, float a = 1.0f) const;


		void setMatrices(glm::mat4 model, glm::mat4 view, glm::mat4 projection);

	};


}