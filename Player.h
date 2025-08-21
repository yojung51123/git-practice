#pragma once
#include <string>
#include <iostream>
using namespace std;

class Player // 기본 클래스
{
public: 
    Player(string nickname) :nickname(nickname) // 플레이어 생성자
    {
        level = 10;
        HP = 100;
        MP = 120;
        power = 50;
        defence = 50;
        accuracy = 50;
        speed = 50;
    }

    virtual ~Player() {}; // 소멸자

    virtual void attack() = 0; // 순수 가상함수
    void printPlayerStatus();

    // getter 함수
    string getJobName();
    string getNickname();
    int getLevel();
    int getHP();
    int getMP();
    int getPower();
    int getDefence();
    int getAccuracy();
    int getSpeed();

    // setter 함수

    void setNickname(string nickname);
    bool setHP(int HP);
    bool setMP(int MP);
    void setPower(int power);
    void setDefence(int defence);
    void setAccuracy(int accuracy);
    void setSpeed(int speed);



protected: 

    string job_name;
    string nickname;
    int level;
    int HP;
    int MP;
    int power;
    int defence;
    int accuracy;
    int speed;

  


};


