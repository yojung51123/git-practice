#include <iostream>
using namespace std;


void setPotion(int count, int* p_HPPotion, int* p_MPPotion) // �Լ�
{
	*p_HPPotion = count;
	*p_MPPotion = count;
}


int main()
{
	int Player = 0; // �޴�����
	int Select = 0; // hp,mp �Է�
	int Status[4] = { 'HP' , 'MP' , 'ATK' ,'DEF' }; // �ɷ�ġ
	int HPPotion = 0; // hp����
	int MPPotion = 0; // mp����

	setPotion(5, &HPPotion, &MPPotion);


	
	while (Select <= 50) // HP,MP �Է�
	{
		cout << "HP�� MP�� �Է� ���ּ���: " << endl;
		cin >> Status[0] >> Status[1];
		Select = (Status[0] + Status[1]) / 2;
		if (Status[0] <= 50)
		{
			cout << "���ڰ� �ʹ� �۽��ϴ� �ٽ� �Է����ּ���" << endl;
		}
		else if (Status[1] <= 50)
		{
			cout << "���ڰ� �ʹ� �۽��ϴ�. �ٽ��Է����ּ���." << endl;
		}

	}

	

	cout << "���ݷ°� ������ �Է� ���ּ���: " << endl;
	cin >> Status[2] >> Status[3];


	cout << "* ������ ���޵Ǿ����ϴ�. (HP, MP ���� �� 5��)" << endl;

	while (Player != 7) // 7�� �ƴҶ� ����
	{

		cout << "===================" << endl;//�޴�
		cout << "<���� ���� �ý���>" << endl;
		cout << "1. HP ȸ��" << endl;
		cout << "2. MP ȸ��" << endl;
		cout << "3. HP ��ȭ" << endl;
		cout << "4. MP ��ȭ" << endl;
		cout << "5. ���� ��ų ���" << endl;
		cout << "6. �ʻ�� ���" << endl;
		cout << "7. ���� ����" << endl;
		cout << "===================" << endl;

		cout << "��ȣ�� �������ּ���: " << endl;
		cin >> Player;


		// ������ ��ȣ ����
		if (Player == 1) // hpȸ��
		{
			if (HPPotion > 0)
			{
				Status[0] = Status[0] + 20;
				HPPotion = HPPotion - 1;
				cout << "* HP�� 20 ȸ���Ǿ����ϴ�. ������ 1�� �����˴ϴ�. *" << endl;
				cout << "���� HP: " << Status[0] << endl; 
				cout << "���� ���� ��: " << HPPotion << endl; 
				cout << "��ȣ�� ���� ���ּ���: " << endl;
			}
			else
			{
				cout << "������ �����մϴ�." << endl;
			}
		}
		else if (Player == 2) // mp ȸ��
		{
			if (MPPotion > 0)
			{
				Status[1] = Status[1] + 20;
				MPPotion = MPPotion - 1;
				cout << "* MP�� 20 ȸ�� �Ǿ����ϴ�. ������ 1�� �����˴ϴ�. *" << endl;
				cout << "���� MP : " << Status[1] << endl;
				cout << "���� ���� ��: " << MPPotion << endl;
				cout << "��ȣ�� ���� ���ּ���: " << endl;
			}
			else
			{
				cout << "������ �����մϴ�." << endl;
			}
		}
		else if (Player == 3) // hp��ȭ
		{
			if (HPPotion > 0)
			{
				Status[0] = Status[0] * 2;
				HPPotion = HPPotion - 1;
				cout << "* HP�� 2��� ���� �Ǿ����ϴ�. *" << endl;
				cout << "���� HP: " << Status[0] << endl;
				cout << "���� ���� ��: " << HPPotion << endl;
				cout << "��ȣ�� ���� ���ּ���: " << endl;
			}
			else
			{
				cout << "������ �����մϴ�." << endl;
			}
		}
		else if (Player == 4) // mp��ȭ
		{
			if (MPPotion > 0)
			{
				Status[1] = Status[1] * 2;
				MPPotion = MPPotion - 1;
				cout << "* MP�� 2��� ���� �Ǿ����ϴ�. *" << endl;
				cout << "���� MP: " << Status[1] << endl;
				cout << "���� ���Ǽ�: " << MPPotion << endl;
				cout << "��ȣ�� ���� ���ּ���: " << endl;
			}
			else
			{
				cout << "������ �����մϴ�." << endl;
			}
		}
		else if (Player == 5) // ���ݽ�ų ���
		{
			if (Status[1] >= 50)
			{
				Status[1] = Status[1] - 50; // MP�� 0 ���Ϸ� �ȶ�������
				cout << "* ��ų�� ����Ͽ� MP�� 50 �Ҹ�Ǿ����ϴ�. *" << endl;
				cout << "���� MP: " << Status[1] << endl;
				cout << "���� ���Ǽ�: " << MPPotion << endl;
				cout << "��ȣ�� ���� ���ּ���: " << endl;
			}
			else
			{
				cout << "��ų����� �Ұ� �մϴ�" << endl;
			}
		}
		else if (Player == 6) // �ʻ�� ���
		{
			
			if (Status[1] > 0)
			{
				Status[1] = Status[1] - (Status[1] / 2); // MP 0 ���� X
				cout << "* �ʻ�⸦ ����Ͽ� MP�� 50% �Ҹ�Ǿ����ϴ�. *" << endl;
				cout << "���� MP: " << Status[1] << endl;
				cout << "���� ���Ǽ�: " << MPPotion << endl;
				cout << "��ȣ�� ���� ���ּ���: " << endl;
			}
			else
			{
				cout << "��ų ����� �Ұ��մϴ�." << endl;
			}
		}
		else if (Player == 7) // ��������
		{
			cout << " ������ ���� �մϴ�." << endl;
			return 0;
		}
		else
		{
			cout << "���ڸ� �߸� �Է��߽��ϴ�. �ٽ� �Է����ּ���!";

		}

	}

};