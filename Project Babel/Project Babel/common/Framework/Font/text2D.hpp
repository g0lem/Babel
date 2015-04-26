//Checked 1


#ifndef TEXT2D_HPP
#define TEXT2D_HPP







typedef char GLchar;


#include FT_FREETYPE_H

typedef struct {
	float x, y, z;    // position
	float s, t;       // texture
	float r, g, b, a; // color
} vertex_t;


class Font
{


	GLuint Text2DTextureID;
	GLuint Text2DVertexBufferID;
	GLuint Text2DUVBufferID;



	GLuint glyph_offset[256];


	GLuint glyph_width;




	inline GLint next_p2(GLint a)
	{
		GLint rval = 1;

		while (rval<a) rval <<= 1;
		return rval;
	}


public:

		texture_atlas_t *m_atlas;
		texture_font_t *m_font;
		int m_size;
		glm::vec2 scale;
		std::string name;
		std::string filename;


		void jambo(std::string name, std::string filename, int size)
		{
			name = name;
			filename = filename;
			m_size = size;
			m_atlas = texture_atlas_new(512, 512, 1);
			m_font = texture_font_new_from_file(m_atlas, size, filename.c_str());
		}
		void setScale(float x, float y){
			scale = glm::vec2(x, y);
		}
		int GetID(){ return this->m_atlas->id; }
		glm::vec2 GetScale(){ return this->scale; }
		std::string GetString(){ return this->name; }
		std::string GetPath(){ return this->filename; }
		int GetSize(){ return this->m_size; }

	GLvoid Create(char * texturePath, GLuint size);
	GLvoid Print(const GLchar * text, GLint x, GLint y, GLint size);
	GLfloat GetLength(const GLchar * text, GLint size);
	GLvoid Clean();




};



#endif