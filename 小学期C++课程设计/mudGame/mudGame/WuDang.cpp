#include"WuDang.h"
WuDang::WuDang(string layername, task* point) :layer(layername), point(point), ifFinishTask(false) {
	changelayerintroduction("");
	changetreasure("武器");

	smalllayerintroduction[0] = "我来到了武当山下，那里正在举行比武大会。\n小二：少侠要不要报名参加比武？这里可云集了武林众多高手，千载难逢的比武好机会啊！只要二两银子即可报名，获胜者还有机会成为下一任武林盟主！\n我：（和其他人接触或许能得到更多消息。）好，麻烦你帮我报名，我是雪山派我。\nROUND ONE龙门镖局对手——樊镖头\n樊镖头：从哪里来的无名小辈？吃我一锤吧！\n";
	smalllayerintroduction[1] = "小二：雪山派我获胜！\nRUOND TWO辉煌门对手——尚雀护法\n尚雀：哎，我教教主有命，不敢违抗，小兄弟，来吧！\n";
	smalllayerintroduction[2] = "小二：雪山派我获胜！\nROUND THREE少林寺对手——空空方丈\n空空方丈：阿弥陀佛，善哉善哉。\n";
	smalllayerintroduction[3] = "小二：雪山派我获胜！\nROUND FIVE 断袖门对手——宫涵蕴（男）\n宫涵蕴：看你肤白貌美大长腿，若是输了，就做我的丈夫吧！\n";
	smalllayerintroduction[4] = "打败了5位对手之后，我被迎上山来，终于见到了武林盟主。\n武林盟主武当派掌门人钟宇：果真有你父母当年的风范啊。\n我：前辈，您知道我父母的事情？\n钟宇：是啊，前些天还去看你了呢，谁知道雪山派出了这么令人难过的事情呢。\n我：原来，您就是....\n钟宇：是的。你的父母当年是名震武林的高手，扶危助困，在整个武林中都有很好的口碑。但是16年前，他们却卷入了一桩谋逆案件。这么多年来，我一直在找你，也算了却故人的一桩心愿吧。谁知....哎....当年他们被魔教陷害，我却没能拿到证据来证明他们的清白，真是惭愧啊！而今魔教死灰复燃，你师父也极有可能死于魔教手中不知你是否有前去魔教寻找证据的愿望呢？\n";
	smalllayerintroduction[5] = "***选择\n1.1：好！我即日前往魔教旧址，探寻师父与父母死因真相，给他们一个答复！\n1.2:晚辈武艺不精，恐怕难以同魔教战斗。我愿意同师妹一起回到雪山派继续修炼，待到武学有了提高后再报仇也不晚。（小师妹剧情开启，二人回去后解决了终身大事。仇人？不存在的。游戏进入结局一——忘记仇恨的爱情）\n2.1:好！我即日前往魔教旧址，探寻师父与父母死因真相，给他们一个答复！\n2.2:晚辈经验还是有所欠缺，我正考虑先回雪山派闭门修炼，待到武艺有所精进再去同魔教众人算账！（两年后，小师妹被抓走，种种迹象表明与魔教有关，我决定去睥睨山救回小师妹）\n100%得到钟宇馈赠：\n断骨长枪：   力量+22  暴击率+2%   命中率-1% 攻击敌人时3%的几率使敌人处于出血状态\n精铁护肩：   防御+35 回避 +5% 生命值+200\n";
	
	monstername[0] = "樊镖头";
	monstername[1] = "尚雀护法";
	monstername[2] = "空空方丈";
	monstername[3] = "宫涵蕴";
	
	/*smalllayer[0] = "天山山脚";
	smalllayer[1] = "天山山麓";
	smalllayer[2] = "天山天池";
	smalllayer[3] = "";*/
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
	HANDLE consolehwnd;
	consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consolehwnd, 11);
	cout << smalllayer[i] << endl;
	movestep(i);
	gettreasure();
}