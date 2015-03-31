#ifndef RANDOM_ITEM_GENERATION_HPP
#define RANDOM_ITEM_GENERATION_HPP
#include <fstream>
#include <vector>
#include <math.h>
#include <time.h>
#include <string.h>
#include "common\Framework\Math\dice.hpp"

class RIG
{

	struct names
	{
		char type[256], sufix[256], prefix[256];
	};

	std::vector <names*> namelist;
	
	
	public:
		void Init();

	names *RandomItem()
	{
		int random;
		names *name = new names;



		strcpy_s(name->type, 256, namelist[Dice::Get(0, namelist.size(), namelist.size())]->type);


		do
		{
			random = Dice::Get(0, namelist.size(),namelist.size());
			strcpy_s(name->prefix, 256, namelist[random]->prefix);

		} while (strcmp(name->type, namelist[random]->type) != 0);



		do
		{
			random = random = Dice::Get(0, namelist.size(), namelist.size());
			strcpy_s(name->sufix, 256, namelist[random]->sufix);

		} while (strcmp(name->type, namelist[random]->type) != 0);

		return name;
	}


	names *RandomItem(char *item_name)
	{
		int random;
		RIG::names *name = new RIG::names;



		strcpy_s(name->type, 256, item_name);


		do
		{
			random = Dice::Get(0, namelist.size(), namelist.size());
			strcpy_s(name->prefix, 256, namelist[random]->prefix);

		} while (strcmp(name->type, namelist[random]->type) != 0);



		do
		{
			random = Dice::Get(0, namelist.size(), namelist.size());
			strcpy_s(name->sufix, 256, namelist[random]->sufix);

		} while (strcmp(name->type, namelist[random]->type) != 0);

		return name;
	}



};

#endif