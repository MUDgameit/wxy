#include"fighting.h"
#include<time.h>
#include<stdlib.h>
fighting::fighting(Monster * monster, Character * character):monster(monster),character(character)
{
	skill = new Skill();
	mylife = character->getLife();
	enemyslife = monster->returnLife();
	blooding = false;
	this->fight();
}

bool fighting::judge()//�ж�һ�ٵĺ��������ж����������������������Զ�������ȹ������������ж�����͹��������ٶȣ�˭��˭�ȹ���
{//true�������������ж�
	if ((this->character)->getAttackSpeed() == 1)
		return true;
	else if ((this->character)->getAttackSpeed() >(monster)->getAttackSpeed())
		return true;
	else
		return false;
}

int fighting::firstRound()
{
	if (judge())//�ж�˭���ж�������һ�غ���˭��
		return 0;//ż����ʾ����غ�
	else
		return 1;//������ʾ����غ�
}

void fighting::fight()
{
	round = firstRound();//�жϵ�һ�غ���˭��
	do {
		if (!judge() || round % 2 != 0) {//����غϣ��غ������������߿�����1���ǹ���Ļغ�
			srand(time(NULL));
			if (1 != rand() % ((int)character->getAvoidRate()))//�ж��Ƿ��ܳɹ���������Ķ���ʣ������������ʱ��
				cout << "��ܳɹ�" << endl;
			else {//û�ж�ܳɹ�
				cout << "��" << monster->returnName() <<//���������
					monster->returnSkill() << "����,���" <<//����ļ���
					monster->fighting() - 100 + (character->getDefense() / 100 )<< "�˺�" << endl;//ֱ�Ӽ����˺���û�и���Ч�����˺����㹫ʽ����
				mylife -= monster->fighting();//�����ȥѪ��
			}

			round++;//�غ���Ŀ��һ
		}
		else if (judge() || round % 2 == 0) {//����غϣ��غ�����ż�����߿�����0��������Ļغ�
			cout << "��ѡ����" << endl;
			this->skill->showSkill();//��ʾ�����Ѿ�ѧ��ļ���
			int select=0;//��ʼ������
			cin >> select;//����ѡ��ļ������
			force = this->skill->UseSkill(select, force);//ʣ�෨���ļ��㣬��ʾʹ�øü���֮��ʣ�෨��
			int hurt1 = this->skill->getSkilldamage(select);//�˺��ĵ�һ���֣�������ʹ�ü�������ɵ��˺�
			int hurt2 = 0;

			srand((unsigned int)time(NULL));
			if (1==rand()%(int)(this->character->getAvoidRate()*100))//�ж��Ƿ����У�û�����еĻ�ֱ�ӻغ�����һ
				cout << "û�����У�" << endl;
			else if (1== rand() % (int)(this->character->getHitRate() * 100))//�жϱ�����
				hurt1 = hurt1 * 2;//�����������һ���ֹ������Զ�
			else if (1)//�����������ӳɣ����˺��ĵڶ�����
				hurt2 = character->getStrength();
			else if (1)
				enemyslife -= hurt1 + hurt2;//�����Ѫ
			else if (rand() % ((int)this->character->getNegative_state_rate())==1)//�ж��Ƿ��б���ѣ��״̬������еĻ��غ�����һ��������������Ǹ��غ�
				round++;
			if (blooding)
				enemyslife -= 10;//�ж��Ƿ��г�����Ѫ״̬��������Ѫÿһ�غϹ���Ѫ����10
			round++;//�غ�����һ
		}
	} while ((mylife > 0) && enemyslife >0);//����͹����Ѫ��������0������£�һֱս��
	if (mylife > 0) {//���ս������������Ѫ������0����������ʤ��
		if (monster->fall() != "")//�����Ƿ������Ʒ
			cout << "��ϲ������" << monster->fall() << endl;//����������ûд
	}
	else if (mylife < 0 || mylife == 0)//��֮�������ˣ���Ϸ����
		cout << "��Ϸ����" << endl;
}
