//Checked 1



#include <common.hpp>



void Aaether2D::BindCreate(char * vertex_shader,char * fragment_shader)

{

	glGenVertexArrays(1, &m_VAO);


	glBindVertexArray(m_VAO);


	this->program = LoadShaders(vertex_shader, fragment_shader);


	this->texID = glGetUniformLocation(this->program, "texture");


	this->ortho = glGetUniformLocation(this->program, "ortho");


	this->u_data = new ScreenUniformData(this->program);


}

void Aaether2D::UnbindCreate()
{

	glBindVertexArray(0);


}








void Aaether2D::Ortho(GLuint window_width, GLuint window_height)
{


	glUniformMatrix4fv(this->ortho, 1, GL_FALSE, &(glm::ortho<GLfloat>(0, window_width, window_height, 0)[0][0]));


}



void Aaether2D::BindRun(GLuint window_width,GLuint window_height)
{

	glBindVertexArray(this->m_VAO);


	glUseProgram(this->program);


	glUniform1i(this->texID, 0);


	this->Ortho(window_width, window_height);


	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);




}



void Aaether2D::UnbindRun()
{



	glDisable(GL_BLEND);


	glUseProgram(0);



	glBindVertexArray(0);



}




void Aaether2D::Clean()
{


		glDeleteProgram(this->program);


		glDeleteVertexArrays(1, &m_VAO);

		

}





