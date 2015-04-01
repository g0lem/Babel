#pragma once

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

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

	inline void TextFade(char* text, glm::vec2 &position, Font *font,int size, int direction, float &alpha, float speed, ScreenUniformData *u_data)
	{
		u_data->SetAmbientLight(glm::vec4(1.f, 1.f, 1.f, alpha));
		font->Print(text, position.x, position.y, size);
		if (direction == UP)
			position.y -= 1 / speed;
		else if (direction == LEFT)
			position.x -= 1 / speed;
		else if (direction == RIGHT)
			position.y += 1 / speed;
		else if (direction == DOWN)
			position.x += 1 / speed;
		alpha -= 1 / speed;
	}

};

