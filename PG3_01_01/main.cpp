#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>
#include<list>
#include<string>
#include<iostream>
using namespace std;



int main() {

	

	list<string> yamanoteLine{
		"Tokyo","Kanda","Akihabara","Okachimachi","Ueno","Uguisudani","Nippori","Tabata","Komagome",
		"Sugamo","Otsuka","Ikebukuro","Mejiro","Takadanobaba","Shin-Okubo","Shinjuku","Yoyogi","Harajuku",
		"Shibuya","Ebisu","Meguro","Gotanda","Osaki","Shinagawa","Tamachi","Hamamatsucho","Shimbashi","Yurakucho"};

	list<string>::iterator itr = yamanoteLine.begin();
	
	//1970の駅一覧
	printf("1970年の山手線一覧\n");
	for (auto i = yamanoteLine.begin(); i != yamanoteLine.end(); i++) {
		cout << *i << "\n";
		
	}

	for (list<string>::iterator i = yamanoteLine.begin(); i != yamanoteLine.end(); i++) {
		//田端の前に西日暮里を追加
		if (*i == "Tabata") {
			i = yamanoteLine.insert(i, "Nishi-Nippori");
			++i;
		}
	}

	//2019の駅一覧
	printf("2019年の山手線一覧\n");
	for (auto i = yamanoteLine.begin(); i != yamanoteLine.end(); i++) {
		cout << *i << "\n";
		
	}

	for (list<string>::iterator i = yamanoteLine.begin(); i != yamanoteLine.end(); i++) {
		//田町の前に高輪ゲートウェイを追加
		if (*i == "Tamachi") {
			i = yamanoteLine.insert(i, "Takanawa Gateway");
			++i;
		}
	}

	//2022の駅一覧
	printf("2022年の山手線一覧\n");
	for (auto i = yamanoteLine.begin(); i != yamanoteLine.end(); i++) {
		cout << *i << "\n";
	}

	return 0;
}