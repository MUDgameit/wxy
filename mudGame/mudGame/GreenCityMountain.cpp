#include"GreenCityMountain.h"
GreenCityMountain::GreenCityMountain(string layername, task* point,Character *gamer) :layer(layername), point(point), ifFinishTask(false) {
	changelayerintroduction("");
	changetreasure("����");

	smalllayerintroduction[0] = "��ʱ��������ʿ�Ѿ�֪���ҵ����\n�����£������ӷ𣬸�λʩ�����ǲ�Ҫɱ���˰ɣ�����Ȼ���ǶԷ򸾵ĺ��ˣ��������ǲ��ܿ϶���Ҳͨ���ѹ������ο���Ҳδ����������ĸ��\n�����ھ֣��������ǲ��ܷŹ��� ������������������Ѫ������ʲôҲ�ı䲻�˵ģ�\n�Ի��ţ��Ҿ��ø�ĸ�ͺ���û�й�ϵ�ɡ���Ҫ���䣬��Ĳ�Ҫ�ˡ�\n�������ۣ����Ǿ�����Ҫն�ݳ�������ȥɽ���µȴ�����ͬ�����ɽ�ϼ���������ζԸ�ħ�̡�\n�����ھ֣��ҵ�����֮ʿ�ز���Ź����������ⰹ��ѪҺ���ˣ�\n";
	smalllayerintroduction[1] = "��Ȯ�ɣ��������Ϊ��Ȯ\n";
	smalllayerintroduction[2] = "�����ţ������㲻���ң���ֻ��ѡ��ɱ�����ˣ�\n";
	smalllayerintroduction[3] = "����ɣ�\n�����ɽѡ����1�����ó�����֤�����\n�ң���λ���ͣ���������˵���䣨�ó����֤�����Щ����Ӧ������֤���Ҹ�ĸ����׵��˰ɡ�\n�̳γȣ���������ţ���û�뵽ħ�����˾�Ȼ��˺ݶ������������ҳ��˵�������飬������������Ҫһֱ�����ⲻ��֮ԩ�ˡ����������̽��ħ�̽�������ص㣬���Ƿ�Ըͬ����һ���ַ���\n�ң��ǡ����ҷ��ģ���Ҫ����ɱ��ħ�̽�������οʦ���͸�ĸ����֮�飡\n���������곤�ۣ�ϡ��װ����������+70  �ر�+5% ����ֵ+550\n�����ɽѡ����2����ᱻɱ������Ϸ�����ֶ�����������ԩ��\n";
	
	monstername[0] = "�����ھ�";
	monstername[1] = "��Ȯ��";
	monstername[2] = "������";

	/*smalllayer[0] = "��ɽɽ��";
	smalllayer[1] = "��ɽɽ´";
	smalllayer[2] = "��ɽ���";
	smalllayer[3] = "";*/
}
GreenCityMountain::~GreenCityMountain() {

}
void GreenCityMountain::judgeTask() {
	if (point->getNowTask() > 10)
	{
		ifFinishTask = true;
	}
}
void GreenCityMountain::move(int i) {
	system("cls");
	cout << smalllayer[i] << endl;
	movestep(i);
	gettreasure();
}

void GreenCityMountain::operate(Character *gamer)
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
