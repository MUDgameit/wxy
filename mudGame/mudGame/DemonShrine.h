#pragma once
#include"layer.h"
#include"task.h"
class DemonShrine : public layer {
public:
	DemonShrine(string, task *);
	~DemonShrine();
	void judgeTask();
	//�ƶ�
	void move(int);
private:
	//С��ͼ
	string smalllayer[7];
	string smalllayerintroduction[7];
	//����
	string monstername[6];
	task * point;
	bool ifFinishTask;
};