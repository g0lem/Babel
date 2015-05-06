#include <common.hpp>




std::vector <glm::vec2> Pathfinder::GetPath()
{
	std::vector <glm::vec2> path;
	node *get=Ending;

	while (get != NULL)
	{
		path.push_back(glm::vec2(get->x * this->scale, get->y * this->scale));
		get = get->last;
	}


	std::reverse(path.begin(), path.end());
	return path;
}



void Pathfinder::Delete()
{




	for (int i = 0; i < openlist.size(); i++)
		delete openlist[i];
	openlist.clear();

	for (int i = 0; i < visitedlist.size(); i++)
		delete  visitedlist[i];
	visitedlist.clear();





}



void Pathfinder::Init(GameObject *g_obj, glm::vec2 start, glm::vec2 finish, int pathfinder_type)
{
	this->scale = 1;
	if (pathfinder_type == PATH_WITH_DOORS)
	{
		this->map = g_obj->GetCollisionMap()->GetTiles();
	}
	else if (pathfinder_type == PATH_PLAYER)
	{
		this->map = g_obj->GetCollisionMap()->GetPlayerTiles();
	}



	this->g_obj = g_obj;


	searchstart = false;

	this->Delete();
	this->PathFound = false;




	Ending = new node;
	Beginning = new node;
	Ending->x = finish.x;
	Ending->y = finish.y;
	Ending->H = 0;

	Beginning->x = start.x;
	Beginning->y = start.y;
	Beginning->last = NULL;
	Beginning->G = 0;
	Beginning->H = GetDistance(Ending);
	Beginning->F = Beginning->G + Beginning->H; 



	openlist.push_back(Beginning);



	node *current;

	current = FindBestNode();

	while (PathFound == false && neighbours(current) == true)
	{
		if (openlist.size() != 0)
		FindNewNode(current);
		if (searchstart == false)
		{
			FindNewNode(current);
			searchstart = true;
		}
		if (!PathFound)
		current = FindBestNode();


		if (openlist.size()==0)
		{
			FindNewNode(current);
			if (openlist.size() == 0)
			break;
		}

	}




}

bool Pathfinder::neighbours(node *currentnode)
{

	int newx, newy;
	int dx[4] = { -1, 0, 0, 1 };
	int dy[4] = { 0, 1, -1, 0 };



	for (int k = 0; k < 4; k++)
	{

		newx = dx[k] + currentnode->x;
		newy = dy[k] + currentnode->y;

		if (newx>=0 && newy>=0 && newx<48 && newy<48)
		if (map[newx][newy] == 0)
			return true;


	}
	return false;
}

void Pathfinder::Init(GameObject *g_obj, glm::vec2 start, glm::vec2 finish, int pathfinder_type, int scale)
{
	this->scale = scale;

	if (pathfinder_type == PATH_WITH_DOORS)
	{
		
		this->b_map = g_obj->GetCollisionMap()->GetTiles();
	}
	else if (pathfinder_type == PATH_PLAYER)
	{
		this->b_map = g_obj->GetCollisionMap()->GetPlayerTiles();
	}

	this->map_size = g_obj->GetCollisionMap()->GetSize();


	AdaptMap();


	this->g_obj = g_obj;


	searchstart = false;

	this->Delete();
	this->PathFound = false;




	Ending = new node;
	Beginning = new node;
	Ending->x = finish.x/this->scale;
	Ending->y = finish.y / this->scale;
	Ending->H = 0;

	Beginning->x = start.x / this->scale;
	Beginning->y = start.y / this->scale;
	Beginning->last = NULL;
	Beginning->G = 0;
	Beginning->H = GetDistance(Ending);
	Beginning->F = Beginning->G + Beginning->H;



	openlist.push_back(Beginning);



	node *current;

	current = FindBestNode();

	while (PathFound == false && neighbours(current) == true)
	{
		if (openlist.size() != 0)
			FindNewNode(current);
		if (searchstart == false)
		{
			FindNewNode(current);
			searchstart = true;
		}
		if (!PathFound)
			current = FindBestNode();


		if (openlist.size() == 0)
		{
			FindNewNode(current);
			if (openlist.size() == 0)
				break;
		}

	}




}
void Pathfinder::AdaptMap()
{
	bool ok;

	
	this->map = new GLboolean*[int(this->map_size.x / this->scale)];
	std::cout << "Intrat";
	for (int i = 0; i < int(this->map_size.x / this->scale); i++)
	{
		this->map[i] = new GLboolean[int(this->map_size.y / this->scale)];
	}

	for (int i = 0; i < int(this->map_size.x); i += this->scale)
		for (int j = 0; j <int(this->map_size.y); j += this->scale)
		{
		ok = true;
		for (int k = 0; k < this->scale; k++)
			for (int l = 0; l < this->scale;l++)
				if (b_map[i+k][j+l] == true)
				{
			//std::cout << "DA";
			        map[i/scale][j/scale] = true;
					ok = false;
				}
		if (ok == true)
		{
			map[i / scale][j / scale] = false;
		}


		}

	

}




bool Pathfinder::IsVisited(int x, int y)
{
	for (int i = 0; i < visitedlist.size(); i++)
	{
		if (visitedlist[i]->x == x && visitedlist[i]->y == y)
			return true;
	}
	return false;

}

bool Pathfinder::IsOpened(int x, int y)
{
	for (int i = 0; i < openlist.size(); i++)
	{
		if (openlist[i]->x == x && openlist[i]->y == y)
			return true;
	}
	return false;
}


void Pathfinder::FindNewNode(node *currentnode)
{


	if (currentnode->x == Ending->x && currentnode->y == Ending->y)
	{
		PathFound = true;
		Ending->last = currentnode->last;
		return;
	}



	int newx, newy;
	int dx[4] = { -1, 0, 0, 1 };
	int dy[4] = { 0, 1, -1, 0 };



	for (int k = 0; k < 4; k++)
	{

		newx = dx[k] + currentnode->x;
		newy = dy[k] + currentnode->y;



		GLboolean ok = map[newx][newy] == 0 && IsVisited(newx, newy) == false && IsOpened(newx, newy) == false;
		if (ok)
		{
			for (GLuint i = 0; i < this->g_obj->GetCollisionMap()->GetList().size(); i++)
				if (glm::ivec2(newx, newy) == this->g_obj->GetCollisionMap()->GetList()[i])
				{
				ok = false;
				break;
				}
			
		}


		if (ok)
		{


			node *nextnode = new node;
			nextnode->last = currentnode;
			nextnode->x = newx;
			nextnode->y = newy;


			nextnode->H = GetDistance(nextnode);


			if (k < 4)
				nextnode->G = currentnode->G + 1.41;
			else
				nextnode->G = currentnode->G + 1;


			nextnode->F = nextnode->G + nextnode->H;
			openlist.push_back(nextnode);


		}

	}


}


Pathfinder::node *Pathfinder::FindBestNode()
{

	if (openlist.size() > 0)
	{
		node *best = openlist[0];
		GLfloat minimum_F = best->F;
		int pozition = 0;


		for (int i = 1; i < openlist.size(); i++)
		{


			if (openlist[i]->F < minimum_F)
			{
				best = openlist[i];
				minimum_F = openlist[i]->F;
				pozition = i;
			}


		}



		visitedlist.push_back(best);
		openlist.erase(openlist.begin() + pozition);


		return best;

	}
	
}

