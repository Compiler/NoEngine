#pragma once
#include "Camera.h"


namespace noe{
	class PerspectiveCamera: Camera{

	public:
		PerspectiveCamera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f));
		~PerspectiveCamera();



	private:

		float _yaw, _pitch;
	};
}

