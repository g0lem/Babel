#pragma once



class EffectsHandler:public Controller
{
	
public:
	
	inline void FadeOut(ScreenUniformData *u_data, Sprite * m_sprite, int frame, float speed, float &alpha){

		u_data->SetAmbientLight(glm::vec4(1.f, 1.f, 1.f, alpha));
		m_sprite->Render(frame);

		alpha -= 1 / speed;
		
	}

	inline void FadeIn(ScreenUniformData *u_data, Sprite * m_sprite, int frame,float speed, float &alpha){

		u_data->SetAmbientLight(glm::vec4(1.f, 1.f, 1.f, alpha));
		m_sprite->Render(frame);
		alpha += 1 / speed;

	}

	inline void Blink(ScreenUniformData *u_data, Sprite * m_sprite, int frame, float &alpha,float speed, bool &turn){

		if (alpha < 0.1f)
			turn = false;
		else if (alpha > 0.9f)
			turn = true;


		u_data->SetAmbientLight(glm::vec4(1.f, 1.f, 1.f, alpha));
		m_sprite->Render(frame);

		if (turn == false)
			alpha += 1 / speed;
		else
			alpha -= 1 / speed;


	}

};

