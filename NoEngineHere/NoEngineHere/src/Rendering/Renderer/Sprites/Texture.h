#pragma once

#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace noe{
	class Texture{

	private:
		unsigned int _id;
		std::string _filePath;
		unsigned char* _localBuffer;
		int _width, _height, _bpp;


	public:
		Texture(const std::string& filePath);
		void bind(unsigned int slot = 0) const;
		void unbind() const;



		inline int getWidth() const{ return _width; }
		inline int getHeight() const{ return _height; }


		~Texture();
	};


}