#include"Bag.h"
void Bag::AddWeapon(string name) {
	weapon[number] = new Weapon(name);
}
void Bag::DeleteWeapon(string name) {
	int i = 0;
	int flag = 0;//�Ƿ�ɾ����
	for (i = 0; i < number; i++)
	{
		if (weapon[i]->getName() == name)
		{
			weapon[i] = NULL;
		}
		//��ɾ����������Ʒǰ��
		if (weapon[i] == NULL)
		{
			weapon[i] == weapon[i + 1];
		}
	}
	if (!flag)
	{
		cout << "��û�����װ����" << endl;
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