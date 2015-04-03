//Checked 1


#include <common.hpp>



void ScreenUniformData::Init(GLuint program)
{




	this->TransformMatrix = glGetUniformLocation(program, "TransformMatrix");
	this->AmbientLight = glGetUniformLocation(program, "AmbientLight");
	this->newUV = glGetUniformLocation(program, "newUV");


}



