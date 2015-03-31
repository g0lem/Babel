//Checked 1



#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP








class Move
{


	


public:




	static void TileMove(Controller* ctrl, GameObject * g_obj, glm::vec2 &position);

	
	static void UpdateScroller(Controller * ctrl, GameObject * g_obj, glm::vec2 position, glm::vec2 scale);
	

	static glm::vec2 GetMapPosition(GameObject * g_obj, glm::vec2 position, glm::vec2 scale);




};

#endif