#include"DemonMountain.h"
DemonMountain::DemonMountain(string layername, task* point, Character *gamer) :layer(layername), point(point), ifFinishTask(false) {
	system("cls");
	changelayerintroduction("");
	changetreasure("����");

	smalllayerintroduction[0] = "�ҵ������ɽ��������ħ�̽��ں����ؽ����ݡ����Ǽ�һ������������Ű׵��·���������˵�Ϳ�ʼͬ��ս����\n";
	smalllayerintroduction[1] = "ħ�̻��������죬��ȥ��������\n";
	smalllayerintroduction[2] = "��������\n�ң����㵱�꺦�Ҹ�ĸ�������ɱ��ʦ����\n�������𣬹�����������\n";
	smalllayerintroduction[3] = "���˽�����������������\n";
	smalllayerintroduction[4] = "�Ӳ��У������˱���ס����浡���\n�ң���浣���û�°ɡ�\n��浣�û�£�����ץ���һ���Ϊ�˱�����������Ǻ�����Ϊ������ǵ���в�ܴ󣬿��ܻ���������֣���һ��Ҫ���С�ġ�\n�ң��á�\n";
	smalllayerintroduction[5] = "***ѡ���Ƿ�ȥ��������Ѱ�����������ܻ�����Σ�գ�����\n1����\t2������Ѱ��������\n";
	smalllayerintroduction[6] = "����Ӧ��ȥ���ҵ���������������ڽ����������\n���������������￪ʼ���ҡ�\n�ң����ó�һ���ţ��⡭.Ī���ǵ���α���ͨ�����飿\n�������ң����ŷ⸽���ҵ���α��ĸ���ͼ�¡�\n�ң����ǡ���Ȼ��˺ݶ����������Ҫ���Ҹ�ĸ�ڲ��Ҳ��壡\n�ң��������ŵ��ӣ�ʦ���������ң���Ȼû�з�������ĵ��Ӷ���ħ�������ˡ������ģ���һ����ץ��ɱ�����Ĵ��ˣ�������Ѫȥ��������\n�ڷ��������ҵ���һЩ����ͨ�ţ�����֤����ĸ����ס��������鷵���䵱ɽ��ȴ����֪�����Ѿ�ǰ�����ɽ��ȥ���ɽѰ�����\n�����������ҵ��ܹǳ�ǹ��ϡ��װ������ ����+40  ������+2%   ������-1%   ���ܹ�����+10%\n";
	smalllayerintroduction[7] = "ֱ�ӷ����䵱ɽ��ȴ����֪�����Ѿ�ǰ�����ɽ��ȥ���ɽѰ�����\n";

	monstername[0] = "ħ�̻���Ҽ";
	monstername[1] = "ħ�̻�����";
	monstername[2] = "ħ�̻�����";
	monstername[3] = "ħ�̻�����";
	monstername[4] = "ħ�̻�����";
	monstername[5] = "ħ�̽���";
	operate(gamer);
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
	int choice = 0;
	while (true)
	{
		system("cls");
		int taskState = point->getNowTask();
		try
		{
			cout << smalllayerintroduction[0] << endl;
			Monster monster1("ħ�̻���Ҽ", "��ͨ����","�һ�������");
			system("pause");
			fighting fight1 = fighting(&monster1, gamer, point,11);
			Monster monster2("ħ�̻�����", "��ͨ����", "��Ѫ�ȼ�");
			fighting fight2 = fighting(&monster2, gamer, point,11);
			Monster monster3("ħ�̻�����", "��ͨ����", "��ս���");
			fighting fight3 = fighting(&monster3, gamer, point,11);
			cout << smalllayerintroduction[1] << endl;
			system("pause");
			Monster monster4("ħ�̻�����", "��ͨ����", "��ɴ����");
			fighting fight4 = fighting(&monster4, gamer, point,11);
			Monster monster5("ħ�̻�����", "��ͨ����", "�������ؼ�");
			fighting fight5 = fighting(&monster5, gamer, point,11);
			cout << smalllayerintroduction[2] << endl;
			Monster monster6("ħ�̽���", "��ͨ����", "�Ϲǳ�ǹ");
			cout << smalllayerintroduction[3] << endl;
			cout << smalllayerintroduction[4] << endl;
			cout << smalllayerintroduction[5] << endl;
			while(cout <<"���������ѡ��") {
                if(cin >> choice) {
                    if(choice == 1 || choice == 2) {
                        point->finishTask(12);
                        point->finishTask(13);
                        break;
                    }
                    else
                        cout << "���벻���Ϲ淶������������1-2" << endl;
                }
            }
			if (choice == 1)
			{
				cout << smalllayerintroduction[6] << endl;
			}
			else
			{
				cout << smalllayerintroduction[7] << endl;

			}
			point->finishNowTask(14);
			break;
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

		break;

	}
}
