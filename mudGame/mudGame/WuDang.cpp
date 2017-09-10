#include"WuDang.h"
WuDang::WuDang(string layername, task* point, Character *gamer) :layer(layername), point(point), ifFinishTask(false) {
	changelayerintroduction("");
	changetreasure("����");

	smalllayerintroduction[0] = "���������䵱ɽ�£��������ھ��б����ᡣ\nС��������Ҫ��Ҫ�����μӱ��䣿������Ƽ��������ڶ���֣�ǧ���ѷ�ı���û��ᰡ��ֻҪ�������Ӽ��ɱ�������ʤ�߻��л����Ϊ��һ������������\n�ң����������˽Ӵ������ܵõ�������Ϣ�����ã��鷳����ұ���������ѩɽ���ҡ�\nROUND ONE�����ھֶ��֡�������ͷ\n����ͷ����������������С��������һ���ɣ�\n";
	smalllayerintroduction[1] = "С����ѩɽ�ɻ�ʤ��\nRUOND TWO�Ի��Ŷ��֡�����ȸ����\n��ȸ�������ҽ̽�������������Υ����С�ֵܣ����ɣ�\n";
	smalllayerintroduction[2] = "С����ѩɽ�ɻ�ʤ��\nROUND THREE�����¶��֡����տշ���\n�տշ��ɣ������ӷ��������ա�\n";
	smalllayerintroduction[3] = "С����ѩɽ�ɻ�ʤ��\nROUND FOUR ��Ȯ�ɶ��֡��������\n�������߾������200������̩ɽѹ����\n";
	smalllayerintroduction[4] = "С����ѩɽ�ɻ�ʤ��\nROUND FIVE �����Ŷ��֡��������̣��У�\n�����̣��������ò�����ȣ��������ˣ������ҵ��ɷ�ɣ�\n";
	smalllayerintroduction[5] = "�����5λ����֮���ұ�ӭ��ɽ�������ڼ���������������\n���������䵱������������������㸸ĸ����ķ緶����\n�ң�ǰ������֪���Ҹ�ĸ�����飿\n����ǰ���ǰЩ�컹ȥ�������أ�˭֪��ѩɽ�ɳ�����ô�����ѹ��������ء�\n�ң�ԭ����������....\n����ǵġ���ĸ�ĸ�������������ֵĸ��֣���Σ�����������������ж��кܺõĿڱ�������16��ǰ������ȴ������һ׮ı�永������ô����������һֱ�����㣬Ҳ����ȴ���˵�һ׮��Ը�ɡ�˭֪....��....�������Ǳ�ħ���ݺ�����ȴû���õ�֤����֤�����ǵ���ף����ǲ�����������ħ�����Ҹ�ȼ����ʦ��Ҳ���п�������ħ�����в�֪���Ƿ���ǰȥħ��Ѱ��֤�ݵ�Ը���أ�\n";
	smalllayerintroduction[6] = "***ѡ��\n1.1���ã��Ҽ���ǰ��ħ�̾�ַ��̽Ѱʦ���븸ĸ�������࣬������һ���𸴣�\n1.2:�����ղ�������������ͬħ��ս������Ը��ͬʦ��һ��ص�ѩɽ�ɼ���������������ѧ������ߺ��ٱ���Ҳ������Сʦ�þ��鿪�������˻�ȥ������������¡����ˣ������ڵġ���Ϸ������һ�������ǳ�޵İ��飩\n2.1:�ã��Ҽ���ǰ��ħ�̾�ַ��̽Ѱʦ���븸ĸ�������࣬������һ���𸴣�\n2.2:�����黹������Ƿȱ�����������Ȼ�ѩɽ�ɱ���������������������������ȥͬħ���������ˣ��������Сʦ�ñ�ץ�ߣ����ּ��������ħ���йأ��Ҿ���ȥ���ɽ�Ȼ�Сʦ�ã�\n100%�õ�����������\n�Ϲǳ�ǹ��   ����+22  ������+2%   ������-1% ��������ʱ3%�ļ���ʹ���˴��ڳ�Ѫ״̬\n�������磺   ����+35 �ر� +5% ����ֵ+200\n";
	
	monstername[0] = "����ͷ";
	monstername[1] = "��ȸ����";
	monstername[2] = "�տշ���";
	monstername[3] = "�����";
	monstername[4] = "������";
	
	smalllayer[0] = "";
	smalllayer[1] = "��ɽɽ´";
	smalllayer[2] = "��ɽ���";
	smalllayer[3] = "";
	operate(gamer);
}
WuDang::~WuDang() {

}
void WuDang::judgeTask() {
	if (point->getNowTask() > 10)
	{
		ifFinishTask = true;
	}
}
void WuDang::move(int i) {
	system("cls");
	cout << smalllayer[i] << endl;
	movestep(i);
	gettreasure();
}

void WuDang::operate(Character * gamer)
{
	while (true)
	{
		int taskState = point->getNowTask();
		switch (taskState)
		{
		case 5:cout << "1.��̨Ҽ\t0.����" << endl; break;
		case 6:cout << "1.��̨Ҽ\t2.��̨��\t0.����" << endl; break;
		case 7:cout << "1.��̨Ҽ\t2.��̨��\t3.��̨��\t0.����" << endl; break;
		case 8:cout << "1.��̨Ҽ\t2.��̨��\t3.��̨��\t4.��̨��\t0.����" << endl; break;
		default:cout << "1.��̨Ҽ\t2.��̨��\t3.��̨��\t4.��̨��\t4.��̨��\t0.����" << endl;
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
						Monster monster = Monster("����ͷ", "��ͨ����");
						system("pause");
						fighting fight = fighting(&monster, gamer, point);

						break;
					}
					else
					{
						Monster monster = Monster("����ͷ", "��ͨ����");
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
						Monster monster = Monster("��ȸ����", "��ͨ����");
						system("pause");
						fighting fight = fighting(&monster, gamer, point);

						break;
					}
					else
					{
						Monster monster = Monster("��ȸ����", "��ͨ����");
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
						Monster monster = Monster("�տշ���", "��ͨ����");
						system("pause");
						fighting fight = fighting(&monster, gamer, point);

						break;
					}
					else
					{
						Monster monster = Monster("�տշ���", "��ͨ����");
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
						Monster monster = Monster("�����", "��ͨ����");
						system("pause");
						fighting fight = fighting(&monster, gamer, point);

						break;
					}
					else
					{
						Monster monster = Monster("�����", "��ͨ����");
						system("pause");
						fighting fight = fighting(&monster, gamer, point);
						break;
					}
				}
				case 5:
				{
					if (taskState > 3)
					{
						cout << smalllayerintroduction[3] << endl;
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
