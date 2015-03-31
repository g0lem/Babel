#include "random_item_generation.hpp"



void RIG::Init()
{

	std::ifstream f("date.txt");
	names *name = new names;
	while (f >> name->prefix >> name->type >> name->sufix)
	{
		namelist.push_back(name);
		name = new names;
	}


}

