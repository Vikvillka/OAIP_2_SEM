#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <windows.h>
using namespace std;
/*2. ������ � ���������� ������ ��������, ��������� �� �����
���� � �����, � �������� �� � ����. ��������� �� ����� ������
� ������� ����� �������� ������. */
string fileOut(string* pStrOut)
{
	ofstream file1("file2_2_1.txt");
	file1 << *pStrOut;
	file1.close();
	return *pStrOut;
}

string fileIn(string* pStrIn)
{
	string StrIn, min = "0000000000000";
	ifstream file2("file2_2_1.txt");
	while (file2)
	{
		file2 >> StrIn;
		if (StrIn.length() < min.length())
			min = StrIn;
	}
	cout << "����� �������� ������: " << min << '\n';
	file2.close();
	return min;
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