#include "Shader.h"

namespace noe{


	Shader::Shader(std::string& vertexPath, std::string& fragmentPath): _shaderID(0), _vertexFilePath(vertexPath), _fragmentFilePath(fragmentPath){

		compileShader();
	}

	Shader::Shader() : _shaderID(0){

	}


	void Shader::init(std::string& vertexPath, std::string& fragmentPath){
		_vertexFilePath = vertexPath;
		_fragmentFilePath = fragmentPath;
		compileShader();
	}



	void Shader::bind()		const	{glUseProgram(_shaderID);}
	void Shader::unbind()	const	{glUseProgram(0);}


	void Shader::setUniform4f(const std::string& name, float v0, float v1, float v2, float v3){
		glUniform4f(getUniformLocation(name), v0, v1, v2, v3);
	}


	void Shader::setUniformMatrix4fv(const std::string& name, bool transpose, const GLfloat* matrix){
		glUniformMatrix4fv(getUniformLocation(name), 1, transpose, matrix);
	}


	Shader::~Shader(){
		glDeleteProgram(_shaderID);
	}




	int Shader::getUniformLocation(const std::string& name){
		if(_uniformLocationCache.find(name) != _uniformLocationCache.end())
			return _uniformLocationCache[name];
		int location = glGetUniformLocation(_shaderID, name.c_str());
		if(location == -1) std::cout << "uniform " << name << " not found" << std::endl;
		_uniformLocationCache[name] = location;
		return location;
	
	}


	bool Shader::compileShader(){

		// retrieve the vertex/fragment source code
		std::string vertexCode, fragmentCode;
		std::ifstream vertexShaderFile, fragmentShaderFile;

		// ensures ifstream objects can throw exceptions
		vertexShaderFile.exceptions(std::ifstream::badbit);
		fragmentShaderFile.exceptions(std::ifstream::badbit);

		try{
			// open files
			vertexShaderFile.open(_vertexFilePath);
			fragmentShaderFile.open(_fragmentFilePath);
			std::stringstream vertexShaderStream, fragmentShaderStream;

			// read file's buffer contents into streams
			vertexShaderStream << vertexShaderFile.rdbuf();
			fragmentShaderStream << fragmentShaderFile.rdbuf();

			// close file handlers
			vertexShaderFile.close();
			fragmentShaderFile.close();

			// convert stream into string
			vertexCode = vertexShaderStream.str();
			fragmentCode = fragmentShaderStream.str();
		} catch(std::ifstream::failure e){
			std::cout << "Error::Shader::File Not Successfully Read!" << std::endl;
			return false;
		}

		const GLchar* vertexShaderCode = vertexCode.c_str();
		const GLchar* fragmentShaderCode = fragmentCode.c_str();

		// compile shaders
		GLuint vertex, fragment;
		GLint success;
		GLchar infoLog[512];

		// vertex shader
		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &vertexShaderCode, NULL);
		glCompileShader(vertex);
		// print compile errors if any
		glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
		if(!success){
			glGetShaderInfoLog(vertex, 512, NULL, infoLog);
			std::cout << "Error::Shader::Vertex::Compilation Failed!" << std::endl << infoLog << std::endl;
			return false;
		}

		// fragment shader
		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &fragmentShaderCode, NULL);
		glCompileShader(fragment);
		// print compile errors if any
		glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
		if(!success){
			glGetShaderInfoLog(fragment, 512, NULL, infoLog);
			std::cout << "Error::Shader::Fragment::Compilation Failed!" << std::endl << infoLog << std::endl;
			return false;
		}

		// shader program
		this->_shaderID = glCreateProgram();
		glAttachShader(this->_shaderID, vertex);
		glAttachShader(this->_shaderID, fragment);
		glLinkProgram(this->_shaderID);
		// print linking errors if any
		glGetProgramiv(this->_shaderID, GL_LINK_STATUS, &success);
		if(!success){
			glGetProgramInfoLog(this->_shaderID, 512, NULL, infoLog);
			std::cout << "Error::Shader::Program::Linking Failed!" << std::endl << infoLog << std::endl;
			return false;
		}

		glDeleteShader(vertex);
		glDeleteShader(fragment);

		return true;
	
	}
	


}