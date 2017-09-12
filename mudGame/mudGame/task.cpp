#include "task.h"

task::task()
{
	int i = 0;
	nowTask = 0;
	ifstream readTask;
	readTask.open("task.txt");
	if (readTask)
	{
		while (!readTask.eof())
		{
			getline(readTask, taskContent[i], '\n');
			ifFinishTask[i] = 0;
			i++;
		}
	}
	else
	{
		cout << "open the task file error, please examine the file location" << endl;
	}
	
}

void task::showTask()
{
	HANDLE consolehwnd;
	consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consolehwnd, 14);
	cout << "1.��ǰ����2.���������3.����" << endl;
	
	int choice = 1;
	while (true)
	{
		cout << "������ѡ�";
		try {
			if (cin >> choice)
			{
				switch (choice)
				{
				case 1:this->printNowTask();break;
				case 2:this->printFinishedTask();
				case 3:break;
				default:throw Error("���벻���Ϲ淶������������1-3");
				}
			}
			else
			{
				throw Error("���벻���Ϲ淶������������1-3");
			}
		}
		catch (Error &e) {
			// �����Ƿ��ַ��������������ڳ���״̬��
			// Ϊ�˼�����ȡ���룬����Ҫ���� clear ����
			cin.clear();
			// numeric_limits<streamsize>::max() �������뻺��Ĵ�С��
			// ignore �����ڴ˽����������е�������ա�
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			cout << e.what() << endl;
			
		}
		if (choice == 3)
		{
			system("cls");
			break;
		}
	}
}

bool task::ifTaskFinish(int i)
{
	if (ifFinishTask[i] == 0)
		return false;
	else
		return true;
}

void task::finishTask(int choice)
{
	if (!this->ifTaskFinish(choice))
	{

		ifFinishTask[choice] = 1;
		nowTask++;
	}
	
}
void task::finishNowTask(int choice)
{
	if (nowTask == 0 || nowTask == 10 || nowTask == 14)
	{
		ifFinishTask[nowTask] = choice;
		nowTask++;
	}
	else
	{
		ifFinishTask[nowTask] = 1;
		nowTask++;
	}
}
int task::getTaskInformation(int i)
{
	return ifFinishTask[i];
}
void task::printFinishedTask()
{
	if (nowTask != 0)
	{
		int i = 0;
		for (i = 0; i < nowTask; i++)
		{
			if (ifFinishTask[i] = true)
			{
				cout << taskContent[i] << "  ���" << endl;
			}
		}
	}
	else
	{
		cout << "û������ɵ�����" << endl;
	}
}

void task::printNowTask()
{
	cout << taskContent[nowTask] << endl;
}
void task::setNowTask(int i)
{
	nowTask = i;
}
void task::setfinishTask(int i)
{
	ifFinishTask[i] = 1;
}
int task::getNowTask()
{
	return nowTask;
}
