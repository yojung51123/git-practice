#include "warrior.h"
#include <iostream>
using namespace std;


Warrior::Warrior(string nickname) : Player(nickname)
{
	job_name = "����";
	cout << "* ����� �����Ͽ����ϴ�." << endl;
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
	cout << "���簡 ���� �ֵѷ����ϴ�. " << endl;
}