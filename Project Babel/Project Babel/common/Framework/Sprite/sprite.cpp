//Checked 1


#include <common.hpp>



void Sprite::Load(GLuint num_textures, char * dir, char ** textures_str)
{


	GLfloat buffer[] = {
		0.0f, 0.0f,
		1.0f, 0.0f,
		0.0f, 1.0f,
		0.0f, 1.0f,
		1.0f, 0.0f, 
		1.0f, 1.0f, 
	};



	glGenBuffers(1, &this->m_VBO);


	glBindBuffer(GL_ARRAY_BUFFER, this->m_VBO);


	glBufferData(GL_ARRAY_BUFFER, sizeof(buffer), &buffer, GL_STATIC_DRAW);


	glEnableVertexAttribArray(0);


	glVertexAttribPointer(
		0,
		2,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
		);


	glBindBuffer(GL_ARRAY_BUFFER, 0);


	this->num_textures = num_textures;


	this->textures = new GLuint[this->num_textures];


	for (GLuint i = 0; i < this->num_textures; i++)
	
	
	{

		std::string temp(dir);
		temp += textures_str[i];
		std::vector<char> writable(temp.begin(), temp.end());
		writable.push_back('\0');

		this->textures[i] = load_texture(&temp[0], GL_LINEAR);



	}

}

void Sprite::Load(char * dir, char * textures_str)
{


	GLfloat buffer[] = {
		0.0f, 0.0f,
		1.0f, 0.0f,
		0.0f, 1.0f,
		0.0f, 1.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
	};



	glGenBuffers(1, &this->m_VBO);


	glBindBuffer(GL_ARRAY_BUFFER, this->m_VBO);


	glBufferData(GL_ARRAY_BUFFER, sizeof(buffer), &buffer, GL_STATIC_DRAW);


	glEnableVertexAttribArray(0);


	glVertexAttribPointer(
		0,
		2,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
		);


	glBindBuffer(GL_ARRAY_BUFFER, 0);


	this->num_textures = num_textures;


	this->textures = new GLuint[0];


	std::string temp(dir);
	temp += textures_str;
	std::vector<char> writable(temp.begin(), temp.end());
	writable.push_back('\0');

	this->textures[0] = load_texture(&temp[0], GL_LINEAR);


}



void Sprite::Render(GLuint current_frame)
{


	this->RenderTexture(this->textures[current_frame]);

}


void Sprite::RenderTexture(GLuint texture)
{

	glBindBuffer(GL_ARRAY_BUFFER, this->m_VBO);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindTexture(GL_TEXTURE_2D, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}
