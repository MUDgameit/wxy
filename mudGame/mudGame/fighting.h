#pragma once
#include<string>
#include<iostream>
#include"monster.h"
#include<cstdlib>
#include"character.h"
#include"Skill.h"
#include<ctime>
#include"task.h"
using namespace std;
class fighting {
public:
	fighting(Monster*, Character*, task*);
	bool judge();
	int firstRound();
	void fight(task*);//ս�����������ﾭ�������뷨���ָ�
private:
	int enemyslife;
	int mylife;
	int force = 100;
	int round;
	int probability;
	bool blooding;
	Monster*monster;
	Character*character;
	Skill*skill;
};
