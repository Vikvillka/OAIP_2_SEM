//����������� � ���� FILE2 ������ ������ ������ �� FILE1.���������� ������ ������ FILE1 � FILE2(� ������).
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	int k, num = 1, counter = 0;

	string str;
	ifstream file1("f1.txt");
	ofstream file2("f2.txt");
	while (getline(file1, str))
	{

		if (num % 2 == 0)
		{
			file2 << str << '\n';
		}
		num++;
	}
	cout << "������ ������ FILE1 " << sizeof(file1) << " ������ ������ FILE2  " << sizeof(file2) << endl;
}