#pragma once
#include"layer.h"
#include"monster.h"
#include"task.h"
#include"fighting.h"
#include"character.h"
class WuDang : public layer {
public:
	WuDang(string, task *, Character *);
	~WuDang();
	void judgeTask();
	//�ƶ�
	void move(int);
	void operate(Character *);
private:
	//С��ͼ
	string smalllayer[6];
	string smalllayerintroduction[6];
	//����
	string monstername[6];
	task * point;
	bool ifFinishTask;
};