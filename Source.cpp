#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <string>
#include "Windows.h"

using namespace std;

void Create(char* filename, const int N);
void Print(char* filename);
bool Count(char* filename);

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char filename[100];
	cout << "Enter filename: ";
	cin.getline(filename, sizeof(filename));

	int N;
	cout << "Enter count of components: "; cin >> N;

	int menuItem;

	do {
		cout << endl << endl;
		cout << "\t[1] - запис даних у файл" << endl;
		cout << "\t[2] - зчитування даних із файлу" << endl;
		cout << "\t[3] - перевірка на наявність групи символів \"***\"" << endl;
		cout << "\t[0] - Exit" << endl;
		cout << "Ваш вибір: "; cin >> menuItem;
		cout << endl << endl;

		switch (menuItem)
		{
		case 1:
			Create(filename, N);
			break;
		case 2:
			Print(filename);
			break;
		case 3:
			if (Count(filename))
			{
				cout << "Група символів \"***\" виявлена" << endl;
			}
			else
			{
				cout << "Групи символів немає у файлі" << endl;
			}
		}
	} while (menuItem != 0);

	system("pause");
	return 0;
}

void Create(char* filename, const int N)
{
	ofstream fout(filename);

	char s[100];

	for (int i = 0; i < N; i++)
	{
		cin.get();
		cin.sync();
		cout << "Enter line: "; cin >> s;
		fout << s << endl;
	}
	cout << endl;

	fout.close();
}

void Print(char* filename)
{
	ifstream fin(filename);

	fin.clear();

	char s[100];

	while (fin >> s)
	{
		cout << s << endl;
	}
	cout << endl;

	fin.close();
}

bool Count(char* filename)
{
	ifstream fin(filename);

	fin.clear();

	char s[100];

	while (fin >> s)
	{
		for (int i = 1; s[i + 1] != 0; i++)
			if (s[i - 1] == '*' && s[i] == '*' && s[i + 1] == '*')
			{
				return true;
			}
	}
	return false;
}