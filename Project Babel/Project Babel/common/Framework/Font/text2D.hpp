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


	GLvoid Create(char * texturePath, GLuint size);
	GLvoid Print(const GLchar * text, GLint x, GLint y, GLint size);
	void Print(const char *test, int x, int y, int size, vertex_buffer_t *buffer)
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		vertex_buffer_render(buffer, GL_TRIANGLES);
		glDisable(GL_BLEND);
	}

	void add_text(vertex_buffer_t * buffer, texture_font_t * font,
		wchar_t * text, vec4 * color, vec2 * pen)
	{
		size_t i;
		float r = color->red, g = color->green, b = color->blue, a = color->alpha;
		for (i = 0; i<wcslen(text); ++i)
		{
			texture_glyph_t *glyph = texture_font_get_glyph(font, text[i]);
			if (glyph != NULL)
			{
				float kerning = 0.0f;
				if (i > 0)
				{
					kerning = texture_glyph_get_kerning(glyph, text[i - 1]);
				}
				pen->x += kerning;
				int x0 = (int)(pen->x + glyph->offset_x);
				int y0 = (int)(pen->y + glyph->offset_y);
				int x1 = (int)(x0 + glyph->width);
				int y1 = (int)(y0 - glyph->height);
				float s0 = glyph->s0;
				float t0 = glyph->t0;
				float s1 = glyph->s1;
				float t1 = glyph->t1;
				GLuint indices[6] = { 0, 1, 2, 0, 2, 3 };
				vertex_t vertices[4] = { { x0, y0, 0, s0, t0, r, g, b, a },
				{ x0, y1, 0, s0, t1, r, g, b, a },
				{ x1, y1, 0, s1, t1, r, g, b, a },
				{ x1, y0, 0, s1, t0, r, g, b, a } };
				vertex_buffer_push_back(buffer, vertices, 4, indices, 6);
				pen->x += glyph->advance_x;
			}
		}
	}
	GLfloat GetLength(const GLchar * text, GLint size);
	GLvoid Clean();




};

#endif