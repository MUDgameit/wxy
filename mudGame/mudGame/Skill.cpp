#include"Skill.h"
void Skill::LearnSkill(string name) {
	int i;
	//��ѯ�������
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
	int i;
	for (i = 0; i < 10; i++)
	{
		if (name-1 == i)
		{
			if (flag[i] == 1)
			{
				if (force >= consumption[i])
				{
					force -= consumption[i];
				}
				else
				{
					cout << "�������㣡" << endl;
				}
			}
			else
			{
				cout << "�ü�����δѧϰ��" << endl;
			}
		}
		else
		{
			cout << "�����ڸü��ܣ�" << endl;
		}
	}
	return force;
}
Skill::Skill() {
	skill[0] = "��ɽ��", damage[0] = 50, consumption[0] = 10;
	skill[1] = "ʮ��ն", damage[1] = 60, consumption[1] = 10;
	skill[2] = "��Ӱ����", damage[2] = 65, consumption[2] = 20;
	skill[3] = "����ǧ����", damage[3] = 70, consumption[3] = 30;
	skill[4] = "��Ӱ֮ì", damage[4] = 80, consumption[4] = 30;
	skill[5] = "��������", damage[5] = 90, consumption[5] = 30;
	skill[6] = "������", damage[6] = 90, consumption[6] = 20;
	skill[7] = "��������ǹ", damage[7] = 100, consumption[7] = 30;
	skill[8] = "����ն", damage[8] = 130, consumption[8] = 50;
	skill[9] = "��ɨ�˻�", damage[9] = 200, consumption[9] = 80;
	for (int i = 0; i < 10; i++)
	{
		flag[i] = 0;
	}

}
int Skill::getSkilldamage(int i) {
	return damage[i - 1];
}
int Skill::getSkillconsumption(int k) {
	return consumption[k - 1];
}
