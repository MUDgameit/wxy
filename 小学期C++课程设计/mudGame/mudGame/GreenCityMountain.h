#pragma once
#include"layer.h"
#include"task.h"
class GreenCityMountain : public layer {
public:
	GreenCityMountain(string, task *);
	~GreenCityMountain();
	void judgeTask();
	//�ƶ�
	void move(int);
private:
	//С��ͼ
	string smalllayer[5];
	string smalllayerintroduction[4];
	//����
	string monstername[3];
	task * point;
	bool ifFinishTask;
};