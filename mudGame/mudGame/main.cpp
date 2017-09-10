#include <iostream>
#include<fstream> 
#include <string>
#include <string.h>
#include <stdlib.h>
#include "Bag.h"
#include "character.h"
#include "DemonMountain.h"
#include "DemonShrine.h"
#include "Error.h"
#include "equipment.h"
#include "fighting.h"
#include "GreenCityMountain.h"
#include "layer.h"
#include "monster.h"
#include "operating.h"
#include "Skill.h"
#include "SkyMountain.h"
#include "task.h"
#include "weapon.h"
#include "WuDang.h"
#include<windows.h>
#include<mmsystem.h>
//windows�����ý���йصĴ�����ӿ�
#pragma commen(lib,"WINMM.LIB")
using namespace std;

int main()
{
	
	operating operating_user;
	//sndPlaySound("E:\BaiduNetdiskDownload\a.wav", SND_ASYNC);
	//system("..\a.MP3\");
	PlaySound(TEXT("..\a.MP3\"), NULL, SND_FILENAME);
	//����ֵΪ�����˳���Ϸ
	int startMenuChoice = operating_user.showStartMenu();
	if (startMenuChoice)
	{

		//�µ���Ϸ
		if (startMenuChoice == 1)
		{	
			
			//��������
			Character amy(operating_user.getGamerName());
			

			//���ɱ���
			Bag myBag = Bag();
			//���ɼ���
			Skill mySkill = Skill();
			//��������
			task myTask = task();
			//����
			myTask.finishTask(operating_user.showStory(amy));
			system("cls");
			int mainMenuChoice = 0;
			while (mainMenuChoice = operating_user.showMainMenu(amy))
			{
				//�����ͼ
				if (mainMenuChoice == 1)
				{
					system("cls");
					int choiceMap;
					while (choiceMap = operating_user.showMap(myTask))
					{
						switch (choiceMap)
						{
							case 1:
							{
								SkyMountain map = SkyMountain("��ɽ", &myTask, &amy);
								break;
							}
							case 2:
							{
								WuDang map = WuDang("�䵱", &myTask, &amy);
								break;
							}
							case 3:
							{
								DemonMountain map = DemonMountain("ħ�����ɽ", &myTask,&amy);
								break;
							}
							case 4:
							{
								GreenCityMountain map = GreenCityMountain("���ɽ", &myTask,&amy);
								break;
							}
							case 5:
							{
								DemonShrine map = DemonShrine("ħ��ʥ��", &myTask,&amy);
								break;
							}
							
							default:break;
						}
						system("cls");
					}
					if (choiceMap == 0)
					{
						system("cls");
					}
				}
				//�鿴����
				if (mainMenuChoice == 2)
				{
					myBag.ShowWeapon();
				}
				//�鿴����
				if (mainMenuChoice == 3)
				{
					myTask.showTask();
				}
				mainMenuChoice=0;
			}
			return 0;
		}
		//��ȡ�浵
		else
		{

		}
	}
	else
	{
		return 0;
	}

	
	return 0;
}
