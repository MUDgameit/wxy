#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include"operating.h"
#include"character.h"
#include"Error.h"
#include<stdlib.h>
#include<limits>
using namespace std;
class task {
public:
	task();
	void showTask();
	bool ifTaskFinish(int);
	void finishTask(int);
	void setfinishTask(int);
	void setNowTask(int);
	void printFinishedTask();
	void printNowTask();
	int getNowTask();
	void finishNowTask(int);
	int getTaskInformation(int);
private:
	int nowTask;
	string taskContent[25];
	//0��ʾδ��ɣ�1��2��ʾѡ��Ҳ�����������
	int ifFinishTask[25];
};
