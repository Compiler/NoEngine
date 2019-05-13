#include "Texture.h"



namespace noe{
	Texture::Texture(const std::string& filePath): _id(0), _filePath(filePath), _localBuffer(nullptr), _width(0), _height(0), _bpp(0){
	
	
	}
	void Texture::bind(unsigned int slot = 0) const{
	
	}
	void Texture::unbind() const{
	
	
	}

}
