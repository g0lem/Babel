#pragma once

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

class EffectsHandler
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

	inline void TextFade(Font *font, char* text, TextRender *tr, glm::vec2 &position, int size, int direction, float speed, float &alpha)
	{
		tr->SetColor(1.f, 1.f, 1.f, alpha);
		if (direction == UP)
			position.y += 2 / speed;
		else if (direction == LEFT)
			position.x -= 2 / speed;
		else if (direction == RIGHT)
			position.x += 2 / speed;
		else if (direction == DOWN)
			position.y -= 2 / speed;

		alpha -= 1/75.f;
		font->Print(text, position.x, position.y, size);
	}

};

