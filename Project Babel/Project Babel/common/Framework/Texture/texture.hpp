//Checked 1




#ifndef TEXTURE_HPP
#define TEXTURE_HPP




#define POWER_OF_TWO(x) ( (x > 0) && ((x & (x - 1)) == 0) ) 




GLuint load_texture(char* file, GLint param = GL_NEAREST);




GLuint create_texture_from_color(GLfloat r, GLfloat y, GLfloat z);



FIBITMAP *get_dib(char* file);


#endif