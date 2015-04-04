//Checked 1




#include <common.hpp>


void Move::TileMove(Controller* ctrl, GameObject * g_obj, glm::vec2 &position)
{




	



	if ((ctrl->GetKeyOnce(GLFW_KEY_W) || ctrl->GetKeyOnce(GLFW_KEY_UP)) && position.y > 0)
	{


		GLboolean ok = true;

		for (GLuint i = 0; i < g_obj->GetCollisionMap()->GetList().size();i++)
			if (glm::ivec2(position.x, position.y - 1) == g_obj->GetCollisionMap()->GetList()[i])
			
			{
			ok = false;
			break;
			}
		if (ok && !g_obj->GetCollisionMap()->GetTiles()[GLuint(position.x)][GLuint(position.y - 1)])
			position.y--;



	}





	if ((ctrl->GetKeyOnce(GLFW_KEY_S) || ctrl->GetKeyOnce(GLFW_KEY_DOWN)) && position.y < glm::vec2(g_obj->GetCollisionMap()->GetSize()).y)
	{


	
		GLboolean ok = true;

		for (GLuint i = 0; i < g_obj->GetCollisionMap()->GetList().size(); i++)
			if (glm::ivec2(position.x, position.y + 1) == g_obj->GetCollisionMap()->GetList()[i])

			{
			ok = false;
			break;
			}
		if (ok && !g_obj->GetCollisionMap()->GetTiles()[GLuint(position.x)][GLuint(position.y + 1)])
			position.y++;




	}


	if ((ctrl->GetKeyOnce(GLFW_KEY_A) || ctrl->GetKeyOnce(GLFW_KEY_LEFT)) && position.x > 0)
	{




		GLboolean ok = true;

		for (GLuint i = 0; i < g_obj->GetCollisionMap()->GetList().size(); i++)
			if (glm::ivec2(position.x - 1, position.y) == g_obj->GetCollisionMap()->GetList()[i])

			{
			ok = false;
			break;
			}
		if (ok && !g_obj->GetCollisionMap()->GetTiles()[GLuint(position.x - 1)][GLuint(position.y)])
			position.x--;





	}



	if ((ctrl->GetKeyOnce(GLFW_KEY_D) || ctrl->GetKeyOnce(GLFW_KEY_RIGHT)) && position.x < glm::vec2(g_obj->GetCollisionMap()->GetSize()).x)
	{




		GLboolean ok = true;

		for (GLuint i = 0; i < g_obj->GetCollisionMap()->GetList().size(); i++)
			if (glm::ivec2(position.x + 1, position.y) == g_obj->GetCollisionMap()->GetList()[i])

			{
			ok = false;
			break;
			}
		if (ok && !g_obj->GetCollisionMap()->GetTiles()[GLuint(position.x + 1)][GLuint(position.y)])
			position.x++;




	}



}


void Move::UpdateScroller(Controller * ctrl, GameObject * g_obj, glm::vec2 position, glm::vec2 scale)
{

	glm::vec2 half_screen_vector = GridPosition(glm::vec2(ctrl->GetWindowWidth(), ctrl->GetWindowHeight()) / 2.0f, scale);


	g_obj->GetScroller()->SetOffset(half_screen_vector - position*scale);


}




glm::vec2 Move::GetMapPosition(GameObject * g_obj, glm::vec2 position, glm::vec2 scale)
{


	position = glm::ivec2(GridPosition(position, scale) / scale - (g_obj->GetScroller()->GetOffset()) / scale);


	if (position.x >= g_obj->GetCollisionMap()->GetSize().x)
		position.x = g_obj->GetCollisionMap()->GetSize().x - 1;
	if (position.y >= g_obj->GetCollisionMap()->GetSize().y)
		position.y = g_obj->GetCollisionMap()->GetSize().y - 1;
	if (position.x < 0)
		position.x = 0;
	if (position.y < 0)
		position.x = 0;


	return position;

}