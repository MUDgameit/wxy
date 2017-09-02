#pragma once
#include<string>
using namespace std;
class layer {
public:
	void showlayer();
	string getlayername();
	void changelayername(string name);
	string getlayerintroduction();
	void changelayerintroduction(string name);
	string getmonstername();
	string gettreasure();
	string move();
private:
	string layername;
	string introduction;
	string monstername[10];
	string treasure;
};
