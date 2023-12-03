// 2. ������������ � ������� ������� �������������� �����������.
#include "Header.h"
#include <iostream>

using namespace std;

struct AAA // ��� �������� AAA, �-�� �� ������� �������� � ���-�������, ������ � ������� ���-�������
{
	int key; // ����, ����
	char* mas; // ������, �� ���� ������ ��������, ����
	AAA(int k, char* z) // ����� ����� key � ������ mas, ����������� � �����������
	   // ����������� ���������� ���� � ������ � ���� ���������
	{
		key = k;
		mas = z;
	}
	AAA() {} // ����������� ��� ����������
};

int key(void* d) // ������� ���������� ������, �������� � ����������, � ����
{
	AAA* f = (AAA*)d; // ����������� �-�� �� ������������ ������ d � �-�� f �� ��������� AAA 
	return f->key;
	// ���������� ���� ��������� AAA �� ��������� f, �� ���� ����� �-�� ���������� � ���� int key
}

void AAA_print(void* d) // ������� ������ 1 �-� ������ �� �-�� �� ���� �-�
{
	cout << "���� " << ((AAA*)d)->key << " - " << ((AAA*)d)->mas << endl;
}


void main()
{
	setlocale(LC_ALL, "rus");
	int siz;
	AAA* a;
	char* str;
	cout << "������� ������ ���-�������" << endl;
	cin >> siz;
	Object H = Create(siz, key);// ������� ���-������� �������� ��������
	int choise; // ���������� ��� ����� ������ ������������
	int k;// ���� ����� � ��� ����������
	for (;;)
	{
		cout << "����:" << endl;
		cout << "1 - ����� ���-�������" << endl;
		cout << "2 - ���������� ��������" << endl;
		cout << "3 - �������� ��������" << endl;
		cout << "4 - ����� ��������" << endl;
		cout << "0 - �����" << endl;
		cout << "�������� �����" << endl; cin >> choise;
		switch (choise)
		{
		case 0: exit(0); // ������� ��������� ������ ���������
		case 1: H.Scan(AAA_print); break;
		case 2:
			a = new AAA(); // ������� ������� ��������� ��� � ������ �
			   // new AAA() - ��� � ���� ����� ������������ ��� 
			
				cout << "������� ����" << endl;
			cin >> k;
			a->key = k;
			str = new char[20];
			cout << "������� ������" << endl;
			cin >> str;
			a->mas = str;
			if (H.N == H.Size) // ���� ���-������� ���������
				cout << "������� ���������" << endl;
			else H.Insert(a);
			break;
		case 3:
			cout << "������� ���� ��� �������� " << endl;
			cin >> k;
			H.Delete(k);
			break;
		case 4:
			cout << "������� ���� ��� ������ " << endl;
			cin >> k;
			unsigned int start = clock();
			if (H.Search(k) == NULL)
				cout << "������� �� ������" << endl;
			else
				AAA_print(H.Search(k));
			unsigned int end = clock();
			float dif = end - start;
			cout << endl << dif << " ��\n";
			break;
		}
	}
}