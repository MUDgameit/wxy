#include"DemonShrine.h"
DemonShrine::DemonShrine(string layername, task* point,Character*gamer) :layer(layername), point(point), ifFinishTask(false) {
	changelayerintroduction("");
	changetreasure("����");

	smalllayerintroduction[0] = ".�˴����ħ���ж����ڶ�������ʿ�μӣ��������������ɽ�Ϲ�Ҳ��������ͽ���ٴγ�ɽ�ˡ�\n";
	smalllayerintroduction[1] = "";
	smalllayerintroduction[2] = "";
	smalllayerintroduction[3] = "";
	smalllayerintroduction[4] = ""; 
	smalllayerintroduction[5] = "";
	smalllayerintroduction[6] = "����ɱ�����մ�BOSS����ħ�̽���ʱ������������䣺\n�ң�ʦ����������\n��������Ե����Ե����Ȼ�Ǳ�Ӧ�𣿣���Ѫ��\n�ң�����ʦ������Ҫһ�����ͣ�\n���������˰��ˣ���Ҳ�����Ͼ�Ҫ�������ˣ�������Ҳ�޷����ұ���ħ���󻤷���20��ǰɱ����ѩɽ�����Ų�αװ���������ӣ�16��ǰ�㸸ĸı��������Ҳ���ҡ��������һ���һͬ�߻��ġ������ҵ�����ô...��Ȼ��αװ�ˣ��һ����븴��ħ�̵ġ�ǧ�������ž��ǵ�������������Ӥ�ñ��˻����ɡ�û�뵽�����㾹Ȼ�����ǵĺ���....֮ǰ�ҵ�ȷ�ǰ��㵱���������������������������ô����ʦ��������ϣ���ֻ����������ȫʬ...�ȿ�.....��ħ�̽�������\n�����鸴�ӣ�ȴҲ�����������ԣ���ͬ�������ֺ�ʦ�����ᡣ���������������ѧϰ���գ������ӹ��䵱�ɣ���Ϊ��һ��������������Ϸ���������������ñ����վ��������������ڿ�";

	monstername[0] = "ħ�̳���Ҽ";
	monstername[1] = "ħ�̳��Ϸ�";
	monstername[2] = "ħ�̳�����";
	monstername[3] = "ħ�̳�����";
	monstername[4] = "ħ�̳�����";
	monstername[5] = "ħ�̽���";

}
DemonShrine::~DemonShrine() {

}
void DemonShrine::judgeTask() {
	if (point->getNowTask() > 10)
	{
		ifFinishTask = true;
	}
}
void DemonShrine::move(int i) {
	system("cls");
	cout << smalllayer[i] << endl;
	movestep(i);
	gettreasure();
}

void DemonShrine::operate(Character *gamer)
{
	while (true)
	{
		int taskState = point->getNowTask();
		switch (taskState)
		{
		case 1:cout << "1.��ɽɽ��\t0.����" << endl; break;
		case 2:cout << "1.��ɽɽ��\t2.��ɽɽ´\t0.����" << endl; break;
		case 3:cout << "1.��ɽɽ��\t2.��ɽɽ´\t3.��ɽ���\t0.����" << endl; break;
		case 4:cout << "1.��ɽɽ��\t2.��ɽɽ´\t3.��ɽ���\t4.��ɽɽ��\t0.����" << endl;
		}
		cout << "��������ѡ��ĵص㣺";
		int choice = 1;
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
						Monster monster = Monster("����", "��ͨ����");
						system("pause");
						fighting fight = fighting(&monster, gamer, point);

						break;
					}
					else
					{
						Monster monster = Monster("����", "��ͨ����");
						system("pause");
						fighting fight = fighting(&monster, gamer, point);
						break;
					}
				}
				case 2:
				{
					if (taskState > 1)
					{
						cout << smalllayerintroduction[1] << endl;
						Monster monster = Monster("������", "��ͨ����");
						system("pause");
						fighting fight = fighting(&monster, gamer, point);

						break;
					}
					else
					{
						Monster monster = Monster("������", "��ͨ����");
						system("pause");
						fighting fight = fighting(&monster, gamer, point);
						break;
					}
				}
				case 3:
				{
					if (taskState > 2)
					{
						cout << smalllayerintroduction[2] << endl;
						Monster monster = Monster("����", "��ͨ����");
						system("pause");
						fighting fight = fighting(&monster, gamer, point);

						break;
					}
					else
					{
						Monster monster = Monster("����", "��ͨ����");
						system("pause");
						fighting fight = fighting(&monster, gamer, point);
						break;
					}
				}
				case 4:
				{
					if (taskState > 3)
					{
						cout << smalllayerintroduction[3] << endl;
						Monster monster = Monster("��ɽ�Ϲ�", "��ͨ����");
						system("pause");
						fighting fight = fighting(&monster, gamer, point);

						break;
					}
					else
					{
						Monster monster = Monster("��ɽ�Ϲ�", "��ͨ����");
						system("pause");
						fighting fight = fighting(&monster, gamer, point);
						break;
					}
				}
				case 0:
				{
					break;
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
		if (choice == 0)
		{
			break;
		}
	}
}
