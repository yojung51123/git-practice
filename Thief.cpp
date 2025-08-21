#include "Thief.h"
#include <iostream>
using namespace std;


Thief::Thief(string nickname) : Player(nickname)
{
	job_name = "도적";
	cout << "* 도적으로 전직하였습니다." << endl;
	level = 10;
	HP = 100;
	MP = 50;
	power = 50;
	defence = 50;
	accuracy = 50;
	speed = 100;
}



void Thief::attack()
{
	cout << "도적이 수리검을 던졌습니다. " << endl;
}