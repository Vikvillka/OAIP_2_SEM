#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <windows.h>
using namespace std;
/*1. ����������� � ���� FILE2 ������ �� ������ �� FILE1,  �������
���������� � ����� ���. ���������� ���������� ���� � FILE2.*/

int main()
{
	setlocale(LC_ALL, "ru");
	int k, num = 0, counter = 0;
	string str;
	ifstream file1("file2_1_1.txt");
	ofstream file2("file2_1_2.txt");
	while (getline(file1, str))
	{
		if (str[0] == 'a' || str[0] == 'A')
		{
			file2 << str << '\n';
			counter++;
			for (int i = 0; i < str.length(); i++)
			{
				if (str[i] == ' ')
				{
					counter++;
				}
			}
		}
	}
	cout << "���-�� ����: " << counter << " �����.\n";
}