#include"DemonMountain.h"
DemonMountain::DemonMountain(string layername, task* point) :layer(layername), point(point), ifFinishTask(false) {
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
	HANDLE consolehwnd;
	consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consolehwnd, 11);
	cout << smalllayer[i] << endl;
	movestep(i);
	gettreasure();
}