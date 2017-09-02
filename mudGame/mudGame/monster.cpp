#include"monster.h"
#include<iostream>
#include <fstream>
#include<time.h>
using namespace std;
class monster {
public:
	monster(string name) {//���ļ�����Ϣ
		string textline[100];
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
				while (p != NULL && k < 5) {
					data[k] = atof(strtok(NULL, split));
					k++;
				}
			}
		}
		this->name = name;
		this->life = data[0];
		this->power = data[1];
		this->defenses = data[2];
		this->skill = str;
		this->speed = data[3];
		this->probabilityFall = data[4];
	}
	int fighting() {//���ع���ֵ
		return power;
	}
	int defense(int hurt, int probability) {//�����ܵ����˺�ֵ
		srand(time(NULL));
		if (1 == rand() % probability)
			return (hurt - 100 + defenses / 100);
		else
			return 0;
	}
	string fall() {//���ص�����Ʒ
		srand(time(NULL));
		if (1 == rand() % probabilityFall)
		{
			return article;
		}
		else
			return "";
	}
	string returnSkill() {//���ع��＼������
		return skill;
	}
	string returnName() {//���ع�������
		return name;
	}
	int returnLife() {//���ع�������ֵ
		return life;
	}
	int getAttackSpeed() {
		return speed;
	}
private:
	string name;
	int life;
	int power;
	int defenses;
	string article;
	int probabilityFall;
	string skill;
	int damage[5];
	int speed;
};