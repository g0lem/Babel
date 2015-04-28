//Checked 1



#ifndef UNIFORM_2D_HPP
#define UNIFORM_2D_HPP







class ScreenUniformData
{



	GLuint TransformMatrix;
	GLuint AmbientLight;
	GLuint newUV;


public:



	inline ScreenUniformData(GLuint program){ this->Init(program); }


	void Init(GLuint program);


	
	inline void ApplyMatrix(glm::mat3 tr){ glUniformMatrix3fv(this->TransformMatrix, 1, GL_FALSE, &tr[0][0]); }
	inline void SetAmbientLight(glm::vec4 ambient){ glUniform4f(this->AmbientLight, ambient.x, ambient.y, ambient.z, ambient.w); }
	inline void SetAmbientLight(){ glUniform4f(this->AmbientLight, 1.f, 1.f, 1.f, 1.f); }
	inline void SetAmbientLight(glm::vec3 ambient){ this->SetAmbientLight(glm::vec4(ambient, 1.0f)); }
	inline void SetNewUV(glm::vec4 newUV){ glUniform4f(this->newUV, newUV.x, newUV.y,newUV.z,newUV.w); }



};




#endif