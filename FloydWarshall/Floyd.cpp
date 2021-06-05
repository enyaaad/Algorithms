#include<stdio.h>
#include<iostream>
#include<vector>
#include <Windows.h>
using namespace std;
const int INF = 10000;

int main() {
	system("chcp 1251");
	int peak;
	int temp = INF;
	cout << "Введите количество вершин: ";
	cin >> peak;

	vector<vector<int>> a(peak, vector<int>(peak));
	

	for (int k = 0; k < peak; ++k) for (int i = 0; i < peak; ++i) for (int j = 0; j < peak; ++j)a[i][j] = min(a[i][j],a[i][k] + a[k][j]);
	for (int i = 0; i < peak; ++i) 
		for (int j = 0; j < peak; ++j) {
		cin >> a[i][j];
		if (a[i][j] == NULL) a[i][j] = INF;
	}


	for (int i = 1; i <= peak; ++i) {
		for (int j = 1; j <= peak; ++j) {
			if (a[i][j] == temp) {
				a[i][j] = a[j][i];

			}
		}
	}

	cout << "Ответ:" << endl;
	for (auto vec : a) {
		for (auto i : vec) {
			if (i >= INF) {
				cout << " \t " << 'i';
			}
			else cout << " \t " << i;
		}
		cout << endl;
	}
	
}

//const int INF = 100000;
//
//#include <Windows.h>
//#include <iostream>
//#include <vector>
//#include <iomanip>      // std::setw
//using namespace std;
//
//void main() {
//	srand(time(NULL));
//	setlocale(LC_ALL, "rus");
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(hConsole, 15);
//
//	int n;
//	cout << "Кол-во вершин = ";
//	SetConsoleTextAttribute(hConsole, 3);
//	cin >> n;
//	SetConsoleTextAttribute(hConsole, 15);
//
//	vector<vector<int>> a(n, vector<int>(n));
//
//	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
//		cin >> a[i][j];
//		if (a[i][j] == -1) a[i][j] = INF;
//	}
//
//	for (int k = 0; k < n; ++k) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
//
//	cout << "Ответ:" << endl;
//	SetConsoleTextAttribute(hConsole, 3);
//	for (auto vec : a) {
//		for (auto i : vec) {
//			SetConsoleTextAttribute(hConsole, 2);
//			if (i >= INF) {
//				SetConsoleTextAttribute(hConsole, 4);
//				cout << std::setw(3) << 'i';
//			}
//			else cout << std::setw(3) << i;
//		}
//		cout << endl;
//	}
//	SetConsoleTextAttribute(hConsole, 15);
//}
//
///*
//9
//00 03 -1 05 09 -1 -1 -1 -1
//03 00 -1 01 -1 -1 08 -1 -1
//-1 -1 00 -1 -1 -1 -1 -1 -1
//05 01 -1 00 -1 03 05 00 00
//09 -1 -1 -1 00 01 -1 09 -1
//-1 -1 -1 03 01 00 -1 -1 -1
//-1 08 -1 05 -1 -1 00 07 05
//-1 -1 -1 -1 09 -1 07 00 -1
//-1 -1 -1 -1 -1 -1 05 -1 00
//*/
