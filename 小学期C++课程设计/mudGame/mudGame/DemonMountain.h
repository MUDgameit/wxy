#pragma once
#include"layer.h"
#include"task.h"
class DemonMountain : public layer {
public:
	DemonMountain(string, task *);
	~DemonMountain();
	void judgeTask();
	//�ƶ�
	void move(int);
private:
	//С��ͼ
	string smalllayer[6];
	string smalllayerintroduction[7];
	//����
	string monstername[6];
	task * point;
	bool ifFinishTask;
};