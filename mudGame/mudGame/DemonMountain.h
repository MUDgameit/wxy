#pragma once
#include"layer.h"
#include"monster.h"
#include"task.h"
#include"fighting.h"
#include"character.h"
class DemonMountain : public layer {
public:
	DemonMountain(string, task *, Character *);
	~DemonMountain();
	void judgeTask();
	//�ƶ�
	void move(int);
	void operate(Character *);
private:
	//С��ͼ
	string smalllayer[6];
	string smalllayerintroduction[7];
	//����
	string monstername[6];
	task * point;
	bool ifFinishTask;
};