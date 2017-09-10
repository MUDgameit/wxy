#include"DemonMountain.h"
DemonMountain::DemonMountain(string layername, task* point, Character *gamer) :layer(layername), point(point), ifFinishTask(false) {
	changelayerintroduction("");
	changetreasure("����");

	smalllayerintroduction[0] = "�ҵ������ɽ��������ħ�̽��ں����ؽ����ݡ����Ǽ�һ������������Ű׵��·���������˵�Ϳ�ʼͬ��ս����\n";
	smalllayerintroduction[1] = "";
	smalllayerintroduction[2] = "";
	smalllayerintroduction[3] = "ħ�̻��������죬��ȥ��������\n";
	smalllayerintroduction[4] = "";
	smalllayerintroduction[5] = "��������\n�ң����㵱�꺦�Ҹ�ĸ�������ɱ��ʦ����\n�������𣬹�����������\n";
	smalllayerintroduction[6] = "���˽�����������������\n2.2�Ӳ��У������˱���ס����浡���\n�ң���浣���û�°ɡ�\n��浣�û�£�����ץ���һ���Ϊ�˱�����������Ǻ�����Ϊ������ǵ���в�ܴ󣬿��ܻ���������֣���һ��Ҫ���С�ġ�\n�ң��á�\n***ѡ���Ƿ�ȥ��������Ѱ��������\n1��ȥ�������Է���Ѱ��������\n2.2:�ң�����ȥ�����������￴�����Ƿ�����е���������Ϣ������һ��ȥ�ɡ�\n���������:����Ӧ��ȥ���ҵ���������������ڽ����������\n���������������￪ʼ���ҡ�\n�ң����ó�һ���ţ��⡭.Ī���ǵ���α���ͨ�����飿\n�������ң����ŷ⸽���ҵ���α��ĸ���ͼ�¡�\n�ң����ǡ���Ȼ��˺ݶ����������Ҫ���Ҹ�ĸ�ڲ��Ҳ��壡\n����������Сʦ�ã�ʦ���ĵ��Ӿ���Сʦ����������ҵ������������Լ��ҵ�����\n�ң��������ŵ��ӣ�ʦ���������ң���Ȼû�з�������ĵ��Ӷ���ħ�������ˡ������ģ���һ����ץ��ɱ�����Ĵ��ˣ�������Ѫȥ��������\n�ڷ��������ҵ���һЩ����ͨ�ţ�����֤����ĸ����ס��������鷵���䵱ɽ��ȴ����֪�����Ѿ�ǰ�����ɽ��ȥ���ɽѰ�����\n�����������ҵ��ܹǳ�ǹ��ϡ��װ������ ����+40  ������+2%   ������-1%   ���ܹ�����+10%\n2������Ѱ��������\nֱ�ӷ����䵱ɽ��ȴ����֪�����Ѿ�ǰ�����ɽ��ȥ���ɽѰ�����\n";

	monstername[0] = "ħ�̻���Ҽ";
	monstername[1] = "ħ�̻�����";
	monstername[2] = "ħ�̻�����";
	monstername[3] = "ħ�̻�����";
	monstername[4] = "ħ�̻�����";
	monstername[5] = "ħ�̽���";

}
DemonMountain::~DemonMountain() {

}
void DemonMountain::judgeTask() {
	if (point->getNowTask() > 10)
	{
		ifFinishTask = true;
	}
}
void DemonMountain::move(int i) {
	system("cls");
	cout << smalllayer[i] << endl;
	movestep(i);
	gettreasure();
}

void DemonMountain::operate(Character *gamer)
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
