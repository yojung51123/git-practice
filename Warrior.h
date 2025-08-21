#pragma once
#include "player.h"

class Warrior : public Player
{
public:
    
	Warrior(string nickname);
   
	void attack() override; 
};

	
