#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <windows.h>
using namespace std;
/* 2. ������ � ���������� ������ ��������, ��������� �� ����,
����������� ���������, � �������� �� � ����. ��������� �� ����� ������
� ������� �� ����� ���������� ����� ����� ����������� �����. ���������
���������� �������� � �����. */

string fileOut(string* pStrOut)
{
	ofstream file1("file9_2_1.txt");
	file1 << *pStrOut;
	file1.close();
	return *pStrOut;
}

string fileIn(string* pStrIn)
{
	string StrIn, min = "0000000";
	short counter = 1, SequenceNum;
	ifstream file2("file9_2_1.txt");
	while (file2)
	{
		file2 >> StrIn;
		if (StrIn.length() < min.length())
		{
			min = StrIn;
			SequenceNum = counter;
		}
		counter++;
	}
	cout << "���������� ����� ������ ��������� �����: " << SequenceNum << '\n';
	char* c = const_cast<char*>(min.c_str());
	cout << "���������� ��������: " << strlen(c);
	file2.close();
	return StrIn;
}

int main()
{
	setlocale(LC_ALL, "ru");
	string strOut, strIn;
	string* pStrOut = &strOut, * pStrIn = &strIn;
	cout << "������� ������ ����, ����������� ��������:\n";
	getline(cin, strOut);
	fileOut(pStrOut);
	fileIn(pStrIn);
}