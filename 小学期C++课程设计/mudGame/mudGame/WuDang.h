#pragma once
#include"layer.h"
#include"task.h"
class WuDang : public layer {
public:
	WuDang(string, task *);
	~WuDang();
	void judgeTask();
	//�ƶ�
	void move(int);
private:
	//С��ͼ
	string smalllayer[4];
	string smalllayerintroduction[4];
	//����
	string monstername[4];
	task * point;
	bool ifFinishTask;
};