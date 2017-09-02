#include"Skill.h"
void Skill::LearnSkill(string name) {
	int i;
	//查询技能情况
	for (i = 0; i < 10; i ++)
	{
		if (name == skill[i])
		{
			if (!flag[i])
			{
				flag[i] = 1;
				cout << "成功学习此技能" << endl;
			}
			else
			{
				cout << "该技能已学习" << endl;
			}
		}
	}
	if (i == 10)
	{
		cout << "所选技能不存在" << endl;
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
					cout << "内力不足！" << endl;
				}
			}
			else
			{
				cout << "该技能尚未学习！" << endl;
			}
		}
		else
		{
			cout << "不存在该技能！" << endl;
		}
	}
	return force;
}
Skill::Skill() {
	skill[0] = "崩山击", damage[0] = 50, consumption[0] = 10;
	skill[1] = "十字斩", damage[1] = 60, consumption[1] = 10;
	skill[2] = "幻影剑舞", damage[2] = 65, consumption[2] = 20;
	skill[3] = "雷鸣千军破", damage[3] = 70, consumption[3] = 30;
	skill[4] = "暗影之矛", damage[4] = 80, consumption[4] = 30;
	skill[5] = "霹雳旋踢", damage[5] = 90, consumption[5] = 30;
	skill[6] = "旋风腿", damage[6] = 90, consumption[6] = 20;
	skill[7] = "夺命雷霆枪", damage[7] = 100, consumption[7] = 30;
	skill[8] = "破灭斩", damage[8] = 130, consumption[8] = 50;
	skill[9] = "横扫八荒", damage[9] = 200, consumption[9] = 80;
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
