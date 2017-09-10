#include"SkyMountain.h"
SkyMountain::SkyMountain(string layername, task* point, Character *gamer) :layer(layername),point(point),ifFinishTask(false) {
	changelayerintroduction("������ɽ���¡�");
	changetreasure("����");
	smalllayerintroduction[0] = "����/һ��������ɽ���¡�\n�ң�����ɽ�Ϲ־���ס����˺���ĵط�����.��\n�Ҹ�Ҫȡ������Я���ĸ����伢���Ϳ���һ�ŷ���Ϯ������\n���ƣ���ɽ�Ϲֶ�ͽ�ܣ������ߺ��ˣ�\n�������������ұ���ѩɽ��A��ǰ��Ѱ����ɽ�ϹַѶɣ�Ϊ��ʦ������\n���ƣ���ʦ���Ѿ�����δ���뿪��ɽ��������ͬ��ʦ���г�ޣ�Ҫ��������ȹ�������ذɣ�\n";
	smalllayerintroduction[1] = "���ƣ��Ҿ�������������С�����£�\n�ң�˵�ɣ��Ѷ������\n���ƣ�������ǵ�Ѫ�������䲻�ʵĿ�����һ�ۣ�����ʦ��������ɽɽ���ϣ�����������ȥ����Լ�Ѱ���ɣ�\n�Ҽ���������ɽ���С����ƺ����ĸ������ˣ���ɫ����������\n����ʱ���ҿ�����һ��������������һ�������ԣ����Ͽ���һֻ���ӣ���������������ڿ����С�\n��������ɽ�Ϲִ�ͽ�ܣ����ţ�����˭������������ɽ����\n�ң��ұ���ѩɽ�ɵ��ӣ���ɽ�ϹַѶɽ���ɱ������ʦ����������ɽ������Ѱ�Ѷ�Ϊ��ʦ������\n������������Ѱ����ʿ������ɽ���ұش���ʦ���д���һ����������ƾ�޾ݾ�˵��ʦ��ɱ���ˣ���ɲ��ܷŹ��ˣ�\n";
	smalllayerintroduction[2] = "�ң�����������ʦ���Ļ����׹����ʹ��˵��ɱ���ˣ�Ҳ��˵��������ʦ�������й�ϵ��\n������������ʦ���ĵ�׹���Ѷ�ʧ�˰������ˣ����Լ���ɽȥѯ����ʦ���ɣ�\n������ɽ�壬����һ����ˮ�������߲ʹ�â������ȥˮ�Լ���ϴһ����ȴ����ˮ��һŮ��������ʦ�������ǽ����ʲô�˰���\n�ң���ɽ�ϹַѶɣ����ٳ�������һ�����ͣ�\n��������ɽ�Ϲ�Сͽ�ܣ�����Ȼ��˲�������ʦ���������ɽȥ����Ҫ�����Ҹ�ʦ��������\n";
	smalllayerintroduction[3] = "��ɽ�Ϲ֣����Ǻ��ˣ���Ȼ�����Ұ�ͽ������������ǲ����뿪��ɽ�ˣ�\n��ɽ�Ϲֱ���ܺ󡪡�\n�ң��ұ���ѩɽ���ң�ǰ������ʦ��������ı�����������䷢���������׹���ҽ�������ɽ����������Ҫ��˵����\n�Ѷɣ�������η��������η����������׹ȷʵ��������ʱ��ʧ���Ϸ�Ҳ��֪����׹��������䵽�Ǵ������С������Ϸ��Ѿ�����δ����ɽ��ƽ��ȫ�����⼸��ͽ����ɽ�����̽����Ϣ����ǰ����ħ����������ı������ʦ��Ҳ���м�����ܡ��䵱ɽ�ۼ����ڶ�������ʿ������ѡ���ַ�ħ�̵����죬���ȥ����̽�������Ϣ��\n�ң���лǰ����\n��ɽ�Ϲ֣��Ϸ���һð����������׹ԭ�ǹ�������������ǰ��ʧ����ʧ�����ã��ܷ���黹���Ϸ��Ϸ��������Ҫ֮ʱף��һ��֮����\n�ң���Ȼǰ������ʦ��������û�й�ϵ��������׹���ԭ��Ҳ�޷����ڴ�л��ǰ���ˡ�\n��ɽ�Ϲ֣������������ӹ���׹�����ۡ�..\n";
	
	monstername[0] = "����";
	monstername[1] = "������";
	monstername[2] = "����";
	monstername[3] = "��ɽ�Ϲ�";

	smalllayer[0] = "��ɽɽ��";
	smalllayer[1] = "��ɽɽ´";
	smalllayer[2] = "��ɽ���";
	smalllayer[3] = "��ɽɽ��";
	operate(gamer);
}
SkyMountain::~SkyMountain() {

}
void SkyMountain::judgeTask() {
	if (point->getNowTask() > 4)
	{
		ifFinishTask = true;
	}
}
void SkyMountain::move(int i) {
	system("cls");
	HANDLE consolehwnd;
	consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consolehwnd, 11);
	cout << smalllayer[i] << endl;
	movestep(i);
	gettreasure();
}
void SkyMountain::operate(Character * gamer)
{
	int taskState = point->getNowTask();
	switch (taskState)
	{
	case 1:cout << "1.��ɽɽ��" << endl; break;
	case 2:cout << "1.��ɽɽ��\t2.��ɽɽ´" << endl; break;
	case 3:cout << "1.��ɽɽ��\t2.��ɽɽ´\t3.��ɽ���" << endl; break;
	case 4:cout << "1.��ɽɽ��\t2.��ɽɽ´\t3.��ɽ���\t4.��ɽɽ��" << endl;
	}
	cout << "��������ѡ��ĵص㣺";
	int choice;
	try {
		if (cin >> choice)
		{
			switch (choice)
			{
			case 1:
			{
				if (taskState > 0)
				{
					cout << smalllayerintroduction[0] << endl;
					Monster monster = Monster("����");
					system("pause");
					fighting fight = fighting(&monster,gamer);
				}
				else
				{
					Monster monster = Monster("����");
					system("pause");
					fighting fight = fighting(&monster, gamer);
				}
			}
			case 2: 
			{
				if (taskState > 1)
				{
					cout << smalllayerintroduction[1] << endl;
					Monster monster = Monster("������");
					system("pause");
					fighting fight = fighting(&monster, gamer);
				}
				else
				{
					Monster monster = Monster("������");
					system("pause");
					fighting fight = fighting(&monster, gamer);
				}
			}
			case 3:
			{
				if (taskState > 2)
				{
					cout << smalllayerintroduction[2] << endl;
					Monster monster = Monster("����");
					system("pause");
					fighting fight = fighting(&monster, gamer);
				}
				else
				{
					Monster monster = Monster("����");
					system("pause");
					fighting fight = fighting(&monster, gamer);
				}
			}
			case 4: 
			{
				if (taskState > 3)
				{
					cout << smalllayerintroduction[3] << endl;
					Monster monster = Monster("��ɽ�Ϲ�");
					system("pause");
					fighting fight = fighting(&monster, gamer);
				}
				else
				{
					Monster monster = Monster("��ɽ�Ϲ�");
					system("pause");
					fighting fight = fighting(&monster, gamer);
				}
			}
			default:throw Error("���벻���Ϲ淶������������1-4");
			}
		}
		else
		{
			throw Error("���벻���Ϲ淶������������1-4");
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

	}
}
