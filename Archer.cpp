#include "Archer.h"
#include <iostream>
using namespace std;


Archer::Archer(string nickname) : Player(nickname)
{
	job_name = "궁수";
	cout << "* 궁수로 전직하였습니다." << endl;
	level = 10;
	HP = 100;
	MP = 50;
	power = 50;
	defence = 50;
	accuracy = 90;
	speed = 50;
}



void Archer::attack()
{
	cout << "궁수가 화살을 발사했습니다. " << endl;
}