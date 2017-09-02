#include<string>
#include<iostream>
#include"monster.h"
#include"character.h"
#include"Skill.h"
#include<time.h>
using namespace std;
class fighting {
public:
	fighting(monster *monster, Character*character){
		this->monster = monster;
		this->character = character;
		this->skill = new Skill();
		mylife = this->character->getLife();
		enemyslife = this->monster->returnLife();
		blooding = false;
	}
	bool judge()
	{
		if ((this->character)->getAttackSpeed()==1 )
			return true;
		else if ((this->character)->getAttackSpeed() >(this->monster)->getAttackSpeed())
			return true;
		else
			return false;
	}
	int firstRound() {
		if (judge)
			return 0;//偶数表示人物回合
		else
			return 1;//奇数表示怪物回合
	}
	void fight() {
		round = firstRound();
		do {
			if (!judge||round%2!=0) {//怪物回合
				srand(time(NULL));
				if (1 != rand() % ((int)this->character->getAvoidRate()))//判断是否躲避成功
					cout << "躲避成功" << endl;
				else {
					cout << "被" << this->monster->returnName() << this->monster->returnSkill() << "攻击,造成" <<
						this->monster->fighting() - 100 + this->character->getDefense() / 100 << "伤害" << endl;//直接计算伤害，没有附加效果
					mylife -= this->monster->fighting;
				}
				
				round++;
			}
			else if (judge || round % 2 == 0) {//人物回合
				cout << "请选择技能" << endl;
				cout << "1 崩山击" << "2 十字斩" << "3 幻影剑舞" << "4 雷鸣千军破" << "5 暗影之矛" << "6 霹雳旋踢" << "7 旋风腿" << "8 夺命雷霆枪" << "9 破灭斩" << "10 横扫八荒" << endl;
				int select;
				cin >> select;
				int hurt1=skill->UseSkill(select, force);
				int hurt2 = 0;
				srand(time(NULL));
				if (1 != rand() % ((int)this->character->getHitRate() * 10))//判断是否命中
					cout << "没有命中！" << endl;
				else if (1 == rand() % ((int)this->character->getInterForce() * 10))//判断暴击率
					hurt1 = hurt1 * 2;
				else if (1)//力量给攻击加成
					hurt2 = this->character->getStrength();
				else if (1)
					enemyslife -= hurt1 + hurt2;
				else if (1 == rand() % ((int)this->character->getNegative_state_rate()))//判断是否有冰冻眩晕状态
					round++;
				if (blooding)
						enemyslife -= 10;//判断是否有持续出血状态
				round++;
			}
		} while ((mylife > 0) && enemyslife >0);
		if (mylife > 0) {
			if (this->monster->fall() != "")
				cout << "恭喜你获得了" << this->monster->fall() << endl;
		}
		else if (mylife < 0 || mylife == 0)
			cout << "游戏结束" << endl;
	}//战斗结束后人物经验提升与法力恢复
private:
	int enemyslife;
	int mylife;
	int force = 100;
	int round;
	int probability;
	bool blooding;
	monster*monster;
	Character*character;
	Skill*skill;
};
