//Checked 1




#include <common.hpp>




FIBITMAP *get_dib(char* file)
{
	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
	FIBITMAP *dib(0);
	fif = FreeImage_GetFileType(file, 0);
	if (fif == FIF_UNKNOWN)
		fif = FreeImage_GetFIFFromFilename(file);
	if (fif == FIF_UNKNOWN)
		return NULL;
	if (FreeImage_FIFSupportsReading(fif))
		dib = FreeImage_Load(fif, file);
	if (!dib)
		return NULL;
	FreeImage_FlipVertical(dib);
	return dib;
}

GLuint load_texture(char* file, GLint param)
{
	BYTE* bits(0);
	unsigned int width(0), height(0);
	GLuint gl_texID;
	FIBITMAP *dib = get_dib(file);
	if (!dib)
		return -1;
	bits = FreeImage_GetBits(dib);
	width = FreeImage_GetWidth(dib);
	height = FreeImage_GetHeight(dib);
	if ((bits == 0) || (width == 0) || (height == 0))
		return -1;
	glGenTextures(1, &gl_texID);
	glBindTexture(GL_TEXTURE_2D, gl_texID);
	if (FreeImage_GetBPP(dib) == 24){
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, bits);
	}
	else if (FreeImage_GetBPP(dib) == 32){
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_BGRA, GL_UNSIGNED_BYTE, bits);
	}
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, param);
	glBindTexture(GL_TEXTURE_2D,0);
	FreeImage_Unload(dib);
	return gl_texID;
}

GLuint create_texture_from_color(GLfloat r, GLfloat g, GLfloat b){
	GLuint gl_texID;
	BYTE * bits = new BYTE[3];
	bits[0] = (r * 255);
	bits[1] = (g * 255);
	bits[2] = (b * 255);
	glGenTextures(1, &gl_texID);
	glBindTexture(GL_TEXTURE_2D, gl_texID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1, 1, 0, GL_RGB, GL_UNSIGNED_BYTE, bits);
	glBindTexture(GL_TEXTURE, 0);
	delete bits;
	return gl_texID;
}

