#include <common.hpp>

void Animation::Init(GLuint num_frames)
{


	this->num_frames = num_frames;




	this->frames = 0;


}


void Animation::Update(GLfloat speed,GLfloat delta)
{





	frames += speed*delta;


	if (frames >= num_frames)
		frames = 0;




}