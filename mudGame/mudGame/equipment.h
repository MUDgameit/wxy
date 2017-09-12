#ifndef EQUIPMENT_H_INCLUDED
#define EQUIPMENT_H_INCLUDED

#include <string>
#include "Article.h"
using namespace std;

class Equipment :public Article{
public:
    Equipment(string my_name);
    string getName();
	double  getStrength() { return 0; }
	double getHitRate() { return 0; }
	double getForceRate() { return 0; }
	double getAttackSpeed() { return 0; }
    int getCategory();
    double getDefense();
    double getAvoidRate();
    double getLife();
    void setEquipment(bool status);
	bool getHas_Equip();
	void showInformation();
private:
    string name; // ����
    int category; // ����Ϊ1���ؼ�Ϊ2������Ϊ3������Ϊ4
    double defense; // ����
    double avoid_rate; // �ر���
    double life; // ����
    bool has_equip; // �Ƿ�װ��
};



#endif // EQUIPMENT_H_INCLUDED
