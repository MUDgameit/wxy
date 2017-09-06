#ifndef EQUIPMENT_H_INCLUDED
#define EQUIPMENT_H_INCLUDED

#include <string>
#include "Article.h"
using namespace std;

class Equipment :public Article{
public:
    Equipment(string my_name);
    string getName();
    int getCategory();
    double getDefense();
    double getAvoidRate();
    double getLife();
    void setEquipment(bool status);
	void showInformation();
private:
    string name; // ����
    int category; // ����Ϊ1���ؼ�Ϊ2������Ϊ3
    double defense; // ����
    double avoid_rate; // �ر���
    double life; // ����
    bool has_equip; // �Ƿ�װ��
};



#endif // EQUIPMENT_H_INCLUDED
