#pragma once

#define FIREBALL 0
#define SPIT 1

#define FINISHED 0
#define RUNNING 1

class Spell
{

	


public:
	Sprite * m_sprite;
	float speed;
	int damage;
	int type;
	glm::vec2 position;
	glm::ivec2 rPosition;
	glm::vec2 scale;
	bool active;
	int direction;
	bool state;
	std::string path;
	glm::vec2 offset;

	inline Spell(int spellID, glm::vec2 position, glm::vec2 offset, glm::vec2 scale, float speed, int direction)
		: position(position), scale(scale), speed(speed), direction(direction), offset(offset)
	{

		if (spellID == FIREBALL)
			path = "data/spells/fireball.png";

		this->m_sprite = new Sprite();
		this->m_sprite->Load(path.c_str());
		this->active = true;
		this->state = RUNNING;
	}

	inline void Operate(Controller *ctrl, ScreenUniformData * u_data, GameObject *g_obj)
	{

		
		rPosition = glm::ivec2((this->position - offset )/ this->scale);

		if (g_obj->GetCollisionMap()->GetTiles()[rPosition.x][rPosition.y] == 0)
		{

			if (direction == UP)
				{
					position.y -= speed;
				}
			if (direction == DOWN && g_obj->GetCollisionMap()->GetTiles()[rPosition.x][rPosition.y + 1] == 0 )
				{
					position.y += speed;
				}
			else if (direction == DOWN && g_obj->GetCollisionMap()->GetTiles()[rPosition.x][rPosition.y + 1] == 1)
			{
				this->active = false;
				this->state = FINISHED;
			}
			if (direction == LEFT)
				{
					position.x -= speed;
				}
			if (direction == RIGHT && g_obj->GetCollisionMap()->GetTiles()[rPosition.x + 1][rPosition.y] == 0)
				{
					position.x += speed;
				}
			else if (direction == RIGHT && g_obj->GetCollisionMap()->GetTiles()[rPosition.x + 1][rPosition.y] == 1)
			{
				this->active = false;
				this->state = FINISHED;
			}

			this->Render(ctrl, u_data, g_obj);
		}
		else
		{
			this->active = false;
			this->state = FINISHED;
		}
		
	}

	inline void Render(Controller *ctrl, ScreenUniformData * u_data, GameObject *g_obj)
	{
		u_data->SetAmbientLight();
		u_data->ApplyMatrix(Translation(this->position)*Scale(this->scale));
		this->m_sprite->Render(0);
	}

};

