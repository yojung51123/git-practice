#include "Archer.h"
#include <iostream>
using namespace std;


Archer::Archer(string nickname) : Player(nickname)
{
	job_name = "�ü�";
	cout << "* �ü��� �����Ͽ����ϴ�." << endl;
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
	cout << "�ü��� ȭ���� �߻��߽��ϴ�. " << endl;
}