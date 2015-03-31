#pragma once



class Xp
{



public:
	float xp, max_xp;

	inline Xp(){ this->Init(); }

	inline void Init(){ this->xp = 0; this->max_xp = 0; }

	inline void Increase(float xp){ this->xp += xp; }

	inline void Decrease(float xp){ this->xp -= xp; }
};

