#include "Thief.h"
#include <iostream>
using namespace std;


Thief::Thief(string nickname) : Player(nickname)
{
	job_name = "����";
	cout << "* �������� �����Ͽ����ϴ�." << endl;
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
	cout << "������ �������� �������ϴ�. " << endl;
}