#include"Skill.h"
#include<iostream>
#include<Windows.h>
void Skill::LearnSkill(string name) {
	int i;
	//��ѯ�������֮���ж�ѧϰ���
	for (i = 0; i < 10; i ++)
	{
		if (name == skill[i])
		{
			if (!flag[i])
			{
				flag[i] = 1;
				cout << "�ɹ�ѧϰ�˼���" << endl;
			}
			else
			{
				cout << "�ü�����ѧϰ" << endl;
			}
		}
	}
	if (i == 10)
	{
		cout << "��ѡ���ܲ�����" << endl;
	}
}

int Skill::UseSkill(int name, int force) {
	int i=0;
	for (i = 0; i < 11; i++)
	{
		if (name==i)
		{
			if (flag[i] == 1)
			{
				if (force >= consumption[i])
				{
					force -= consumption[i];
					return force;

				}
				else
				{
					cout << "�������㣡" << endl;
					return force;
				}
			}
			if(flag[i] == 0)
			{
				cout << "�ü�����δѧϰ��" << endl;
				return force;
			}
		}
		else
		{
			cout << "�����ڸü��ܣ�" << endl;
			return force;
		}
	}
	return force;
}
void Skill::showSkill() {
	int j;
	//��ѯ�������
	for (j = 0; j < 11; j++)
	{
		HANDLE consolehwnd;
		consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(consolehwnd, 14);
		if (flag[j]==1)//���ѧ���˸ü��ܣ�����ʾ�ü���
			cout << j << "  " << skill[j] << " ";

	}
	cout << endl;
}
Skill::Skill() {//һ��11�����ܣ��չ�������0�������±���Ǽ��ܴ���
	skill[0]="��ͨ����", damage[0] = 30, consumption[0] = 0;
	skill[1] = "��ɽ��", damage[0] = 50, consumption[0] = 10;
	skill[2] = "ʮ��ն", damage[1] = 60, consumption[1] = 10;
	skill[3] = "��Ӱ����", damage[2] = 65, consumption[2] = 20;
	skill[4] = "����ǧ����", damage[3] = 70, consumption[3] = 30;
	skill[5] = "��Ӱ֮ì", damage[4] = 80, consumption[4] = 30;
	skill[6] = "��������", damage[5] = 90, consumption[5] = 30;
	skill[7] = "������", damage[6] = 90, consumption[6] = 20;
	skill[8] = "��������ǹ", damage[7] = 100, consumption[7] = 30;
	skill[9] = "����ն", damage[8] = 130, consumption[8] = 50;
	skill[10] = "��ɨ�˻�", damage[9] = 200, consumption[9] = 80;
	flag[0] = 1;//��ʼ������չ�
	for (int i = 1; i < 11; i++)
	{
		flag[i] = 0;//��ʼû��ѧ�Ἴ��
	}

}
int Skill::getSkilldamage(int i) {//�����˺�ֵ
	return damage[i];
}
int Skill::getSkillconsumption(int k) {//�������ķ�����ֵ
	return consumption[k];
}
void Skill::setSkillLearned(int i) {//���ļ���ʱ�����Ѿ�ѧ��ļ�������ѧ��״̬
	flag[i] = 1;
}
bool Skill::iflearnt(int i) {//�ж��Ƿ�ѧ��ü���
	if (flag[i] == 1)
		return true;
	else
		return false;
}
