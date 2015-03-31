//Checked 1



#ifndef TEXT_RENDER_HPP
#define TEXT_RENDER_HPP




class TextRender
{



	GLuint m_VAO;


	GLuint program;


	GLuint font_texture_uniform;


	GLuint half_screen_uniform;


	GLuint font_color_uniform;


public:



	inline TextRender() { }


	inline ~TextRender() { this->Clean(); }



	void SetColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a);



	void SetColor(GLfloat r, GLfloat g, GLfloat b);



	void BindCreate(char * vertex_shader, char * fragment_shader);


	void UnbindCreate();


	void BindRun(GLuint window_width, GLuint window_height);


	void UnbindRun();


	void Clean();




};



#endif






