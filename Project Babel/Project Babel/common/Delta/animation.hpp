#ifndef ANIMATION_HPP
#define ANIMATION_HPP



class Animation
{


	GLfloat frames;
	GLuint num_frames;




public:


	inline GLfloat GetFrames(){ return this->frames; }
	inline GLuint GetIFrames(){ return GLuint(this->frames); }
	inline GLuint GetNumFrames(){ return this->num_frames; }


	inline GLboolean Finished(){ return this->frames >= this->num_frames; }
	inline GLboolean Started(){ return this->frames > 0.0f; }


	inline Animation(GLuint num_frames){ this->Init(num_frames); }
	void Init(GLuint num_frames);
	void Update(GLfloat speed, GLfloat delta);


};







#endif