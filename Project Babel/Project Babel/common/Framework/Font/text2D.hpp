//Checked 1


#ifndef TEXT2D_HPP
#define TEXT2D_HPP







typedef char GLchar;


#include FT_FREETYPE_H




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


	GLvoid Create(char * texturePath, GLuint size);
	GLvoid Print(const GLchar * text, GLint x, GLint y, GLint size);
	GLfloat GetLength(const GLchar * text, GLint size);
	GLvoid Clean();




};

#endif