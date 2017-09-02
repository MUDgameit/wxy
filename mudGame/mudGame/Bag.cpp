#include"Bag.h"
void Bag::AddWeapon(string name) {
	weapon[number] = new Weapon(name);
}
void Bag::DeleteWeapon(string name) {
	int i = 0;
	int flag = 0;//是否删除了
	for (i = 0; i < number; i++)
	{
		if (weapon[i]->getName() == name)
		{
			weapon[i] = NULL;
		}
		//将删除后所有物品前移
		if (weapon[i] == NULL)
		{
			weapon[i] == weapon[i + 1];
		}
	}
	if (!flag)
	{
		cout << "你没有这个装备！" << endl;
	}
	else
	{
		number--;
	}
}
void Bag::ShowWeapon() {
	int i = 0;
	for (i = 0; i < number; i++)
	{
		cout << weapon[i]->getName() << endl;
	}
}
Bag::Bag() {
	weapon = new Weapon*[100]();
	number = 0;
}