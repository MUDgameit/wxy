#pragma once
#include"layer.h"
#include"monster.h"
#include"task.h"
#include"fighting.h"
#include"character.h"
class GreenCityMountain : public layer {
public:
	GreenCityMountain(string, task *, Character *);
	~GreenCityMountain();
	void judgeTask();
	//�ƶ�
	void move(int);
	void operate(Character *);
private:
	//С��ͼ
	string smalllayer[5];
	string smalllayerintroduction[4];
	//����
	string monstername[3];
	task * point;
	bool ifFinishTask;
};