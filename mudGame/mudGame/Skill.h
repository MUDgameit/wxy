#pragma once
#include<iostream>
#include<string>
using namespace std;
class Skill {
private:
	string skill[10];
	int flag[10];
	int damage[10];
	int consumption[10];
public:
	Skill();
	void LearnSkill(string name);
	int UseSkill(int name, int force);
	int getSkilldamage(int i);
	int getSkillconsumption(int k);
};