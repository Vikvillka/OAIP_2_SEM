//����� ������, ����� ����������, ����� ��������,
//����� �����������. 
//����� �� ������ ����������.
#include <iostream>  
#include<fstream>
# include <iostream> 
#include <iostream>
#include <fstream>
#include <string>
# define size 100  
using namespace std;
void enter_new();
void out();
void search();

union forvokzal
{
	char str[40];
	int limb;
};
struct vokzal
{
	forvokzal name;
	string punct;
	forvokzal vremzot;
	forvokzal vremzpr;
};
vokzal raspisanie[size];
int current_size = 0; int choice;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "������� �����:" << endl;
	cout << "1-��� ����� ������" << endl;
	cout << "2-��� ������ ������" << endl;
	cout << "3-��� ������ ����������" << endl;
	
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1:  enter_new();	break;
		case 2:  out();  break;
		case 3:  search();	break;
		
		}
	} while (choice != 4);
}


void enter_new()
{
	cout << "���� ����������" << endl;
	if (current_size < size)
	{
		cout << "������ �����  ";
		cout << current_size + 1;
		cout << "\n";
		
		cout << endl << "����� ������:" << endl;
		cin >> raspisanie[current_size].name.str;
		cout << "����� ����������:" << endl;
		cin.ignore();
		getline(cin, raspisanie[current_size].punct);
		cout << "����� �����������:" << endl;
		cin >> raspisanie[current_size].vremzot.str;
		cout << "����� ��������:" << endl;
		cin >> raspisanie[current_size].vremzpr.str;
		current_size++;

	}
	else
		cout << "������� ������������ ���-�� �����";
	cout << "��� ������?" << endl;
	cin >> choice;
}
void out()
{
	int sw, n;
	cout << "1-������� 1 ������" << endl;
	cout << "2-������� ��� ������" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "����� ��������� ������: " << endl;
		cin >> n;
		cout << endl;
		
		cout << "����� ������ ";
		cout << raspisanie[n - 1].name.str;
		cout << endl;
		cout << "����� ���������� ";
		cout << raspisanie[n - 1].punct;
		cout << endl;
		cout << "����� ����������� ";
		cout << raspisanie[n - 1].vremzot.str;
		cout << endl;
		cout << "����� �������� ";
		cout << raspisanie[n - 1].vremzpr.str;
		cout << endl;


	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << "����� ������ ";
			cout << raspisanie[i].name.str;
			cout << endl;
			cout << "����� ���������� ";
			cout << raspisanie[i].punct;
			cout << endl;
			cout << "����� ����������� ";
			cout << raspisanie[i].vremzot.str;
			cout << endl;
			cout << "����� �������� ";
			cout << raspisanie[i].vremzpr.str;
			cout << endl;
		}
	}
	cout << "��� ������?" << endl;
	cin >> choice;
}
void search()
{
	string name;
	cout << "������� �������:" << "\n";
	cin.ignore();
	getline(cin, name);
	for (int z = 0; z < current_size; z++)
	{
		if (raspisanie[z].punct==name)
		{
			cout << "����� ������ ";
			cout << raspisanie[z].name.str;
			cout << endl;
			cout << "����� ���������� ";
			cout << raspisanie[z].punct;
			cout << endl;
			cout << "����� ����������� ";
			cout << raspisanie[z].vremzot.str;
			cout << endl;
			cout << "����� �������� ";
			cout << raspisanie[z].vremzpr.str;
			cout << endl;
		}
	}
	cout << "��� ������?" << endl;
	cin >> choice;
}