#pragma once
#include"Weapon.h"
#include<iostream>
#include<string>
using namespace std;
class Bag {
private:
	int number;
	Weapon ** weapon;
public:
	void DeleteWeapon(string name);
	void AddWeapon(string name);
	void ShowWeapon();
	Bag();
};