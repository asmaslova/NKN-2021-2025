﻿#include <iostream>
#include "Matrix.h"
using namespace std;

int main() {
	char n; //РЁС‚СѓРєР° РґР»СЏ СЃРІРёС‡Р°
	int amount = 2; //РљРѕР»РёС‡РµСЃС‚РІРѕ РІРµРєС‚РѕСЂРѕРІ
	/*cout << "РЎРєРѕР»СЊРєРѕ РјР°С‚СЂРёС† Р’С‹ С…РѕС‚РёС‚Рµ СЃРѕР·РґР°С‚СЊ?" << endl;
	cin >> amount;*/
	int capacity = amount + 1;
	Matrix* massive = new Matrix[amount];
	for (int k = 0; k < capacity - 1; ++k) {
		int h;
		int w;
		cout << "РљР°РєРѕР№ СЂР°Р·РјРµСЂРЅРѕСЃС‚Рё Р±СѓРґРµС‚ РјР°С‚СЂРёС†Р° (РІРІРµРґРёС‚Рµ РєРѕР»РёС‡РµСЃС‚РІРѕ СЃС‚СЂРѕРє Рё СЃС‚РѕР»Р±С†РѕРІ)?\n";
		cin >> h;
		cin >> w;
		Matrix a(h, w);
		cout << "Р’РІРµРґРёС‚Рµ РјР°С‚СЂРёС†Сѓ\n";
		a.setMatrix();
		a.print();
		massive[k] = a;
		/*amount ++;
		Matrix *tmp = new Matrix[amount];
		tmp [amount - 1] = a;
		for (int i = 0; i < amount - 1; i++) {
			tmp[i] = a;
		}*/
		int number = k;
		cout << "РџРѕСЂСЏРґРєРѕРІС‹Р№ РЅРѕРјРµСЂ СЌС‚РѕР№ РјР°С‚СЂРёС†С‹ СЂР°РІРµРЅ: " << number + 1 << endl;
	}
	/*massive[1].print();*/
	bool flag = false;
	while (!flag)
	{
	mark:
		cout << "Р’РІРµРґРёС‚Рµ 0, РµСЃР»Рё С…РѕС‚РёС‚Рµ Р·Р°РІРµСЂС€РёС‚СЊ РїСЂРѕРіСЂР°РјРјСѓ" << endl <<
			"Р’РІРµРґРёС‚Рµ 1, РµСЃР»Рё С…РѕС‚РёС‚Рµ СЃР»РѕР¶РёС‚СЊ РјР°С‚СЂРёС†С‹" << endl <<
			"Р’РІРµРґРёС‚Рµ 2, РµСЃР»Рё С…РѕС‚РёС‚Рµ РІС‹С‡РµСЃС‚СЊ РјР°С‚СЂРёС†С‹" << endl <<
			"Р’РІРµРґРёС‚Рµ 3, РµСЃР»Рё С…РѕС‚РёС‚Рµ РїСЂРёСЃРІРѕРёС‚СЊ РјР°С‚СЂРёС†Рµ РґСЂСѓРіРѕРµ Р·РЅР°С‡РµРЅРёРµ" << endl <<
			"Р’РІРµРґРёС‚Рµ 4, С‡С‚РѕР±С‹ РїСЂРѕРёР·РІРµСЃС‚Рё РѕРїРµСЂР°С†РёСЋ СѓРЅР°СЂРЅС‹Р№ РјРёРЅСѓСЃ" << endl <<
			"Р’РІРµРґРёС‚Рµ 5, РµСЃР»Рё С…РѕС‚РёС‚Рµ СѓРјРЅРѕР¶РёС‚СЊ РјР°С‚СЂРёС†Сѓ РЅР° С‡РёСЃР»Рѕ" << endl <<
			"Р’РІРµРґРёС‚Рµ 6, РµСЃР»Рё С…РѕС‚РёС‚Рµ СѓРјРЅРѕР¶РёС‚СЊ РјР°С‚СЂРёС†Сѓ РЅР° РјР°С‚СЂРёС†Сѓ" << endl <<
			"Р’РІРµРґРёС‚Рµ 7, РµСЃР»Рё С…РѕС‚РёС‚Рµ СѓРјРЅРѕР¶РёС‚СЊ РјР°С‚СЂРёС†Сѓ РЅР° РІРµРєС‚РѕСЂ" << endl <<
			"Р’РІРµРґРёС‚Рµ 8, РµСЃР»Рё С…РѕС‚РёС‚Рµ РІС‹РІРµСЃС‚Рё СЃРїРёСЃРѕРє РјР°С‚СЂРёС†" << endl;
		cin >> n;
		cout << endl;

		switch (n)
		{
		case '0':
			flag = true;
			break;

		case '1':
		{
			int ID1, ID2;
			cout << "Р’РІРµРґРёС‚Рµ РЅРѕРјРµСЂ РїРµСЂРІРѕР№ РјР°С‚СЂРёС†С‹" << endl;
			cin >> ID1;
			cout << "Р’РІРµРґРёС‚Рµ РЅРѕРјРµСЂ РІС‚РѕСЂРѕР№ РјР°С‚СЂРёС†С‹" << endl;
			cin >> ID2;
			if (ID1 >= capacity || ID2 >= capacity) {
				cout << "РќРµС‚ РјР°С‚СЂРёС† СЃ С‚Р°РєРёРјРё РЅРѕРјРµСЂР°РјРё" << endl;
			}
			else
			{
				cout << "РЎСѓРјРјР° СЂР°РІРЅР°: " << endl;
				(massive[ID1 - 1] + massive[ID2 - 1]).print();
			}
			break;
		}

		case '2':
		{
			int ID1, ID2;
			cout << "Р’РІРµРґРёС‚Рµ РЅРѕРјРµСЂ РїРµСЂРІРѕР№ РјР°С‚СЂРёС†С‹" << endl;
			cin >> ID1;
			cout << "Р’РІРµРґРёС‚Рµ РЅРѕРјРµСЂ РІС‚РѕСЂРѕР№ РјР°С‚СЂРёС†С‹" << endl;
			cin >> ID2;
			if (ID1 >= capacity || ID2 >= capacity) {
				cout << "РќРµС‚ РјР°С‚СЂРёС† СЃ С‚Р°РєРёРјРё РЅРѕРјРµСЂР°РјРё" << endl;
			}
			else
			{
				Matrix result = massive[ID1 - 1] - massive[ID2 - 1];
				cout << "Р Р°Р·РЅРѕСЃС‚СЊ СЂР°РІРЅР°:" << endl;
				result.print();
			}
			break;
		}
		case '3':
		{
			int number;
			cout << "Р’РІРµРґРёС‚Рµ РїРѕСЂСЏРґРєРѕРІС‹Р№ РЅРѕРјРµСЂ РјР°С‚СЂРёС†С‹, РєРѕС‚РѕСЂСѓСЋ С…РѕС‚РёС‚Рµ РїРµСЂРµРЅР°Р·РЅР°С‡РёС‚СЊ" << endl;
			cin >> number;
			if (number >= capacity) {
				cout << "РќРµС‚ РјР°С‚СЂРёС†С‹ СЃ С‚Р°РєРёРј РЅРѕРјРµСЂРѕРј" << endl;
			}
			else
			{
				Matrix tmp;
				int height;
				int width;
				cout << "РљР°РєРѕР№ СЂР°Р·РјРµСЂРЅРѕСЃС‚Рё Р±СѓРґРµС‚ РјР°С‚СЂРёС†Р°?" << endl;
				cin >> height;
				cin >> width;
				Matrix m(height, width);
				cout << "Р’РІРµРґРёС‚Рµ Р·РЅР°С‡РµРЅРёСЏ РјР°С‚СЂРёС†С‹: \n";
				m.setMatrix();
				massive[number - 1] = m;
			}
			break;
		}

		case '4':
		{
			int number;
			cout << "Р’РІРµРґРёС‚Рµ РїРѕСЂСЏРґРєРѕРІС‹Р№ РЅРѕРјРµСЂ РјР°С‚СЂРёС†С‹" << endl;
			cin >> number;
			if (number >= capacity) {
				cout << "РќРµС‚ РјР°С‚СЂРёС†С‹ СЃ С‚Р°РєРёРј РЅРѕРјРµСЂРѕРј" << endl;
			}
			else {
				(-massive[number - 1]).print();
			}
			break;
		}
		case '6':
		{
			int ID1, ID2;
			cout << "Р’РІРµРґРёС‚Рµ РЅРѕРјРµСЂ РїРµСЂРІРѕР№ РјР°С‚СЂРёС†С‹" << endl;
			cin >> ID1;
			cout << "Р’РІРµРґРёС‚Рµ РЅРѕРјРµСЂ РІС‚РѕСЂРѕР№ РјР°С‚СЂРёС†С‹" << endl;
			cin >> ID2;
			if (ID1 >= capacity || ID2 >= capacity) {
				cout << "РќРµС‚ РјР°С‚СЂРёС† СЃ С‚Р°РєРёРјРё РЅРѕРјРµСЂР°РјРё" << endl;
			}
			else {
				(massive[ID1 - 1] * massive[ID2 - 1]).print();
			}
			break;
		}
		case '8':
		{
			for (int i = 0; i < amount; i++) {
				massive[i].print();
			}
			break;
		}
		default:
			cout << "Р’РІРµРґРµРЅРѕ РЅРµРєРѕСЂСЂРµРєС‚РЅРѕРµ Р·РЅР°С‡РµРЅРёРµ, РїРѕРїСЂРѕР±СѓР№С‚Рµ РµС‰Рµ СЂР°Р·" << endl;
			goto mark;
			break;
		}
	}
	return 0;

}
