#include "Player.h"

    void Player::printPlayerStatus()
    {
        cout << "------------------------------------" << endl;
        cout << "* ���� �ɷ�ġ" << endl;
        cout << "�г���: " << nickname << endl;
        cout << "Lv. " << level << endl;
        cout << "HP: " << HP << endl;
        cout << "MP: " << MP << endl;
        cout << "���ݷ�: " << power << endl;
        cout << "����: " << defence << endl;
        cout << "��Ȯ��: " << accuracy << endl;
        cout << "�ӵ�: " << speed << endl;
        cout << "------------------------------------" << endl;
    }

