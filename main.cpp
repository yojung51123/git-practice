
#include <iostream>
#include "player.h"
#include "warrior.h"
#include "magician.h"
#include "thief.h"
#include "archer.h"

//��ǥ : �÷��̾ ������ �����ϰ� ������ �����Ҷ����� �ڵ����� �����Լ��� ���;���
// 1. ������ ���� -> Player.h �� ������Ƽ�� �� ���� ����
// 2. �Լ��� ���� ���� 
// �⺻ ���� ������ ������ 
// ���� : hp 150 , mp 50 , power 50, ��� 50 , ���ǵ� 50
// �ü� : hp 120 , mp 80 , power 20, ��� 20, ���ǵ� 80
// ���� : hp 90 , mp 80, power 30 , ��� 10, ���ǵ� 100
// ������ : hp 100, mp 150, power 30, ��� 20, ���ǵ� 70
// ���� �Լ�
int main()
{
    /*public: // �÷��̾� ������ ���� 1 HP,MP,����,���,���ǵ� 10
    Player(string n, string j, int l, int h, int m, int p, int d, int a, int s)
        : nickname(n), job_name(j), level(l), HP(h), MP(m), power(p), defence(d), accuracy(a), speed(s) {}*/

    string jobs[] = { "����", "������", "����", "�ü�" };
    int job_choice = 0; // 0���� ���� �ʱ�ȭ
    string nickname; // �г��� ����

    Player* player = nullptr;

    cout << "* �г����� �Է����ּ���: ";
    cin >> nickname; // �г��� ����


    cout << "<���� �ý���>" << endl;
    cout << nickname << "��, ȯ���մϴ�!" << endl;
    cout << "* ���Ͻô� ������ �������ּ���." << endl;

    for (int i = 0; i < 4; i++) {
        cout << (i + 1) << ". " << jobs[i] << endl; // i + 1 ?, job�迭�� �ִ� ���� ���õ�
    }

    cout << "����: ";
    cin >> job_choice; // job ���̽��� �Է°� ����

    switch (job_choice) {
    case 1:
        player = new Warrior(nickname); // 1 ����
        break;
    case 2:
        player = new Magician(nickname); // 2 ������
        break;
    case 3:
        player = new Thief(nickname); // 3 ����
        break;
    case 4:
        player = new Archer(nickname); // 4 �ü�
        break;
    default:
        cout << "�߸��� �Է��Դϴ�." << endl; // �׿� ��ȣ�� �Է�������
        return 1; // ���� 1�� �ǵ����� ?
    }

    player->attack(); // Player.h �� �ִ� ���� �����Լ��� ȣ���Ѵ�
    player->printPlayerStatus(); // Player.cpp ���ִ� �������ͽ� â�� ȣ���Ѵ�



    delete player; // �޸𸮸� ����ش�

    return 0; // ��
}