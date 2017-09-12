#include"fighting.h"
#include<time.h>
#include<stdlib.h>
fighting::fighting(Monster * monster, Character * character, task * taskPoint, int taskNum):monster(monster),character(character)
{
	skill = character->getSkill();
	mylife = character->getLife();
	enemyslife = monster->returnLife();
	blooding = false;
	this->fight(taskPoint,taskNum);
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

void fighting::fight(task* point, int task)
{
	int i;
	round = firstRound();//�жϵ�һ�غ���˭��
	do {
		if ( round % 2 != 0) {//����غϣ��غ������������߿�����1���ǹ���Ļغ�
			srand(time(NULL));
			i = rand() % (10 / ((int)(character->getAvoidRate() * 10))) + 1;
			if (1 == i)//�ж��Ƿ��ܳɹ���������Ķ���ʣ������������ʱ��
				cout << "���ܳɹ�" << endl;
			else {//û�ж�ܳɹ�
				cout << "�㱻" << monster->returnName() <<//���������
					monster->returnSkill() << "����,���" <<//����ļ���
					monster->fighting() * (100.0 / (character->getDefense()+100) )<< "�˺�" << endl;//ֱ�Ӽ����˺���û�и���Ч�����˺����㹫ʽ����
				mylife -= monster->fighting() * (100.0 / (character->getDefense() + 100));//�����ȥѪ��
			}

			round++;//�غ���Ŀ��һ
		}
		else if ( round % 2 == 0) {//����غϣ��غ�����ż�����߿�����0��������Ļغ�
			cout << "��ѡ����" << endl;
			this->skill->showSkill();//��ʾ�����Ѿ�ѧ��ļ���
			int select=0;//��ʼ������
			try {
				if (cin >> select)//����ѡ��ļ������
				{
					switch (select)
					{
					case 0:break;
					case 1:break;
					case 2:break;
					case 3:break;
					case 4:break;
					case 5:break;
					case 6:break;
					case 7:break;
					case 8:break;
					case 9:break;
					case 10:break;
					default:throw Error("���벻���Ϲ淶������������1-10");
					}
					srand((unsigned int)time(NULL));
					//i = rand() % (10 / ((int)(character->getHitRate() * 10))) + 1;
					if (!(this->skill->iflearnt(select)))
						;
					else
					{
						force = this->skill->UseSkill(select, force);//ʣ�෨���ļ��㣬��ʾʹ�øü���֮��ʣ�෨��
						int hurt1 = this->skill->getSkilldamage(select);//�˺��ĵ�һ���֣�������ʹ�ü�������ɵ��˺�
						int hurt2 = 0;
						if (1 == rand() % (10 / ((int)(character->getHitRate() * 10))) + 1)//�ж��Ƿ����У�û�����еĻ�ֱ�ӻغ�����һ
						{
							cout << "��Ĺ���û�����У�" << endl;
						}
						else
						{
							if (1 == rand() % (int)(this->character->getHitRate() * 100))//�жϱ�����
								hurt1 = hurt1 * 2;//�����������һ���ֹ������Զ�
												  //�����������ӳɣ����˺��ĵڶ�����
							hurt2 = character->getStrength();
							enemyslife -= hurt1 + hurt2;//�����Ѫ
							cout << "��Ĺ��������" << hurt1 + hurt2 << "���˺���" << endl;

							if ((int)this->character->getNegative_state_rate() == 1)//�ж��Ƿ��б���ѣ��״̬������еĻ��غ�����һ��������������Ǹ��غ�
								round++;
							if (blooding)
								enemyslife -= 10;//�ж��Ƿ��г�����Ѫ״̬��������Ѫÿһ�غϹ���Ѫ����10
						}
					}
					round++;//�غ�����һ
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
				system("pause");

				system("cls");
			}

		}
	} while ((mylife > 0) && enemyslife >0);//����͹����Ѫ��������0������£�һֱս��
	if (mylife > 0) {//���ս������������Ѫ������0����������ʤ��
		cout << "ս��ʤ����" << endl;
		point->finishTask(task);
		string fallArticle = monster->fall();
		if (fallArticle != "")//�����Ƿ������Ʒ
		{
			cout << "��ϲ������" << fallArticle << endl;//����������ûд
			character->getBag()->AddWeapon(fallArticle);

		}
		character->setExperience(character->getExperience() + 20);
	}
	else if (mylife < 0 || mylife == 0)//��֮�������ˣ���Ϸ����
		cout << "��Ϸ����" << endl;
	system("pause");
	system("cls");
	if (character->getExperience() >= 100)
	{
		character->setExperience(character->getExperience() - 100);
		character->getSkill()->LearnSkill(character->getLevel());
		character->levelUp();
		cout << "��ϲ��������ѧϰ�����¼���:" << character->getSkill()->getSkillName(character->getLevel()) << endl;
	}
}
