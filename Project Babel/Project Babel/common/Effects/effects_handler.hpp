#pragma once



class EffectsHandler
{
	

public:
	
	inline static void FadeOut(ScreenUniformData *u_data, Sprite * m_sprite, int frame, float &alpha){

		u_data->SetAmbientLight(glm::vec4(1.f, 1.f, 1.f, alpha));
		m_sprite->Render(frame);
		alpha -= 1 / 255.f;
		
	}

	inline static void FadeIn(ScreenUniformData *u_data, Sprite * m_sprite, int frame, float &alpha){

		u_data->SetAmbientLight(glm::vec4(1.f, 1.f, 1.f, alpha));
		m_sprite->Render(frame);
		alpha += 1 / 255.f;

	}

	inline static void Blink(ScreenUniformData *u_data, Sprite * m_sprite, int frame, float &alpha, bool &turn){

		if (alpha < 0.1f)
			turn = false;
		else if (alpha > 0.9f)
			turn = true;


		u_data->SetAmbientLight(glm::vec4(1.f, 1.f, 1.f, alpha));
		m_sprite->Render(frame);

		if (turn == false)
			alpha += 1 / 255.f;
		else
			alpha -= 1 / 255.f;


	}

};

