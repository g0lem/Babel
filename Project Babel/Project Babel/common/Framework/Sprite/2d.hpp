//Checked 1



#ifndef SIMPLE_2D_HPP
#define SIMPLE_2D_HPP



class Aaether2D 
{



	ScreenUniformData * u_data;

	GLuint texID;


	GLuint ortho;


	GLuint program;


	GLuint m_VAO;


	void Ortho(GLuint window_width, GLuint window_height);



	
public:



	inline Aaether2D(){}


	inline ~Aaether2D(){ this->Clean(); }



	void Clean();



	void BindCreate(char * vertex_shader, char * fragment_shader);


	void UnbindCreate();



	void BindRun(GLuint window_width, GLuint window_height);


	void UnbindRun();
	


	inline ScreenUniformData * GetScreenPointer(){ return this->u_data; }


};



#endif