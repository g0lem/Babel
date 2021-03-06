//Checked 1



#ifndef TILE_MAP_HPP
#define TILE_MAP_HPP









class Tilemap
{



	void GenerateTileMap();


	glm::vec2 tile_scale;

	glm::ivec2 size;


	GLint **tiles;

	Sprite *dark;
	


public:



	GLboolean boss_lvl;

	inline Sprite* GetDark(){ return this->dark; }//Get Metal, kids

	void SmootherFOW(float **fog, glm::ivec2 position, ScreenUniformData * u_data);

	void Init();

	void InitBoss();


	void GenerateBossRoom();

	void Render(Controller * ctrl, ScreenUniformData * u_data, Sprite * m_sprite,
		glm::ivec2 begin_limit, glm::ivec2 end_limit,
		glm::vec2 offset, GLuint texture, float ** fog, ItemList *item_list);


	inline glm::ivec2 GetSize(){ return this->size; }


	inline glm::vec2 GetTileScale(){ return this->tile_scale; }


	inline GLint**GetTiles(){ return this->tiles; }


};







#endif