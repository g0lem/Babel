//Checked 1



#ifndef METH_2D_HPP
#define METH_2D_HPP





#ifndef M_PI
#define M_PI 3.14159265358979
#endif


#ifndef TO_RADIANS(a)
#define TO_RADIANS(a) a/180.0 * M_PI
#endif


#ifndef vec2_0
#define vec2_0 glm::vec2(0.0f, 0.0f)
#endif



#define V_GREATER 0
#define V_LESSER 1
#define V_UNDEFINED 2


class Contains{


public:


	static inline bool Circle(glm::vec2 arg, glm::vec2 container, glm::vec2 scale){
		
		glm::vec2 center(container + scale/2.f);
				if (glm::distance(center, arg) < scale.x/2.f)
				return true;
		return false;
	}
	
	static inline bool Rectangle(glm::vec2 arg, glm::vec2 container, glm::vec2 scale){
		if (arg.x >= container.x&&arg.y >= container.y)
			if (arg.x <= container.x + scale.x && arg.y <= container.y + scale.y)
				return true;
		return false;
	}
};

glm::mat3 Translation(GLfloat x, GLfloat y);


inline glm::mat3 Translation(glm::vec2 t_vec){return Translation(t_vec.x, t_vec.y); }


glm::mat3 Scale(GLfloat x_scale, GLfloat y_scale);




inline glm::mat3 Scale(GLfloat scale){return Scale(scale, scale); }


inline glm::mat3 Scale(glm::vec2 scale){ return Scale(scale.x, scale.y); }






glm::mat3 Rotation(GLfloat alpha);



inline glm::mat3 Shaorma(glm::vec2 pos, glm::vec2 scale, GLfloat alpha)
{
	return Translation(pos)*Rotation(TO_RADIANS(alpha))*Translation(-scale / 2.0f)*Scale(scale); 
}


inline GLuint Rand(GLuint n){ return rand() % n; }


inline GLuint Rand(GLuint a, GLuint b){ return rand() % (b - a + 1) + a; }


inline glm::vec2 GridPosition(glm::vec2 pos, glm::vec2 scale) { return glm::vec2(glm::ivec2(pos / scale))*scale; }



inline glm::vec2 GetCenter(glm::vec2 point_a, glm::vec2 point_b){ return (point_a + point_b) / 2.0f; }


inline glm::vec2 GetCenter(glm::vec2 points[2]){ return GetCenter(points[0], points[1]); }


inline glm::ivec2 GetCenter(glm::ivec2 point_a, glm::ivec2 point_b){ return (point_a + point_b) / 2; }


inline glm::ivec2 GetCenter(glm::ivec2 points[2]){ return GetCenter(points[0], points[1]); }



inline GLvoid print_vec2(glm::vec2 t_vec){ printf("%.2f, %.2f\n", t_vec.x, t_vec.y); }
inline GLvoid print_vec2(glm::ivec2 t_vec){ printf("%i, %i\n", t_vec.x, t_vec.x); }


inline GLboolean vec2_i(glm::vec2 t_vec){ return (glm::vec2(glm::ivec2(t_vec)) == t_vec); }


GLuint compare_vec2(glm::vec2 a, glm::vec2 b);



inline GLboolean Between(glm::vec2 b, glm::vec2 a, glm::vec2 c){ return (compare_vec2(b, a) == V_GREATER) && (compare_vec2(b, c) == V_LESSER); }



#endif



