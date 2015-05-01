//Checked 1




#include <common.hpp>


void Font::Init(std::string name, std::string filename, int size)
{
	name = name;
	filename = filename;
	m_size = size;
	m_atlas = texture_atlas_new(512, 512, 1);
	this->m_fonts = new std::vector < texture_font_t * > ;

	this->GenerateFonts(10, size, m_atlas, filename);
}

void Font::GenerateFonts(int min, int max, texture_atlas_t *atlas, std::string filename)
{

	for (int i = min; i <= max; i++)
	{

		this->m_fonts->push_back(texture_font_new_from_file(atlas, i, filename.c_str()));
	}

}

texture_font_t * Font::GetFontIndex(int size)
{
	for (int i = 0; i < m_fonts->size(); i++)
	{
		if (this->m_fonts->at(i)->size == size)
			return this->m_fonts->at(i);
	}
}

GLvoid Font::Create(GLchar * texturePath, GLuint size)
{
	glGenBuffers(1, &Text2DVertexBufferID);
	glGenBuffers(1, &Text2DUVBufferID);

	Init("Arial", "data/fonts/choco.ttf", 80);
	this->scale = glm::vec2(1, 1);
}


GLvoid Font::Print(const GLchar * text, GLint x, GLint y, GLint size){
	GLuint length = strlen(text);
	GLfloat character_offset = 0;

	std::vector<glm::vec2> vertices;
	std::vector<glm::vec2> UVs;
	printf("%s\n", text);

	float ny = y;

	float x3 = x;
	texture_font_t *font = this->GetFontIndex(size);
	glm::vec2 scale = glm::vec2(1, 1);

	for (GLuint i = 0; i<length; i++){

		GLchar character = text[i];
		texture_glyph_t *glyph = texture_font_get_glyph(font, character);

		float x0 = x3 + glyph->offset_x / scale.x;
		float y0 = y + glyph->offset_y / scale.y;
		float x1 = x0 + glyph->width / scale.x;
		float y1 = y0 - glyph->height / scale.y;

		float u0 = glyph->s0;
		float v0 = glyph->t0;
		float u1 = glyph->s1;
		float v1 = glyph->t1;


		glm::vec2 vertex_up_left = glm::vec2(x0, y0);
		glm::vec2 vertex_up_right = glm::vec2(x0, y1);
		glm::vec2 vertex_down_left = glm::vec2(x1, y1);
		glm::vec2 vertex_down_right = glm::vec2(x1, y0);

		vertices.push_back(vertex_up_left);
		vertices.push_back(vertex_down_left);
		vertices.push_back(vertex_up_right);

		vertices.push_back(vertex_up_left);
		vertices.push_back(vertex_down_left);
		vertices.push_back(vertex_down_right);


		glm::vec2 uv_up_left = glm::vec2(u0, v0);
		glm::vec2 uv_up_right = glm::vec2(u0, v1);
		glm::vec2 uv_down_left = glm::vec2(u1, v1);
		glm::vec2 uv_down_right = glm::vec2(u1, v0);

		UVs.push_back(uv_up_left);
		UVs.push_back(uv_down_left);
		UVs.push_back(uv_up_right);

		UVs.push_back(uv_up_left);
		UVs.push_back(uv_down_left);
		UVs.push_back(uv_down_right);


		x3 += glyph->advance_x / scale.x;
	}



	glBindBuffer(GL_ARRAY_BUFFER, Text2DVertexBufferID);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec2), &vertices[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, Text2DUVBufferID);
	glBufferData(GL_ARRAY_BUFFER, UVs.size() * sizeof(glm::vec2), &UVs[0], GL_STATIC_DRAW);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, GetID());

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, Text2DVertexBufferID);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, Text2DUVBufferID);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDrawArrays(GL_TRIANGLES, 0, vertices.size());
	glDisable(GL_BLEND);
}


GLfloat Font::GetLength(const GLchar * text, GLint size)
{
	GLuint length = strlen(text);

	texture_font_t * font = this->GetFontIndex(size);

	int x = 0;

	for (GLuint i = 0; i < length; i++)
	{
		GLchar character = text[i];
		texture_glyph_t *glyph = texture_font_get_glyph(font, character);
		x += glyph->advance_x;
	}

	return x;
}


GLvoid Font::Clean()
{
	glDeleteBuffers(1, &Text2DVertexBufferID);
	glDeleteBuffers(1, &Text2DUVBufferID);
	glDeleteTextures(1, &Text2DTextureID);
}
