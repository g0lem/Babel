//Checked 1


#include <common.hpp>


GLuint Dice::Get(GLuint values[], GLuint n, GLuint num_faces)
{

	GLuint offset = 1;

	GLuint result = Rand(num_faces) + 1;


	for (GLuint i = 0; i < n; i++)
		if (result >= offset&& result < offset + values[i])
			return i;
		else
			offset += values[i];

	

}