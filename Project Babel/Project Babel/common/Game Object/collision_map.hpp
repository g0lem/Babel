#ifndef COLLISION_MAP_HPP
#define COLLISION_MAP_HPP


class CollisionMap
{



	glm::ivec2 size;
	GLboolean **tiles;


	std::vector<glm::ivec2>list;


public:


	inline CollisionMap(){ this->Init(); }
	void Init();


	void CreateOutOfMap(Tilemap * map);


	inline void ResetList(){ this->list.clear(); }
	inline std::vector<glm::ivec2> GetList(){ return this->list; }
	inline void AddToList(glm::ivec2 position){ this->list.push_back(position); }


	inline glm::ivec2 GetSize(){ return this->size; }
	inline GLboolean **GetTiles(){ return this->tiles; }


};

#endif