#pragma once

#include "Texture.h"
#include <glm/vec3.hpp>
#include <string>

namespace noe{

	class Sprite{

	private:
		Texture _texture;
		glm::vec3 _position; /*Bottom Left*/
		float _width, _height; /*width - height */


	};


}