#pragma once
#include"layer.h"
#include"monster.h"
#include"task.h"
#include"fighting.h"
#include"character.h"
class SkyMountain : public layer {
public:
	SkyMountain(string,task *,Character *);
	~SkyMountain();
	void judgeTask();
	//�ƶ�
	void move(int);
	void operate(Character *);
private:
	//С��ͼ
	string smalllayer[4];
	string smalllayerintroduction[5];
	//����
	string monstername[4];
	task * point;
	bool ifFinishTask;
};