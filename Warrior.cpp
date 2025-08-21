#include "warrior.h"
#include <iostream>
using namespace std;


Warrior::Warrior(string nickname) : Player(nickname)
{
	job_name = "전사";
	cout << "* 전사로 전직하였습니다." << endl;
	level = 10;
	HP = 120;
	MP = 30;
	power = 50;
	defence = 50;
	accuracy = 50;
	speed = 50;
}



void Warrior::attack()
{
	cout << "전사가 검을 휘둘렀습니다. " << endl;
}