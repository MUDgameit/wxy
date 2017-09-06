#ifndef WEAPON_H_INCLUDED
#define WEAPON_H_INCLUDED

#include <string>
#include "Article.h"
using namespace std;

class Weapon : public Article{
public:
    Weapon(string my_name);
    string getName();
	double getLife() { return 0; }
    double getStrength();
    double getHitRate();
    double getDefense();
    double getAvoidRate();
    double getForceRate();
    double getAttackSpeed();
    int judgeDistance(); // �ж��Ƿ�ΪԶ������
    void setEquipment(bool status);
	void showInformation();
private:
    string name; // ����
    double strength; // ����
    double hit_rate; // ������
    double defense; // ������
    double avoid_rate; // �ر���
    double force_rate; // ������
    double attack_speed; // �����ٶ�
    int is_distance; // �Ƿ�ΪԶ������
    bool has_equip; // �Ƿ�װ��
};


#endif // WEAPON_H_INCLUDED
