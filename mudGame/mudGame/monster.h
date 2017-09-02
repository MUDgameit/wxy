#pragma once
#include<string>
using namespace std;
class monster {
public:
	monster();
	int fighting();
	int defense(int hurt, int probability);
	string fall();
	string returnSkill();
	string returnName();
	string returnName();
	int returnLife();
	int getAttackSpeed();
private:
	string name;
	int life;
	int power;
	int defenses;
	string article;
	int probability;
	string skill;
	int damage[5];
};