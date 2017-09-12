#include"monster.h"
#include<iostream>
#include <fstream>
#include<time.h>
using namespace std;
Monster::Monster(string name,string skillName,string fall) {//���ļ�����Ϣ
	string textline[100];
	article = fall;
	int i = 0, j = 0;
	ifstream fin("monster.txt");
	while (!fin.eof())
	{
		getline(fin, textline[i], '\n');
		i++;
	}
	fin.close();
	double data[5];
	char str[100];
	const char * split = ",";
	char * p;
	int k = 0;
	for (j = 0; j < i; j++) {
		if (textline[j].find(name) != string::npos) {
			strcpy(str, textline[j].c_str());
			p = strtok(str, split);
			while (p + 1 != NULL && k < 5) {
				data[k] = atof(strtok(NULL, split));
				k++;
			}
		}
	}
	this->name = name;
	life = data[0];//����
	power = data[1];
	defenses = data[2];
	skill = str;
	speed = data[3];
	probabilityFall = data[4];
	life = 100;
}


int Monster::fighting() {//���ع���ֵ
	return power;
}
int Monster::defense(int hurt, int probability) {//�����ܵ����˺�ֵ
	srand(time(NULL));
	if (1 == rand() % probability)
		return (hurt - 100 + defenses / 100);
	else
		return 0;
}
string Monster::fall() {//���ص�����Ʒ
	srand(time(NULL));
	int probality = rand() % 100 + 1;
	if (probality < probabilityFall)
	{
		return article;
	}
	else
		return "";
}
string Monster::returnSkill() {//���ع��＼������
	return skill;
}
string Monster::returnName() {//���ع�������
	return name;
}
int Monster::returnLife() {//���ع�������ֵ
	return life;
}
int Monster::getAttackSpeed() {
	return speed;
}

