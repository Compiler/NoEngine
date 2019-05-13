#include "Texture.h"

#include "../../../externs/stb/stb_image.h"


namespace noe{
	Texture::Texture(const std::string& filePath): _id(0), _filePath(filePath), _localBuffer(nullptr), _width(0), _height(0), _bpp(0){
	


		stbi_set_flip_vertically_on_load(1);

		_localBuffer = stbi_load(filePath.c_str(), &_width, &_height, &_bpp, 4);


		glGenTextures(1, &_id);
		glBindTexture(GL_TEXTURE_2D, _id);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, _localBuffer);
		glBindTexture(GL_TEXTURE_2D, 0);

		if(_localBuffer)
			stbi_image_free(_localBuffer);
	
	}
	void Texture::bind(unsigned int slot = 0) const{
		glActiveTexture(GL_TEXTURE0 + slot);
		glBindTexture(GL_TEXTURE_2D, _id);
	}
	void Texture::unbind() const{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

}
