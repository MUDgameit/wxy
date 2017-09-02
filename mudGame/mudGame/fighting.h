#pragma once
#include<string>
#include"monster.h"
#include"character.h"
using namespace std;
class fighting {
public:
	fighting();
	bool judge();
private:
	int enemyslife;
	int mylife;
	int force = 100;
	monster*monster;
	Character*character;
};