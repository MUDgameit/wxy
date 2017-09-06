#pragma once
#include"layer.h"
#include"task.h"
class DemonShrine : public layer {
public:
	DemonShrine(string, task *);
	~DemonShrine();
	void judgeTask();
	//移动
	void move(int);
private:
	//小地图
	string smalllayer[7];
	string smalllayerintroduction[7];
	//怪物
	string monstername[6];
	task * point;
	bool ifFinishTask;
};