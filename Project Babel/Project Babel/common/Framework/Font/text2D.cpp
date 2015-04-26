//Checked 1




#include <common.hpp>




GLvoid Font::Create(GLchar * texturePath, GLuint size)
{




	glGenBuffers(1, &Text2DVertexBufferID);
	glGenBuffers(1, &Text2DUVBufferID);


	FT_Library ft;

	if (FT_Init_FreeType(&ft)) {
		fprintf(stderr, "Could not init freetype library\n");
		return;
	}

	FT_Face face;

	if (FT_New_Face(ft, texturePath, 0, &face)) {
		fprintf(stderr, "Could not open font\n");
		return;
	}

	FT_Set_Pixel_Sizes(face, 0, size);
	


	GLuint g_width = 0, g_height = 0;



	for (GLuint c = 0; c < 256; c++)
	{


		if (FT_Load_Char(face, c, FT_LOAD_RENDER))
		{
			fprintf(stderr, "Could not load character &x\n",c);
			return;
		}


		FT_GlyphSlot g = face->glyph;




		if (g->bitmap.width > g_width)
			g_width = g->bitmap.width;

		if (g->bitmap.rows > g_height)
			g_height = g->bitmap.rows;

	}


	g_width = next_p2(g_width);
	g_height = next_p2(g_height);



	this->glyph_width = g_width;



	glGenTextures(1, &this->Text2DTextureID);
	glBindTexture(GL_TEXTURE_2D, this->Text2DTextureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, 16 * g_width, 16 * g_height, 0, GL_RED, GL_UNSIGNED_BYTE, 0);


	for (GLuint j = 0; j < 16; j++)
	{

		for (GLuint i = 0; i < 16; i++)

		{


			if (FT_Load_Char(face, j*16+i, FT_LOAD_RENDER)) {
				fprintf(stderr, "Could not load character &x\n", j*16+i);
				return;
			}


			FT_GlyphSlot g = face->glyph;




			this->glyph_offset[16 * j + i] = (g_width - g->bitmap.width) / 2;


			glTexSubImage2D(GL_TEXTURE_2D,
				0,
				g_width*i + (g_width-g->bitmap.width)/2,
				g_height*j + (g_height-g->bitmap.rows)/2 ,
				g->bitmap.width, 
				g->bitmap.rows,
				GL_RED, 
				GL_UNSIGNED_BYTE, 
				g->bitmap.buffer);

		}
	}


	glBindTexture(GL_TEXTURE_2D, 0);
	jambo("Arial", "data/fonts/arial.ttf", 40);
	this->scale = glm::vec2(30, 30);


}

GLvoid Font::Print(const GLchar * text, GLint x, GLint y, GLint size){
	GLuint length = strlen(text);
	GLfloat character_offset = 0;

	std::vector<glm::vec2> vertices;
	std::vector<glm::vec2> UVs;



	float x3 = x;
	texture_font_t *font = this->m_font;
	glm::vec2 scale = glm::vec2(0.3, 0.3);

	for (GLuint i = 0; i<length; i++){

		GLchar character = text[i];
		//character_offset += GLfloat(this->glyph_offset[character]);
		texture_glyph_t *glyph = texture_font_get_glyph(font, character);
		if (i > 0)
		{
			float kerning = texture_glyph_get_kerning(glyph, text[i - 1]);
			character_offset += kerning;
		}

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

		vertices.push_back(vertex_down_right);
		vertices.push_back(vertex_up_right);
		vertices.push_back(vertex_down_left);


		glm::vec2 uv_up_left = glm::vec2(u0, v0);
		glm::vec2 uv_up_right = glm::vec2(u0, v1);
		glm::vec2 uv_down_left = glm::vec2(u1, v1);
		glm::vec2 uv_down_right = glm::vec2(u1, v0);

		UVs.push_back(uv_up_left);
		UVs.push_back(uv_down_left);
		UVs.push_back(uv_up_right);

		UVs.push_back(uv_down_right);
		UVs.push_back(uv_up_right);
		UVs.push_back(uv_down_left);


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
	GLfloat character_offset = 0;


	for (GLuint i = 0; i < length; i++)
	character_offset += GLfloat(this->glyph_offset[text[i]])*(GLfloat(size) / GLfloat(this->glyph_width));
	

	return GLfloat(length*size) - character_offset;
}


GLvoid Font::Clean()
{
	glDeleteBuffers(1, &Text2DVertexBufferID);
	glDeleteBuffers(1, &Text2DUVBufferID);
	glDeleteTextures(1, &Text2DTextureID);
}
