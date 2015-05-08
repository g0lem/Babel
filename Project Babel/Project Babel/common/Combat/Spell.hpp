#pragma once

#define FIREBALL 0
#define SPIT 1

#define FINISHED 0
#define RUNNING 1

#define endGOKU 0


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
	glm::vec2 finish;
	glm::vec2 ipos;
	glm::vec2 lpos;
	int npcscale;
	glm::vec2 maxd;
	bool player;
	glm::vec3 goku;

	inline Spell(int spellID, int damage, glm::vec2 position, glm::vec2 offset, glm::vec2 scale, float speed, int direction)
		: damage(damage), position(position), scale(scale), speed(speed), direction(direction), offset(offset)
	{

		if (spellID == FIREBALL)
			path = "data/spells/fireball.png";
		this->ipos = this->position;
		this->m_sprite = new Sprite();
		this->m_sprite->Load(path.c_str());
		npcscale = 1;
		player = false;
		this->active = true;
		this->state = true;
		goku = glm::vec3(1, 1, 1);
		maxd = glm::vec2(5, 5);
	}

	inline Spell(int spellID, int damage, glm::vec2 position, glm::vec2 offset, glm::vec2 scale, float speed, int direction, bool player)
		: damage(damage), position(position), scale(scale), speed(speed), direction(direction), offset(offset), player(player)
	{

		if (spellID == FIREBALL)
			path = "data/spells/fireball.png";
		this->ipos = this->position;
		this->m_sprite = new Sprite();
		this->m_sprite->Load(path.c_str());
		npcscale = 1;
		this->active = true;
		this->state = true;
		goku = glm::vec3(1, 1, 1);
		maxd = glm::vec2(5, 5);
	}

	inline Spell(int spellID, int damage, glm::vec2 position, glm::vec2 offset, glm::vec2 scale, float speed, int direction, glm::vec3 goku)
		: damage(damage), position(position), scale(scale), speed(speed), direction(direction), offset(offset), goku(goku)
	{

		if (spellID == FIREBALL)
			path = "data/spells/fireball.png";
		this->ipos = this->position;
		this->m_sprite = new Sprite();
		this->m_sprite->Load(path.c_str());
		npcscale = 1;
		player = false;
		this->active = true;
		this->state = true;
		maxd = glm::vec2(5, 5);
	}

	inline Spell(int spellID, int damage, glm::vec2 position, glm::vec2 offset, glm::vec2 scale, int npcscale, float speed, int direction)
		: damage(damage), position(position), scale(scale), speed(speed), direction(direction), offset(offset), npcscale(npcscale)
	{

		if (spellID == FIREBALL)
			path = "data/spells/fireball.png";
		this->ipos = this->position;
		this->m_sprite = new Sprite();
		this->m_sprite->Load(path.c_str());
		this->active = true;
		this->state = true;
		player = false;
		goku = glm::vec3(1, 1, 1);
		maxd = glm::vec2(5, 5);
	}

	inline Spell(int spellID, int damage, glm::vec2 position, glm::vec2 last, glm::vec2 offset, glm::vec2 scale, int npcscale, float speed, int direction)
		: damage(damage), position(position), scale(scale), speed(speed), direction(direction), offset(offset), lpos(last), npcscale(npcscale)
	{

		if (spellID == FIREBALL)
			path = "data/spells/fireball.png";
		this->ipos = this->position;
		this->m_sprite = new Sprite();
		this->m_sprite->Load(path.c_str());
		this->active = true;
		this->state = true;
		goku = glm::vec3(1, 1, 1);
		player = false;
		npcscale = 1;
		maxd = glm::vec2(5, 5);
	}

	inline glm::vec2 Operate(Controller *ctrl, ScreenUniformData * u_data, glm::vec2 offset, GLboolean **tiles)
	{
		rPosition = glm::ivec2((this->position - offset) / glm::vec2(32, 32));
		glm::ivec2 initial = glm::ivec2((this->ipos - offset) / glm::vec2(32, 32));


		if (direction == UP)
		{
			maxd = (glm::vec2)initial + glm::vec2(-5, -5);
		}
		else if (direction == DOWN)
		{
			maxd = (glm::vec2)initial + glm::vec2(5, +5);
		}
		else if (direction == LEFT)
		{
			maxd = (glm::vec2)initial + glm::vec2(-5, -5);
		}
		else if (direction == RIGHT)
		{
			maxd = (glm::vec2)initial + glm::vec2(5, 5);
		}



		bool check = true;

		//print_vec2(rPosition);
		//print_vec2(initial);

		if (npcscale == 1)
		{
			if ((tiles[rPosition.x][rPosition.y] == 0 || rPosition == initial) && rPosition.x >= 0 && rPosition.y >= 0 && !(rPosition == (glm::ivec2)lpos))
			{
				if (rPosition.x == maxd.x || rPosition.y == maxd.y)
				{
					this->active = false;
					return position;
				}
				else if (direction == UP)
				{
					position.y -= speed*ctrl->GetFpsPointer()->Delta() * 100;
				}
				else if (direction == DOWN && tiles[rPosition.x][rPosition.y + 1] == 0)
				{
					position.y += speed*ctrl->GetFpsPointer()->Delta() * 100;
				}
				else if (direction == DOWN && tiles[rPosition.x][rPosition.y + 1] == 1)
				{
					this->active = false;

					rPosition.y++;
					return position;
				}
				else if (direction == LEFT)
				{
					position.x -= speed*ctrl->GetFpsPointer()->Delta() * 100;
				}
				else if (direction == RIGHT && tiles[rPosition.x + 1][rPosition.y] == 0)
				{
					position.x += speed*ctrl->GetFpsPointer()->Delta() * 100;
				}
				else if (direction == RIGHT && tiles[rPosition.x + 1][rPosition.y] == 1)
				{
					this->active = false;
					rPosition.x++;
					return position;
				}
				this->Render(u_data);
			}
			else
			{
				this->active = false;
				return position;
			}
		}
		else
		{
			if ((tiles[rPosition.x][rPosition.y] == 0 || rPosition == initial) && rPosition.x >= 0 && rPosition.y >= 0 && !(rPosition == (glm::ivec2)lpos))
			{
				if (rPosition.x == maxd.x || rPosition.y == maxd.y)
				{
					this->active = false;
					return position;
				}
				else if (direction == UP && (
					tiles[rPosition.x][rPosition.y - 1] == 0 &&
					tiles[rPosition.x + 1][rPosition.y - 1] == 0 &&
					!(rPosition + glm::ivec2(0, -1) == glm::ivec2(lpos)) &&
					!(rPosition + glm::ivec2(1, -1) == glm::ivec2(lpos))))
				{
					position.y -= speed*ctrl->GetFpsPointer()->Delta() * 100;
				}
				else if (direction == UP && (
					tiles[rPosition.x][rPosition.y - 1] == 0 ||
					tiles[rPosition.x + 1][rPosition.y - 1] == 0 ||
					(rPosition + glm::ivec2(0, -1) == glm::ivec2(lpos)) ||
					(rPosition + glm::ivec2(1, -1) == glm::ivec2(lpos))
					))
				{
					this->active = false;

					if (rPosition + glm::ivec2(0, -1) == (glm::ivec2)(lpos) || tiles[rPosition.x][rPosition.y - 1] == 1)
						rPosition.y -= 1;
					else if (rPosition + glm::ivec2(1, -1) == (glm::ivec2)(lpos) || tiles[rPosition.x + 1][rPosition.y - 1] == 1)
					{
						rPosition += glm::ivec2(1, -1);
					}

					return position;
				}
				else if (direction == DOWN && (
					tiles[rPosition.x][rPosition.y + 2] == 0 &&
					tiles[rPosition.x + 1][rPosition.y + 2] == 0 &&
					!(rPosition + glm::ivec2(0, 2) == glm::ivec2(lpos)) &&
					!(rPosition + glm::ivec2(1, 2) == glm::ivec2(lpos))))
				{
					position.y += speed*ctrl->GetFpsPointer()->Delta() * 100;
				}
				else if (direction == DOWN && ((
					tiles[rPosition.x][rPosition.y + 2] == 1 ||
					(tiles[rPosition.x + 1][rPosition.y + 2] == 1 ||
					rPosition + glm::ivec2(0, 2) == (glm::ivec2)lpos) ||
					rPosition + glm::ivec2(1, 2) == (glm::ivec2)lpos)))
				{
					this->active = false;

					if (rPosition + glm::ivec2(0, 2) == (glm::ivec2)lpos || tiles[rPosition.x][rPosition.y + 2] == 1)
						rPosition.y += 2;
					else if ((tiles[rPosition.x + 1][rPosition.y + 2] == 1 || rPosition + glm::ivec2(1, 2) == (glm::ivec2)lpos))
					{
						rPosition += glm::ivec2(1, 2);
					}
					return position;
				}
				else if (direction == LEFT && (
					tiles[rPosition.x - 1][rPosition.y] == 0 &&
					tiles[rPosition.x - 1][rPosition.y + 1] == 0 &&
					!(rPosition + glm::ivec2(-1, 0) == glm::ivec2(lpos)) &&
					!(rPosition + glm::ivec2(-1, 1) == glm::ivec2(lpos))
					))
				{
					position.x -= speed*ctrl->GetFpsPointer()->Delta() * 100;
				}
				else if (direction == LEFT && (
					tiles[rPosition.x - 1][rPosition.y] == 0 ||
					tiles[rPosition.x - 1][rPosition.y + 1] == 0 ||
					(rPosition + glm::ivec2(-1, 0) == glm::ivec2(lpos)) ||
					(rPosition + glm::ivec2(-1, 1) == glm::ivec2(lpos))
					))
				{
					this->active = false;

					if (rPosition + glm::ivec2(-1, 0) == (glm::ivec2)(lpos) || tiles[rPosition.x - 1][rPosition.y] == 1)
						rPosition.x -= 1;
					else if (rPosition + glm::ivec2(-1, 1) == (glm::ivec2)(lpos) || tiles[rPosition.x - 1][rPosition.y + 1] == 1)
					{
						rPosition += glm::ivec2(-1, 1);
					}

					return position;
				}
				else if (direction == RIGHT && (
					tiles[rPosition.x + 2][rPosition.y] == 0 &&
					tiles[rPosition.x + 2][rPosition.y + 1] == 0 &&
					!(rPosition + glm::ivec2(2, 0) == glm::ivec2(lpos)) &&
					!(rPosition + glm::ivec2(2, 1) == glm::ivec2(lpos))))
				{
					position.x += speed*ctrl->GetFpsPointer()->Delta() * 100;
				}
				else if (direction == RIGHT && (
					tiles[rPosition.x + 2][rPosition.y] == 1 ||
					tiles[rPosition.x + 2][rPosition.y + 1] == 0 ||
					(rPosition + glm::ivec2(2, 0) == glm::ivec2(lpos)) ||
					(rPosition + glm::ivec2(2, 1) == glm::ivec2(lpos))))
				{
					this->active = false;
					if (tiles[rPosition.x + 2][rPosition.y] == 1 || rPosition + glm::ivec2(2, 0) == glm::ivec2(lpos))
						rPosition.x += 2;
					else if (tiles[rPosition.x + 2][rPosition.y + 1] == 1 || rPosition + glm::ivec2(2, 1) == glm::ivec2(lpos))
					{
						rPosition += glm::ivec2(2, 1);
					}

					return position;
				}

				this->Render(u_data);
			}
			else
			{
				this->active = false;
				return position;
			}
		}
	}





	inline void Render(ScreenUniformData * u_data)
	{
			u_data->SetAmbientLight(goku);
			if (direction == UP)
				u_data->ApplyMatrix(Translation(this->position + glm::vec2(32, 32)*(float)npcscale)*Scale(this->scale)*Rotation((3 * 3.14159265359 / 2)));
			else if (direction == DOWN)
				u_data->ApplyMatrix(Translation(this->position)*Scale(this->scale)*Rotation((3.14159265359 / 2)));
			else if (direction == LEFT)
				u_data->ApplyMatrix(Translation(this->position + glm::vec2(32, 32)*(float)npcscale)*Scale(this->scale)*Rotation(3.14159265359));
			else if (direction == RIGHT)
				u_data->ApplyMatrix(Translation(this->position)*Scale(this->scale));

		
		this->m_sprite->Render(0);
	}

};

