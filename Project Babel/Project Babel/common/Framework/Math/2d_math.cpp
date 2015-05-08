//Checked 1


#include <common.hpp>





glm::mat3 Translation(GLfloat x, GLfloat y)
{


	glm::mat3 tr(1.0f);


	tr[2] = glm::vec3(x, y, 1.0f);


	return tr;

}



glm::mat3 Scale(GLfloat x_scale, GLfloat y_scale)
{


	glm::mat3 tr(1.0f);

	tr[0].x = x_scale;
 
	tr[1].y = y_scale;


	return tr;

}




glm::mat3 Rotation(GLfloat alpha)
{


	glm::mat3 tr(1.0f);


	tr[0].x = cos(alpha);
	tr[0].y = sin(alpha);

	tr[1].x = sin(alpha);
	tr[1].y = cos(alpha);



	return tr;

}




GLuint compare_vec2(glm::vec2 a, glm::vec2 b)
{


	if (a.x >= b.x&&a.y >= b.y)
		return V_GREATER;
	else if (a.x < b.x && a.y < b.y)
		return V_LESSER;
	else
		return V_UNDEFINED;


}













