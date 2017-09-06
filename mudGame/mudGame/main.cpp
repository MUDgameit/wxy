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
	//返回值为零则退出游戏
	int startMenuChoice = operating_user.showStartMenu();
	if (startMenuChoice)
	{
		//新的游戏
		if (startMenuChoice == 1)
		{	
			
			//生成人物
			Character amy(operating_user.getGamerName());
			

			//生成背包
			Bag myBag = Bag();
			//生成技能
			Skill mySkill = Skill();
			//生成任务
			task myTask = task();
			//故事
			myTask.finishTask(operating_user.showStory(amy));
			system("cls");
			int mainMenuChoice = 0;
			while (mainMenuChoice = operating_user.showMainMenu(amy))
			{
				//进入地图

				if (mainMenuChoice == 1)
				{
					int choiceMap;
					while (choiceMap = operating_user.showMap(myTask))
					{
						switch (choiceMap)
						{
							case 1:
							{
								SkyMountain map = SkyMountain("天山", &myTask, &amy);
							}
							case 2:
							{
								WuDang map = WuDang("武当", &myTask);
							}
							case 3:
							{
								DemonMountain map = DemonMountain("魔教睥睨山", &myTask);
							}
							case 4:
							{
								GreenCityMountain map = GreenCityMountain("青城山", &myTask);
							}
							case 5:
							{
								DemonShrine map = DemonShrine("魔教圣地", &myTask);
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
				//查看背包
				if (mainMenuChoice == 2)
				{
					myBag.ShowWeapon();
				}
				//查看任务
				if (mainMenuChoice == 3)
				{
					myTask.showTask();
				}
				mainMenuChoice=0;
			}
			return 0;
		}
		//读取存档
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
			//生成技能
			Skill mySkill = Skill();
			int SkillNumber;
			ifstream file2;
			file2.open("SkillName.txt");
			while (file2.good()) {
				file2 >> SkillNumber;
				mySkill.setSkillLearned(SkillNumber);
			}
			//生成任务
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
