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
			return 0;//ż����ʾ����غ�
		else
			return 1;//������ʾ����غ�
	}
	void fight() {
		round = firstRound();
		do {
			if (!judge||round%2!=0) {//����غ�
				srand(time(NULL));
				if (1 != rand() % ((int)this->character->getAvoidRate()))//�ж��Ƿ��ܳɹ�
					cout << "��ܳɹ�" << endl;
				else {
					cout << "��" << this->monster->returnName() << this->monster->returnSkill() << "����,���" <<
						this->monster->fighting() - 100 + this->character->getDefense() / 100 << "�˺�" << endl;//ֱ�Ӽ����˺���û�и���Ч��
					mylife -= this->monster->fighting;
				}
				
				round++;
			}
			else if (judge || round % 2 == 0) {//����غ�
				cout << "��ѡ����" << endl;
				cout << "1 ��ɽ��" << "2 ʮ��ն" << "3 ��Ӱ����" << "4 ����ǧ����" << "5 ��Ӱ֮ì" << "6 ��������" << "7 ������" << "8 ��������ǹ" << "9 ����ն" << "10 ��ɨ�˻�" << endl;
				int select;
				cin >> select;
				int hurt1=skill->UseSkill(select, force);
				int hurt2 = 0;
				srand(time(NULL));
				if (1 != rand() % ((int)this->character->getHitRate() * 10))//�ж��Ƿ�����
					cout << "û�����У�" << endl;
				else if (1 == rand() % ((int)this->character->getInterForce() * 10))//�жϱ�����
					hurt1 = hurt1 * 2;
				else if (1)//�����������ӳ�
					hurt2 = this->character->getStrength();
				else if (1)
					enemyslife -= hurt1 + hurt2;
				else if (1 == rand() % ((int)this->character->getNegative_state_rate()))//�ж��Ƿ��б���ѣ��״̬
					round++;
				if (blooding)
						enemyslife -= 10;//�ж��Ƿ��г�����Ѫ״̬
				round++;
			}
		} while ((mylife > 0) && enemyslife >0);
		if (mylife > 0) {
			if (this->monster->fall() != "")
				cout << "��ϲ������" << this->monster->fall() << endl;
		}
		else if (mylife < 0 || mylife == 0)
			cout << "��Ϸ����" << endl;
	}//ս�����������ﾭ�������뷨���ָ�
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
