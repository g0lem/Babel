//Checked 1




#ifndef MAP_HPP
#define MAP_HPP



class Map
{

	

	


public:

	struct Wall
	{
		glm::vec2 position;
		int type;
		Wall(glm::vec2 position, int type){ this->position = position; this->type = type; }
	};


	void Render(Controller * ctrl, ScreenUniformData * u_data, GameObject * g_obj, glm::vec2 position);
	void Render(Controller * ctrl, ScreenUniformData * u_data, Sprite * m_sprite,
		glm::ivec2 begin_limit, glm::ivec2 end_limit,
		glm::vec2 offset, GLuint texture, float ** fog, ItemList *item_list);

	void InitBoss(GameObject *g_obj);
	void Init(GameObject *g_obj);


	void TransformAndApplyRoomToTileMap(Room * room, Tilemap * tilemap, GLuint transform_flag);

	void ComplexDecoration();

	void AddScrolls(GameObject *g_obj);
	inline Tilemap * GetTilemap(){ return this->tilemap; }

	inline fog_of_war *GetFogofWar(){ return this->fog; }

	inline 	std::vector<Room*>* GetRoomsPointer(){ return this->rooms; }

	

private:

	std::vector<Wall*> wall_list;

	Graph * m_graph;
    
	int ***wall_score;


	Tilemap *tilemap;


	Sprite * m_sprite;
	Sprite * m_walls;

	fog_of_war *fog;


	GLuint expected_rooms;


	std::vector<Room*>*rooms;


	void LoadSprites();


	void GenerateContent(GameObject *g_obj);
	
	void GenerateBossRoom(GameObject *g_obj);

	void GenerateScore();
	
	void BossSprites();

	void AddTunnel(glm::ivec2 point_a, glm::ivec2 point_b);

	void AddTablets(GameObject *g_obj);

	void AddStairs(GameObject *g_obj);

	void AddChests(GameObject *g_obj);

	void AddLevers(GameObject *g_obj);

	void Decorate(GameObject *g_obj);

	void AddPotions();

	void FirstTunnelPass();


	void SecondTunnelPass();


	void AddRooms(GLuint expected_rooms);
	void AddBossRoom();

	void AddDoors();




};

#endif