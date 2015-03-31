//Checked 1



#include <common.hpp>



void TextRender::BindCreate(char * vertex_shader, char * fragment_shader)
{


	glGenVertexArrays(1, &m_VAO);


	glBindVertexArray(m_VAO);



	this->program = LoadShaders(vertex_shader, fragment_shader);


	this->font_texture_uniform = glGetUniformLocation(this->program, "myTextureSampler");


	this->half_screen_uniform = glGetUniformLocation(this->program, "half_screen_size");


	this->font_color_uniform = glGetUniformLocation(this->program, "fontColor");

}



void TextRender::UnbindCreate()
{

	glBindVertexArray(0);

}





void TextRender::BindRun(GLuint window_width, GLuint window_height)
{


	glBindVertexArray(m_VAO);


	glUseProgram(this->program);


	glUniform1i(this->font_texture_uniform, 0);


	glUniform2f(this->half_screen_uniform, window_width / 2, window_height / 2);


}
	



void TextRender::UnbindRun()
{


	glUseProgram(0);


	glBindVertexArray(0);


}



void TextRender::Clean()
{



	glDeleteProgram(this->program);


	glDeleteVertexArrays(1, &m_VAO);




}




void TextRender::SetColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{


	glUniform4f(this->font_color_uniform, r, g, b, a); 


}



void TextRender::SetColor(GLfloat r, GLfloat g, GLfloat b)
{ 

	glUniform4f(this->font_color_uniform, r, g, b, 1.0f); 

}



