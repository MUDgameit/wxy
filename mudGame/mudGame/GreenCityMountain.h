#pragma once
#include"layer.h"
#include"task.h"
class GreenCityMountain : public layer {
public:
	GreenCityMountain(string, task *);
	~GreenCityMountain();
	void judgeTask();
	//移动
	void move(int);
private:
	//小地图
	string smalllayer[5];
	string smalllayerintroduction[4];
	//怪物
	string monstername[3];
	task * point;
	bool ifFinishTask;
};