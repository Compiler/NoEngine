#pragma once


#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <GL/glew.h>

namespace noe{
	class Shader{


	private:
		unsigned int _shaderID;
		std::string _vertexFilePath, _fragmentFilePath;

		std::unordered_map<std::string, int> _uniformLocationCache;

	public:

		Shader(const std::string& vertexPath, const std::string& fragmentPath);
		Shader();

		void init(const std::string& vertexPath, const std::string& fragmentPath);

		void bind() const;
		void unbind() const;

		void setUniform1i(const std::string& name, int v0);
		void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
		void setUniformMatrix4fv(const std::string& name, bool transpose, const GLfloat* matrix);

		~Shader();

	private:
		int getUniformLocation(const std::string& name);
		bool compileShader();
	};

}
