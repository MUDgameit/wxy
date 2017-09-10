#pragma once
#include"layer.h"
#include"task.h"
class DemonMountain : public layer {
public:
	DemonMountain(string, task *);
	~DemonMountain();
	void judgeTask();
	//移动
	void move(int);
private:
	//小地图
	string smalllayer[6];
	string smalllayerintroduction[7];
	//怪物
	string monstername[6];
	task * point;
	bool ifFinishTask;
};