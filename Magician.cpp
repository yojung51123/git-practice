#include "Magician.h"
#include <iostream>
using namespace std;


Magician::Magician(string nickname) : Player(nickname)
{
	job_name = "������";
	cout << "* ������� �����Ͽ����ϴ�." << endl;
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
	cout << "�����簡 ������ ����߽��ϴ�. " << endl;
}