//Checked 1




#ifndef MAP_HPP
#define MAP_HPP



class Map
{





public:



	void Render(Controller * ctrl, ScreenUniformData * u_data, GameObject * g_obj, glm::vec2 position);



	void Init(GameObject *g_obj);


	void TransformAndApplyRoomToTileMap(Room * room, Tilemap * tilemap, GLuint transform_flag);



	inline Tilemap * GetTilemap(){ return this->tilemap; }



	inline 	std::vector<Room*>* GetRoomsPointer(){ return this->rooms; }



private:



	Graph * m_graph;
    

	Tilemap *tilemap;


	Sprite * m_sprite;

	fog_of_war *fog;


	GLuint expected_rooms;


	std::vector<Room*>*rooms;


	void LoadSprites();


	void GenerateContent(GameObject *g_obj);


	void AddTunnel(glm::ivec2 point_a, glm::ivec2 point_b);

	void AddTablets();

	void AddPotions();

	void FirstTunnelPass();


	void SecondTunnelPass();


	void AddRooms(GLuint expected_rooms);


	void AddDoors();



};

#endif