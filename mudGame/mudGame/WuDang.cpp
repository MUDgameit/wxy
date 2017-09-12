#include"WuDang.h"
WuDang::WuDang(string layername, task* point, Character *gamer) :layer(layername), point(point), ifFinishTask(false)
{
    system("cls");
    changelayerintroduction("");
    changetreasure("����");

    smalllayerintroduction[0] = "���������䵱ɽ�£��������ھ��б����ᡣ\nС��������Ҫ��Ҫ�����μӱ��䣿������Ƽ��������ڶ���֣�ǧ���ѷ�ı���û��ᰡ��ֻҪ�������Ӽ��ɱ�������ʤ�߻��л����Ϊ��һ������������\n�ң����������˽Ӵ������ܵõ�������Ϣ�����ã��鷳����ұ���������ѩɽ���ҡ�\nROUND ONE�����ھֶ��֡�������ͷ\n����ͷ����������������С��������һ���ɣ�\n";
    smalllayerintroduction[1] = "С����ѩɽ�ɻ�ʤ��\nRUOND TWO�Ի��Ŷ��֡�����ȸ����\n��ȸ�������ҽ̽�������������Υ����С�ֵܣ����ɣ�\n";
    smalllayerintroduction[2] = "С����ѩɽ�ɻ�ʤ��\nROUND THREE�����¶��֡����տշ���\n�տշ��ɣ������ӷ��������ա�\n";
    smalllayerintroduction[3] = "С����ѩɽ�ɻ�ʤ��\nROUND FOUR ��Ȯ�ɶ��֡��������\n�������߾������200������̩ɽѹ����\n";
    smalllayerintroduction[4] = "С����ѩɽ�ɻ�ʤ��\nROUND FIVE �����Ŷ��֡��������̣��У�\n�����̣��������ò�����ȣ��������ˣ������ҵ��ɷ�ɣ�\n";
    smalllayerintroduction[5] = "�����5λ����֮���ұ�ӭ��ɽ�������ڼ���������������\n���������䵱������������������㸸ĸ����ķ緶����\n�ң�ǰ������֪���Ҹ�ĸ�����飿\n����ǰ���ǰЩ�컹ȥ�������أ�˭֪��ѩɽ�ɳ�����ô�����ѹ��������ء�\n�ң�ԭ����������....\n����ǵġ���ĸ�ĸ�������������ֵĸ��֣���Σ�����������������ж��кܺõĿڱ�������16��ǰ������ȴ������һ׮ı�永������ô����������һֱ�����㣬Ҳ����ȴ���˵�һ׮��Ը�ɡ�˭֪....��....�������Ǳ�ħ���ݺ�����ȴû���õ�֤����֤�����ǵ���ף����ǲ�����������ħ�����Ҹ�ȼ����ʦ��Ҳ���п�������ħ�����в�֪���Ƿ���ǰȥħ��Ѱ��֤�ݵ�Ը���أ�\n";
    smalllayerintroduction[6] = "***ѡ��\n1���ã��Ҽ���ǰ��ħ�̾�ַ��̽Ѱʦ���븸ĸ�������࣬������һ���𸴣�\n2:�����ղ�������������ͬħ��ս������Ը��ͬʦ��һ��ص�ѩɽ�ɼ���������������ѧ������ߺ��ٱ���Ҳ������Сʦ�þ��鿪�������˻�ȥ������������¡����ˣ������ڵġ���Ϸ������һ�������ǳ�޵İ��飩\n100%�õ�����������\n�Ϲǳ�ǹ��   ����+22  ������+2%   ������-1% ��������ʱ3%�ļ���ʹ���˴��ڳ�Ѫ״̬\n�������磺   ����+35 �ر� +5% ����ֵ+200\n";
    smalllayerintroduction[7] = "***ѡ��\n1:�ã��Ҽ���ǰ��ħ�̾�ַ��̽Ѱʦ���븸ĸ�������࣬������һ���𸴣�\n2:�����黹������Ƿȱ�����������Ȼ�ѩɽ�ɱ���������������������������ȥͬħ���������ˣ��������Сʦ�ñ�ץ�ߣ����ּ��������ħ���йأ��Ҿ���ȥ���ɽ�Ȼ�Сʦ�ã�\n100%�õ�����������\n�Ϲǳ�ǹ��   ����+22  ������+2%   ������-1% ��������ʱ3%�ļ���ʹ���˴��ڳ�Ѫ״̬\n�������磺   ����+35 �ر� +5% ����ֵ+200\n";


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
WuDang::~WuDang()
{

}
void WuDang::judgeTask()
{
    if (point->getNowTask() > 10)
    {
        ifFinishTask = true;
    }
}
void WuDang::move(int i)
{
    system("cls");
    cout << smalllayer[i] << endl;
    movestep(i);
    gettreasure();
}

void WuDang::operate(Character * gamer)
{
    int mapFlag = 1;
    while (true)
    {
        system("cls");
        int taskState = point->getNowTask();
        switch (taskState)
        {
        case 5:
            cout << "1.��̨Ҽ\t0.����" << endl;
            mapFlag = 1;
            break;
        case 6:
            cout << "1.��̨Ҽ\t2.��̨��\t0.����" << endl;
            mapFlag = 2;
            break;
        case 7:
            cout << "1.��̨Ҽ\t2.��̨��\t3.��̨��\t0.����" << endl;
            mapFlag = 3;
            break;
        case 8:
            cout << "1.��̨Ҽ\t2.��̨��\t3.��̨��\t4.��̨��\t0.����" << endl;
            mapFlag = 4;
            break;
        default:
            cout << "1.��̨Ҽ\t2.��̨��\t3.��̨��\t4.��̨��\t5.��̨��\t0.����" << endl;
            mapFlag = 5;
        }
        cout << "��������ѡ��ĵص㣺";
        int choice = 1;
        try
        {
            if (cin >> choice)
            {
                if(choice > mapFlag || choice < 0)
                    break;
                else
                {
                    switch (choice)
                    {
                    case 1:
                    {
                        if (taskState == 5)
                        {
                            cout << smalllayerintroduction[0] << endl;
                            Monster monster = Monster("����ͷ", "��ͨ����","��ӥ֮צ");
                            system("pause");
                            fighting fight = fighting(&monster, gamer, point,5);


                            break;
                        }
                        else
                        {
                            Monster monster = Monster("����ͷ", "��ͨ����", "���ȵĸ���ذ��");
                            system("pause");
                            fighting fight = fighting(&monster, gamer, point,5);
                            break;
                        }
                    }
                    case 2:
                    {
                        if (taskState == 6)
                        {
                            cout << smalllayerintroduction[1] << endl;
                            Monster monster = Monster("��ȸ����", "��ͨ����", "Ů������ذ��");
                            system("pause");
                            fighting fight = fighting(&monster, gamer, point,6);

                            break;
                        }
                        else
                        {
                            Monster monster = Monster("��ȸ����", "��ͨ����", "��Ƥ����");
                            system("pause");
                            fighting fight = fighting(&monster, gamer, point,6);
                            break;
                        }
                    }
                    case 3:
                    {
                        if (taskState == 7)
                        {
                            cout << smalllayerintroduction[2] << endl;
                            Monster monster = Monster("�տշ���", "��ͨ����", "����ʯ��ǹ");
                            system("pause");
                            fighting fight = fighting(&monster, gamer, point,7);

                            break;
                        }
                        else
                        {
                            Monster monster = Monster("�տշ���", "��ͨ����", "ī�ֻ���");
                            system("pause");
                            fighting fight = fighting(&monster, gamer, point,7);
                            break;
                        }
                    }
                    case 4:
                    {
                        if (taskState == 8)
                        {
                            cout << smalllayerintroduction[3] << endl;
                            Monster monster = Monster("�����", "��ͨ����", "��������");
                            system("pause");
                            fighting fight = fighting(&monster, gamer, point,8);

                            break;
                        }
                        else
                        {
                            Monster monster = Monster("�����", "��ͨ����", "ѩ֮����");
                            system("pause");
                            fighting fight = fighting(&monster, gamer, point,8);
                            break;
                        }
                    }
                    case 5:
                    {
                        if (taskState == 9)
                        {
                            cout << smalllayerintroduction[4] << endl;
                            Monster monster = Monster("������", "��ͨ����", "�ڽ�����");
                            system("pause");
                            fighting fight = fighting(&monster, gamer, point,9);
                            cout << smalllayerintroduction[5] << endl;
                            if (point->getTaskInformation(0))
                                cout << smalllayerintroduction[6] << endl;
                            else
                                cout << smalllayerintroduction[7] << endl;
                            int taskChoice;
                            while(cout <<"���������ѡ��") {
                                if(cin >> taskChoice) {
                                    if(taskChoice == 1 || taskChoice == 2) {
                                        point->finishNowTask(taskChoice);
                                        break;
                                    }
                                    else
                                        cout << "���벻���Ϲ淶������������1-2" << endl;
                                }
                            }
                        }
                        else
                        {
                            Monster monster = Monster("������", "��ͨ����", "��������");
                            system("pause");
                            fighting fight = fighting(&monster, gamer, point,9);
                            break;
                        }
                    }
                    case 0:
                    {
                        break;
                    }
                    default:
                        throw Error("���벻���Ϲ淶������������1-2");
                    }
                }
            }
            else
            {
                throw Error("���벻���Ϲ淶������������1-2");
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
        }
        if (choice == 0 || choice == 5)
        {
            break;
        }
    }
}
