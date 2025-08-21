#include "Magician.h"
#include <iostream>
using namespace std;


Magician::Magician(string nickname) : Player(nickname)
{
	job_name = "마법사";
	cout << "* 마법사로 전직하였습니다." << endl;
	level = 10;
	HP = 100;
	MP = 120;
	power = 50;
	defence = 50;
	accuracy = 50;
	speed = 50;
}



void Magician::attack()
{
	cout << "마법사가 마법을 사용했습니다. " << endl;
}