#pragma once
#include"layer.h"
#include"monster.h"
#include"task.h"
#include"fighting.h"
#include"character.h"
class DemonShrine : public layer {
public:
	DemonShrine(string, task *, Character *);
	~DemonShrine();
	void judgeTask();
	//�ƶ�
	void move(int);
	void operate(Character *);
private:
	//С��ͼ
	string smalllayer[7];
	string smalllayerintroduction[7];
	//����
	string monstername[6];
	task * point;
	bool ifFinishTask;
};