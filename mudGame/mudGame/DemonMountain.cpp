#include"DemonMountain.h"
DemonMountain::DemonMountain(string layername, task* point, Character *gamer) :layer(layername), point(point), ifFinishTask(false) {
	changelayerintroduction("");
	changetreasure("武器");

	smalllayerintroduction[0] = "我到了睥睨山，正看见魔教教众合力重建房屋。他们见一外来人物，又身着白道衣服，二话不说就开始同我战斗。\n";
	smalllayerintroduction[1] = "";
	smalllayerintroduction[2] = "";
	smalllayerintroduction[3] = "魔教护法叁：快，快去禀报教主\n";
	smalllayerintroduction[4] = "";
	smalllayerintroduction[5] = "教主出现\n我：是你当年害我父母，如今又杀我师父吗？\n教主不答，攻击更加猛烈\n";
	smalllayerintroduction[6] = "重伤教主，教主带伤逃走\n2.2从柴房中，发现了被捆住的清娴——\n我：清娴，你没事吧。\n清娴：没事，他们抓了我还是为了逼你过来。他们好像认为你对他们的威胁很大，可能还会对你下手，你一定要多加小心。\n我：好。\n***选择：是否去教主卧室寻找线索？\n1：去教主旧卧房找寻线索——\n2.2:我：我想去教主的卧室里看看，是否会留有当年的相关信息，和我一起去吧。\n其他情况我:我们应该去找找当年的线索。或许在教主的卧室里。\n来到教主的卧室里开始翻找。\n我：（拿出一封信）这….莫不是当年伪造的通信文书？\n继续翻找，在信封附近找到了伪造的各种图章。\n我：他们…竟然如此狠毒！这分明是要陷我父母于不忠不义！\n（如果身边有小师妹，师父的笛子就由小师妹在书架上找到，否则由我自己找到。）\n我：（抚摸着笛子）师父…都怪我，竟然没有发现您最爱的笛子都被魔教拿走了…您放心，我一定会抓到杀害您的歹人，用他的血去祭奠您！\n在房间中又找到了一些往来通信，足以证明父母的清白。带着文书返回武当山，却被告知钟宇已经前往青城山。去青城山寻找钟宇。\n教主房间内找到熊骨长枪（稀有装备）： 力量+40  暴击率+2%   命中率-1%   技能攻击力+10%\n2：放弃寻找线索。\n直接返回武当山，却被告知钟宇已经前往青城山。去青城山寻找钟宇。\n";

	monstername[0] = "魔教护法壹";
	monstername[1] = "魔教护法贰";
	monstername[2] = "魔教护法叁";
	monstername[3] = "魔教护法肆";
	monstername[4] = "魔教护法伍";
	monstername[5] = "魔教教主";

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
		case 1:cout << "1.天山山脚\t0.返回" << endl; break;
		case 2:cout << "1.天山山脚\t2.天山山麓\t0.返回" << endl; break;
		case 3:cout << "1.天山山脚\t2.天山山麓\t3.天山天池\t0.返回" << endl; break;
		case 4:cout << "1.天山山脚\t2.天山山麓\t3.天山天池\t4.天山山顶\t0.返回" << endl;
		}
		cout << "请输入你选择的地点：";
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
						Monster monster = Monster("陶云", "普通攻击");
						system("pause");
						fighting fight = fighting(&monster, gamer, point);

						break;
					}
					else
					{
						Monster monster = Monster("陶云", "普通攻击");
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
						Monster monster = Monster("孙泽翼", "普通攻击");
						system("pause");
						fighting fight = fighting(&monster, gamer, point);

						break;
					}
					else
					{
						Monster monster = Monster("孙泽翼", "普通攻击");
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
						Monster monster = Monster("璃音", "普通攻击");
						system("pause");
						fighting fight = fighting(&monster, gamer, point);

						break;
					}
					else
					{
						Monster monster = Monster("璃音", "普通攻击");
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
						Monster monster = Monster("天山老怪", "普通攻击");
						system("pause");
						fighting fight = fighting(&monster, gamer, point);

						break;
					}
					else
					{
						Monster monster = Monster("天山老怪", "普通攻击");
						system("pause");
						fighting fight = fighting(&monster, gamer, point);
						break;
					}
				}
				case 0:
				{
					break;
				}
				default:throw Error("输入不符合规范，请输入数字1-4");
				}
			}
			else
			{
				throw Error("输入不符合规范，请输入数字1-4");
			}
		}
		catch (Error &e) {
			// 读到非法字符后，输入流将处于出错状态，
			// 为了继续获取输入，首先要调用 clear 函数
			cin.clear();
			// numeric_limits<streamsize>::max() 返回输入缓冲的大小。
			// ignore 函数在此将把输入流中的数据清空。
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			cout << e.what() << endl;
		}
		if (choice == 0)
		{
			break;
		}
	}
}
