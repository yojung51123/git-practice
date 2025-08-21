
#include <iostream>
#include "player.h"
#include "warrior.h"
#include "magician.h"
#include "thief.h"
#include "archer.h"

//목표 : 플레이어가 직업을 선택하고 직업을 변경할때마다 자동으로 어택함수가 나와야함
// 1. 변수가 없음 -> Player.h 에 프로텍티드 로 변수 있음
// 2. 함수를 정의 하자 
// 기본 직업 스탯을 정하자 
// 전사 : hp 150 , mp 50 , power 50, 방어 50 , 스피드 50
// 궁수 : hp 120 , mp 80 , power 20, 방어 20, 스피드 80
// 도적 : hp 90 , mp 80, power 30 , 방어 10, 스피드 100
// 마법사 : hp 100, mp 150, power 30, 방어 20, 스피드 70
// 메인 함수
int main()
{
    /*public: // 플레이어 생성자 레벨 1 HP,MP,공격,방어,스피드 10
    Player(string n, string j, int l, int h, int m, int p, int d, int a, int s)
        : nickname(n), job_name(j), level(l), HP(h), MP(m), power(p), defence(d), accuracy(a), speed(s) {}*/

    string jobs[] = { "전사", "마법사", "도적", "궁수" };
    int job_choice = 0; // 0으로 변수 초기화
    string nickname; // 닉네임 변수

    Player* player = nullptr;

    cout << "* 닉네임을 입력해주세요: ";
    cin >> nickname; // 닉네임 저장


    cout << "<전직 시스템>" << endl;
    cout << nickname << "님, 환영합니다!" << endl;
    cout << "* 원하시는 직업을 선택해주세요." << endl;

    for (int i = 0; i < 4; i++) {
        cout << (i + 1) << ". " << jobs[i] << endl; // i + 1 ?, job배열에 있는 직업 선택됨
    }

    cout << "선택: ";
    cin >> job_choice; // job 초이스에 입력값 넣음

    switch (job_choice) {
    case 1:
        player = new Warrior(nickname); // 1 전사
        break;
    case 2:
        player = new Magician(nickname); // 2 마법사
        break;
    case 3:
        player = new Thief(nickname); // 3 도적
        break;
    case 4:
        player = new Archer(nickname); // 4 궁수
        break;
    default:
        cout << "잘못된 입력입니다." << endl; // 그외 번호를 입력했을때
        return 1; // 값을 1로 되돌린다 ?
    }

    player->attack(); // Player.h 에 있는 순수 가상함수를 호출한다
    player->printPlayerStatus(); // Player.cpp 에있는 스테이터스 창을 호출한다



    delete player; // 메모리를 비워준다

    return 0; // 끝
}