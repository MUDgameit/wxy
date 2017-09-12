#include <iostream>
#include <fstream>
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
#include "save.h"
using namespace std;

int main()
{
	operating operating_user;
	//返回值为零则退出游戏
	int startMenuChoice = operating_user.showStartMenu();
	//生成人物
	Character amy;
	//生成背包
	Bag myBag;
	//生成技能
	Skill mySkill;
	//生成任务
	task myTask;
	if (startMenuChoice)
	{
		//新的游戏
		if (startMenuChoice == 1)
		{
			//生成背包
			myBag = Bag();
			//生成技能
			mySkill = Skill();
			//生成任务
			myTask = task();
			//生成人物
			amy = Character(operating_user.getGamerName(),&mySkill,&myBag);
			//故事
			myTask.finishNowTask(operating_user.showStory(amy));
			system("cls");

		}
		//读取存档
		else
		{
			ifstream file;
			file.open("name.txt");
			string name;
			string weaponname;
			while (file.good())
			{
				file >> name;
			}
//			file.close;
			amy = Character(name, &mySkill, &myBag);
			ifstream file4;
			double i;
			string wearing;
			file.open("character.txt");
			while (file.good())
			{
				file >> i;
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
				amy.setShoulder(new Equipment(wearing));
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
			int taskNumber,  k= 0;
			ifstream file3;
			file3.open("Task.txt");
			while (file3.good()) {
				file3 >> taskNumber;
				myTask.setfinishTask(taskNumber);
				k++;
			}
			myTask.setNowTask(i);
		}
		int mainMenuChoice = 0;
		while (mainMenuChoice = operating_user.showMainMenu(amy))
		{
			//进入地图
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
						SkyMountain map = SkyMountain("天山", &myTask, &amy);
						break;
					}
					case 2:
					{
						WuDang map = WuDang("武当", &myTask, &amy);
						break;
					}
					case 3:
					{
						DemonMountain map = DemonMountain("魔教睥睨山", &myTask, &amy);
						break;
					}
					case 4:
					{
						GreenCityMountain map = GreenCityMountain("青城山", &myTask, &amy);
						break;
					}
					case 5:
					{
						DemonShrine map = DemonShrine("魔教圣地", &myTask, &amy);
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
			//查看背包
			if (mainMenuChoice == 2)
			{
				myBag.ShowWeapon(amy);
			}
			//查看任务
			if (mainMenuChoice == 3)
			{
				myTask.showTask();
			}
			mainMenuChoice = 0;
		}
		return 0;
	}
	else
	{   //save save1(&amy,&myBag,&mySkill,&myTask);
		return 0;
	}


	return 0;
}
