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
	
	//1970�̉w�ꗗ
	printf("1970�N�̎R����ꗗ\n");
	for (auto i = yamanoteLine.begin(); i != yamanoteLine.end(); i++) {
		cout << *i << "\n";
		
	}

	for (list<string>::iterator i = yamanoteLine.begin(); i != yamanoteLine.end(); i++) {
		//�c�[�̑O�ɐ����闢��ǉ�
		if (*i == "Tabata") {
			i = yamanoteLine.insert(i, "Nishi-Nippori");
			++i;
		}
	}

	//2019�̉w�ꗗ
	printf("2019�N�̎R����ꗗ\n");
	for (auto i = yamanoteLine.begin(); i != yamanoteLine.end(); i++) {
		cout << *i << "\n";
		
	}

	for (list<string>::iterator i = yamanoteLine.begin(); i != yamanoteLine.end(); i++) {
		//�c���̑O�ɍ��փQ�[�g�E�F�C��ǉ�
		if (*i == "Tamachi") {
			i = yamanoteLine.insert(i, "Takanawa Gateway");
			++i;
		}
	}

	//2022�̉w�ꗗ
	printf("2022�N�̎R����ꗗ\n");
	for (auto i = yamanoteLine.begin(); i != yamanoteLine.end(); i++) {
		cout << *i << "\n";
	}

	return 0;
}