#include <iostream>
using namespace std;


void setPotion(int count, int* p_HPPotion, int* p_MPPotion) // 함수
{
	*p_HPPotion = count;
	*p_MPPotion = count;
}


int main()
{
	int Player = 0; // 메뉴선택
	int Select = 0; // hp,mp 입력
	int Status[4] = { 'HP' , 'MP' , 'ATK' ,'DEF' }; // 능력치
	int HPPotion = 0; // hp포션
	int MPPotion = 0; // mp포션

	setPotion(5, &HPPotion, &MPPotion);


	
	while (Select <= 50) // HP,MP 입력
	{
		cout << "HP와 MP를 입력 해주세요: " << endl;
		cin >> Status[0] >> Status[1];
		Select = (Status[0] + Status[1]) / 2;
		if (Status[0] <= 50)
		{
			cout << "숫자가 너무 작습니다 다시 입력해주세요" << endl;
		}
		else if (Status[1] <= 50)
		{
			cout << "숫자가 너무 작습니다. 다시입력해주세요." << endl;
		}

	}

	

	cout << "공격력과 방어력을 입력 해주세요: " << endl;
	cin >> Status[2] >> Status[3];


	cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)" << endl;

	while (Player != 7) // 7이 아닐때 실행
	{

		cout << "===================" << endl;//메뉴
		cout << "<스탯 관리 시스템>" << endl;
		cout << "1. HP 회복" << endl;
		cout << "2. MP 회복" << endl;
		cout << "3. HP 강화" << endl;
		cout << "4. MP 강화" << endl;
		cout << "5. 공격 스킬 사용" << endl;
		cout << "6. 필살기 사용" << endl;
		cout << "7. 게임 종료" << endl;
		cout << "===================" << endl;

		cout << "번호를 선택해주세요: " << endl;
		cin >> Player;


		// 실행할 번호 조건
		if (Player == 1) // hp회복
		{
			if (HPPotion > 0)
			{
				Status[0] = Status[0] + 20;
				HPPotion = HPPotion - 1;
				cout << "* HP가 20 회복되었습니다. 포션이 1개 차감됩니다. *" << endl;
				cout << "현재 HP: " << Status[0] << endl; 
				cout << "남은 포션 수: " << HPPotion << endl; 
				cout << "번호를 선택 해주세요: " << endl;
			}
			else
			{
				cout << "포션이 부족합니다." << endl;
			}
		}
		else if (Player == 2) // mp 회복
		{
			if (MPPotion > 0)
			{
				Status[1] = Status[1] + 20;
				MPPotion = MPPotion - 1;
				cout << "* MP가 20 회복 되었습니다. 포션이 1개 차감됩니다. *" << endl;
				cout << "현재 MP : " << Status[1] << endl;
				cout << "남은 포션 수: " << MPPotion << endl;
				cout << "번호를 선택 해주세요: " << endl;
			}
			else
			{
				cout << "포션이 부족합니다." << endl;
			}
		}
		else if (Player == 3) // hp강화
		{
			if (HPPotion > 0)
			{
				Status[0] = Status[0] * 2;
				HPPotion = HPPotion - 1;
				cout << "* HP가 2배로 증가 되었습니다. *" << endl;
				cout << "현재 HP: " << Status[0] << endl;
				cout << "남은 포션 수: " << HPPotion << endl;
				cout << "번호를 선택 해주세요: " << endl;
			}
			else
			{
				cout << "포션이 부족합니다." << endl;
			}
		}
		else if (Player == 4) // mp강화
		{
			if (MPPotion > 0)
			{
				Status[1] = Status[1] * 2;
				MPPotion = MPPotion - 1;
				cout << "* MP가 2배로 증가 되었습니다. *" << endl;
				cout << "현재 MP: " << Status[1] << endl;
				cout << "남은 포션수: " << MPPotion << endl;
				cout << "번호를 선택 해주세요: " << endl;
			}
			else
			{
				cout << "포션이 부족합니다." << endl;
			}
		}
		else if (Player == 5) // 공격스킬 사용
		{
			if (Status[1] >= 50)
			{
				Status[1] = Status[1] - 50; // MP가 0 이하로 안떨어지게
				cout << "* 스킬을 사용하여 MP가 50 소모되었습니다. *" << endl;
				cout << "현재 MP: " << Status[1] << endl;
				cout << "남은 포션수: " << MPPotion << endl;
				cout << "번호를 선택 해주세요: " << endl;
			}
			else
			{
				cout << "스킬사용이 불가 합니다" << endl;
			}
		}
		else if (Player == 6) // 필살기 사용
		{
			
			if (Status[1] > 0)
			{
				Status[1] = Status[1] - (Status[1] / 2); // MP 0 이하 X
				cout << "* 필살기를 사용하여 MP가 50% 소모되었습니다. *" << endl;
				cout << "현재 MP: " << Status[1] << endl;
				cout << "남은 포션수: " << MPPotion << endl;
				cout << "번호를 선택 해주세요: " << endl;
			}
			else
			{
				cout << "스킬 사용이 불가합니다." << endl;
			}
		}
		else if (Player == 7) // 게임종료
		{
			cout << " 게임을 종료 합니다." << endl;
			return 0;
		}
		else
		{
			cout << "숫자를 잘못 입력했습니다. 다시 입력해주세요!";

		}

	}

};