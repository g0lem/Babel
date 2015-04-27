#pragma once

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

class EffectsHandler
{
	
public:
	
	inline void FadeOut(Controller*ctrl,
		ScreenUniformData *u_data,
		Sprite * m_sprite, int frame,
		float speed, 
		float &alpha){

		u_data->SetAmbientLight(glm::vec4(1.f, 1.f, 1.f, alpha));
		m_sprite->Render(frame);

		alpha -= ctrl->GetFpsPointer()->Delta()*speed;
		
	}

	inline void FadeIn(Controller *ctrl, ScreenUniformData *u_data, Sprite * m_sprite, int frame,float speed, float &alpha){

		u_data->SetAmbientLight(glm::vec4(1.f, 1.f, 1.f, alpha));
		m_sprite->Render(frame);

		alpha += ctrl->GetFpsPointer()->Delta()*speed;

	}

	inline void Blink(Controller *ctrl, ScreenUniformData *u_data, Sprite * m_sprite, int frame, float &alpha,float speed, bool &turn){

		if (alpha < 0.1f)
			turn = false;
		else if (alpha > 0.9f)
			turn = true;

		u_data->SetAmbientLight(glm::vec4(1.f, 1.f, 1.f, alpha));
		m_sprite->Render(frame);

		if (turn == false)
			alpha += ctrl->GetFpsPointer()->Delta()*speed;
		else
			alpha -= ctrl->GetFpsPointer()->Delta()*speed;


	}

	inline void TextFade(Controller * ctrl,
		Font *font,
		char* text,
		TextRender *tr,
		glm::vec2 &position,
		glm::vec4 &color,
		int size,
		int direction, 
		float speed)
	{

		speed *= ctrl->GetFpsPointer()->Delta();

		tr->SetColor(color.r, color.g, color.b, color.a);
		if (direction == UP)
			position.y -= speed;
		else if (direction == LEFT)
			position.x -= speed;
		else if (direction == RIGHT)
			position.x += speed;
		else if (direction == DOWN)
			position.y += speed;

		color.a -= 8.0f*ctrl->GetFpsPointer()->Delta();
		font->Print(text, position.x, ctrl->GetWindowHeight() - position.y, size);
	}

};

