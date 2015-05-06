#ifndef COLLISION_MAP_HPP
#define COLLISION_MAP_HPP


class CollisionMap
{



	glm::ivec2 size;
	GLboolean **tiles;
	GLboolean **player_tiles;
	GLboolean **visible_tiles;
	GLboolean **poland;

	std::vector<glm::ivec2>list;


public:


	inline CollisionMap(){ this->Init(); }
	void Init();


	void CreateOutOfMap(Tilemap * map);
	void AddSolid(glm::vec2 position);

	inline void ResetList(){ this->list.clear(); }
	inline std::vector<glm::ivec2> GetList(){ return this->list; }
	inline void AddToList(glm::ivec2 position){ this->list.push_back(position); }


	inline glm::ivec2 GetSize(){ return this->size; }
	inline GLboolean **GetTiles(){ return this->tiles; }
	inline GLboolean **GetPlayerTiles(){ return this->player_tiles; }
	inline GLboolean **GetVisibleTiles(){ return this->visible_tiles; }
	inline GLboolean **AcquirePoland(){ return this->poland; }
};

#endif