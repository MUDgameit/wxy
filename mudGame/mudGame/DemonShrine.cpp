#include"DemonShrine.h"
DemonShrine::DemonShrine(string layername, task* point,Character*gamer) :layer(layername), point(point), ifFinishTask(false) {
	system("cls");
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
	operate(gamer);
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
	int choice = 0;
	while (true)
	{
		system("cls");
		int taskState = point->getNowTask();
		
		cout << smalllayerintroduction[0] << endl;
		Monster monster1("ħ�̳���Ҽ", "��ͨ����","˫�о޽�");
		system("pause");
		fighting fight1 = fighting(&monster1, gamer, point, 11);
		Monster monster2("ħ�̳��Ϸ�", "��ͨ����", "ǧ���������ؼ�");
		fighting fight2 = fighting(&monster2, gamer, point, 11);
		Monster monster3("ħ�̳�����", "��ͨ����", "ħս�����ȼ�");
		fighting fight3 = fighting(&monster3, gamer, point, 11);
		Monster monster4("ħ�̳�����", "��ͨ����", "�鶷�ߵĲ�˿����");
		fighting fight4 = fighting(&monster4, gamer, point, 11);
		Monster monster5("ħ�̳�����", "��ͨ����", "����֮�����");
		fighting fight5 = fighting(&monster5, gamer, point, 11);

		Monster monster6("ħ�̽���", "��ͨ����", "���ܰ���");
		cout << smalllayerintroduction[6] << endl;
		cout << "��ϲͨ����" << endl;

	}
}
