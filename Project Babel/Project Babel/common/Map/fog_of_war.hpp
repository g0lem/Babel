#pragma once
class fog_of_war
{
	float **s_map;
	Sprite *m_sprite;
	void Advance(GameObject *g_obj);

public:
	void Init(GameObject *g_obj);
	float **GetFOW(GameObject *g_obj, glm::ivec2 position);
	void Render(Controller * ctrl, ScreenUniformData * u_data, glm::vec2 position, GameObject *g_obj);
};

