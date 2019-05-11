#pragma once
#include "Scene.h"
#include <vector>

namespace noe{

	class SceneManager{
	private:
		Scene _currentScene;
		std::vector<Scene> _scenes;


	public:
		SceneManager();
		~SceneManager();
	};

}
