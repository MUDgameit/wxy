#include"GreenCityMountain.h"
GreenCityMountain::GreenCityMountain(string layername, task* point) :layer(layername), point(point), ifFinishTask(false) {
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
	HANDLE consolehwnd;
	consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consolehwnd, 11);
	cout << smalllayer[i] << endl;
	movestep(i);
	gettreasure();
}