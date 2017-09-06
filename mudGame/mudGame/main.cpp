#include <iostream>
#include<istream>
#include <fstream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
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

using namespace std;

int main()
{
	operating operating_user;
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
					int choiceMap;
					while (choiceMap = operating_user.showMap(myTask))
					{
						switch (choiceMap)
						{
							case 1:
							{
								SkyMountain map = SkyMountain("��ɽ", &myTask, &amy);
							}
							case 2:
							{
								WuDang map = WuDang("�䵱", &myTask);
							}
							case 3:
							{
								DemonMountain map = DemonMountain("ħ�����ɽ", &myTask);
							}
							case 4:
							{
								GreenCityMountain map = GreenCityMountain("���ɽ", &myTask);
							}
							case 5:
							{
								DemonShrine map = DemonShrine("ħ��ʥ��", &myTask);
							}
							system("cls");
							default:break;
						}
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
			ifstream file;
			file.open("name.txt");
			string name;
			string weaponname;
			int i;
			while (file.good())
			{
				file >> name;
			}
			file.close;
			Character amy(name);
			ifstream file4;
			double i;
			string wearing;
			file.open("character.txt");
			while (file.good())
			{
				file >>i;
				amy.setAttackSpeed(i);
				file >> i;
				amy.setAvoidRate(i);
				file >> wearing;
				amy.setChest(new Equipment(wearing));
				file >> i;
				amy.setDefense(i);
				file >> i;
				amy.setExperience(i);
				file >> i;
				amy.setForceRate(i);
				file >> i;
				amy.setHitRate(i);
				file >> i;
				amy.setInterForce(i);
				file >> wearing;
				amy.setLeg(new Equipment(wearing));
				file >> i;
				amy.setLevel(i);
				file >> i;
				amy.setLife(i);
				file >> i;
				amy.setNegative_state_rate(i);
				file >> wearing;
				amy.setStrength(new Equipment(wearing));
				file >> i;
				amy.setStrength(i);
				file >> wearing;
				amy.setWeapon(new Weapon(wearing));

			}
			Bag myBag = Bag();
			ifstream file1;
			file1.open("bag.txt");
			while (file1.good()) {
				file1 >> weaponname;
				myBag.AddWeapon(weaponname);
			}
			//���ɼ���
			Skill mySkill = Skill();
			int SkillNumber;
			ifstream file2;
			file2.open("SkillName.txt");
			while (file2.good()) {
				file2 >> SkillNumber;
				mySkill.setSkillLearned(SkillNumber);
			}
			//��������
			task myTask = task();
			int taskNumber,i=0;
			ifstream file3;
			file3.open("Task.txt");
			while (file3.good()) {
				file3 >> taskNumber;
				myTask.setfinishTask(taskNumber);
				i++;
			}
			myTask.setNowTask(i);
		}
	}
	else
	{
		return 0;
	}

	
	return 0;
}
