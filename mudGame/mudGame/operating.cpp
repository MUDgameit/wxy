#include "operating.h"

operating::operating()
{
}

int operating::showStartMenu()
{
	int choice;
	while(cout << "1.��ʼ��Ϸ  2.��ȡ�浵  3.�˳�" << endl << "���������ѡ��") {
	    try {
            if (cin >> choice)
            {
                switch (choice)
                {
                case 1:return 1;
                case 2:return 2;
                case 3:return 0;
                default:throw Error("���벻���Ϲ淶������������1-3");
                }
            }
            else
            {
                throw Error("���벻���Ϲ淶������������1-3");
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
            system("pause");

            system("cls");
        }
	}

	return choice;
}

string operating::getGamerName()
{
	system("cls");
	string name;
	cout << "�������������ƣ�";
	try
	{
		cin >> name;
		//���Ȳ������壬�����ո�
		if (name.length() < 6 || name.find(" ") != std::string::npos)
		{
			return name;
		}
		else
		{
			throw Error("�����ɫ��Ӧ���ĳ��Ȳ������壬Ӣ�Ĳ�����ʮ���Ҳ����ո�");
		}
	}
	catch (Error &e)
	{
		// �����Ƿ��ַ��������������ڳ���״̬��
		// Ϊ�˼�����ȡ���룬����Ҫ���� clear ����
		cin.clear();
		// numeric_limits<streamsize>::max() �������뻺��Ĵ�С��
		// ignore �����ڴ˽����������е�������ա�
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		cout << e.what() << endl;
		system("pause");


		system("cls");
		this->getGamerName();
	}
}

int operating::showMainMenu(Character & gamer)
{
	cout << "��ɫ���֣�" << gamer.getName() << "\t" << "�ȼ���" << gamer.getLevel() << endl;
	cout << "������" << gamer.getLife() << "\t" << "������100" << "\t" << "���飺" << gamer.getExperience() << endl;
	cout << "������" << gamer.getWeaponName() << "\t" << "ͷ����" << gamer.getShoulderName() << "\t" <<
		"���ף�" << gamer.getChestName() << "\t" << "���ȣ�" << gamer.getLegName() << endl;
	cout << "������" << gamer.getStrength() << "\t" << "������" << gamer.getDefense() << "\t" <<
		"�����ʣ�" << gamer.getHitRate() << "\t" << "�����ʣ�" << gamer.getForceRate() << "\t" <<
		"�����ʣ�" << gamer.getAvoidRate() << "\t" << "���٣�" << gamer.getAttackSpeed() << endl;
	cout << "1.��ͼ\t2.����\t3.����\t4.�˳�" << endl;
	int choice;
	while(cout << "��������Ĳ�����1-4��" << endl) {
	    try {
            if (cin >> choice)
            {
                switch (choice)
                {
                case 1:return 1;
                case 2:return 2;
                case 3:return 3;
                case 4:return 0;
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
            system("pause");
            system("cls");
        }
        cout << "��ɫ���֣�" << gamer.getName() << "\t" << "�ȼ���" << gamer.getLevel() << endl;
        cout << "������" << gamer.getLife() << "\t" << "������100" << "\t" << "���飺" << gamer.getExperience() << endl;
        cout << "������" << gamer.getWeaponName() << "\t" << "ͷ����" << gamer.getShoulderName() << "\t" <<
            "���ף�" << gamer.getChestName() << "\t" << "���ȣ�" << gamer.getLegName() << endl;
        cout << "������" << gamer.getStrength() << "\t" << "������" << gamer.getDefense() << "\t" <<
            "�����ʣ�" << gamer.getHitRate() << "\t" << "�����ʣ�" << gamer.getForceRate() << "\t" <<
            "�����ʣ�" << gamer.getAvoidRate() << "\t" << "���٣�" << gamer.getAttackSpeed() << endl;
        cout << "1.��ͼ\t2.����\t3.����\t4.�˳�" << endl;
	}
	return 0;
}

int operating::showMap(task &myTask)
{
	int numberOfTask = myTask.getNowTask();
	if(numberOfTask < 5)
	{
		cout << "1.��ɽ" << endl;
	}
	else
	{
		if (numberOfTask < 11)
		{
			cout << "1.��ɽ\t2.�䵱" << endl;
		}
		else
		{
			if (numberOfTask < 15)
			{
				cout << "1.��ɽ\t2.�䵱\t3.ħ�����ɽ" << endl;
			}
			else
			{
				if (numberOfTask < 20)
				{
					cout << "1.��ɽ\t2.�䵱\t3.ħ�����ɽ\t4.���ɽ" << endl;
				}
				else
				{
					cout << "1.��ɽ\t2.�䵱\t3.ħ�����ɽ\t4.���ɽ\t5.ħ��ʥ��" << endl;
				}
			}
		}
	}
	cout << "��������ǰ���ĵ�ͼ������0���أ�" << endl;
	int choice;
	try {
		if (cin >> choice)
		{
		    if((numberOfTask < 5 && choice > 1) || (numberOfTask < 11 && choice > 2) || (numberOfTask < 15 && choice > 3) || (numberOfTask < 20 && choice > 4) || choice > 5) {
                cout << "�õ�ͼ�����ڣ�" << endl;
		    }
		    else {
                switch (choice)
                {
                case 1:return 1;
                case 2:return 2;
                case 3:return 3;
                case 4:return 4;
                case 5:return 5;
                case 0:return 0;
                default:throw Error("���벻���Ϲ淶������������1-5");
                }
		    }
		}
		else
		{
			throw Error("���벻���Ϲ淶������������1-5");
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

	return 0;
}

int operating::showStory(Character &amy)
{
	cout << "����һ������Ķ��졣\n";
	cin.get();
	cout << amy.getName() <<
		"�ոչ���������16�����ա���С��ĸ˫����������һ����ѩ�׷ɵĶ��ձ�ʦ������ɽ����������ġ�ʦ����ѩɽ�ɵ����ţ���Щ�����Ҳ��Ϥ�Ľ̵�������������ʦ��������һ��������ƽ��һͬϰ��Ļ�������Сʦ�ã�����浣������˸���Ҳ���൱���׺�\nһ������Ѱ�������ӣ�A����������׼�����޵�ʱ��һ����ӰͻȻ�����ڴ��⡪��\n";
	cin.get();
	cout << amy.getName() << "��˭����\n";
	cin.get();
	cout <<
		"��Ӱ�����£������㸸ĸ�Ĺ��ˣ��Ѿ�Ѱ����16���ˣ����ղŴ�ѩɽ����Ѱ���������Ϣ��\n";

	cin.get();
	cout << amy.getName() <<
		"����˵��ƾ�����ݵ��ҽ��������м����δ������ĸ����ʦ�����Ҵ�С������������ĸ����֮˵��\n";
	cin.get();
	cout <<
		"��Ӱ������˵�����Ŀ��Ƿ���һ��ɫ����̥�ǣ�\n";
	cin.get();
	cout << amy.getName() <<
		"������ô˽�ܵ��������������˵�֪����������ͬ����һ��ԨԴ����\n";
	cin.get();
	cout <<
		"��Ӱ�����ˣ��ҽ���Ҳ���ڴ˾���������ʱ���������㡣��˵�գ��������Ṧ�뿪����\n";
	cin.get();
	cout << amy.getName() <<
		"��Ҳ�գ������մ�������ʦ�������غ�����ѯʦ���ɡ�\n";
	cin.get();

	cout <<
		"ʮ�պ�......\n" << amy.getName() << "�ճ��أ���ҪȥѰʦ����ȴ������ʦ������ɱ������Ϣ����\n";
	cin.get();
	cout << amy.getName() <<
		"����....��������....ʦ��...ʦ����......����ޣ�\n";
	cin.get();
	cout <<
		"��������ƽ��Щ��" << amy.getName() << "����ʦ������ʦ�������ʱ������һö��ɫ�ӹ���׹���������ɣ��㻽��ȡ���쿴��\n";
	cin.get();
	cout << amy.getName() <<
		"����ʦ��������������ǰ��ɽ�Ϲ����߽���ʱ�����������ӹ���׹��Ϊ������ݱ�ʶ��Ī����...��\n";
	cin.get();
	cout <<
		"������������׹��" << amy.getName() << "����ȷ����ɽ�Ϲ�ͬʦ�������Ѳ��ù�ϵ��\n";
	cin.get();
	cout << amy.getName() <<
		"���ұ�Ҫ��ɽȥѰ����ɽ�Ϲ֣�Ϊʦ������\n";
	cin.get();
	cout <<
		"ʦ�ã���ͬ��һ��ȥ�ɣ����˶������Ϲ����и���İ��ա�\n";
	cin.get();
	cout <<
		"***ѡ��\n" <<
		"1���ã������Ǳ�һͬȥȡ�ǳ�����������οʦ������֮�飡\n" <<
		"2��ʦ����ȥ���������������˴������ҵ��ţ��ұ�ȡ���ǳ����׼���\n";
	cout << "�������ѡ��";
	int choice;
	while (true)
	{
		try 
		{
			if (cin >> choice)
			{
				switch (choice)
				{
				case 1:return 1;
				case 2:return 2;
				default:throw Error("���벻���Ϲ淶������������1-2");
				}
			}
			else
			{
				throw Error("���벻���Ϲ淶������������1-2");
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
	return 0;
}
