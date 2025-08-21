#pragma once
#include "player.h"

class Thief : public Player
{
public:

	Thief(string nickname);

	void attack() override;
};




