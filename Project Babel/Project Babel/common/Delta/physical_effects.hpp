#pragma once

class PhysiscalEffects
{
public:
	bool freeze;
	bool bleed;
	bool poisoned;
	inline PhysiscalEffects()
	{
		freeze = false;
		bleed = false;
		poisoned = false;
	}
};