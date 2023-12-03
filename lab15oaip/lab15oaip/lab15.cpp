#include "Hash_Chain.h"
#include <iostream>
#include <windows.h>
#include <tchar.h>
#include <time.h>

using namespace std;


struct AAA
{
	int key;
	const char* mas;
	AAA(int k, const char* z)
	{
		key = k;
		mas = z;
	}
	AAA()
	{
		key = 0;
		mas = NULL;
	}
};
//-------------------------------
int hf(void* d)                                                                         //������� �������� ��������� ��� ��������������� �������� ������
{
	AAA* f = (AAA*)d;
	return f->key;
}
//-------------------------------
void AAA_print(listx::Element* e)
{
	std::cout << ((AAA*)e->data)->key << '-' << ((AAA*)e->data)->mas << " / ";
}
//-------------------------------
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");                                                            //������������ ���������
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(0));
	int current_size = 0;                                                                //����������, ������������ ������ �������                                                    
	cout << "������� ������ ���-�������: ";                             //��������� � ����� ������� �������
	cin >> current_size;                                                                 //���� ������������� ������� �������
	hashTC::Object H = hashTC::create(current_size, hf);
	int choice;
	int k;
	for (;;)																			//����
	{
		cout << "1 - ����� ���-�������" << endl;
		cout << "2 - ���������� ��������" << endl;
		cout << "3 - �������� ��������" << endl;
		cout << "4 - ����� ��������" << endl;
		cout << "0 - �����" << endl;
		cout << "�������� �����" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 2: {	  AAA* a = new AAA;                                            //�������� ������ �������� ������. ������ - ������� �������
			char* str = new char[100];                                              //�������� ����� ������ ��� ������, ���������� � ���� �������� ������
			cout << "������� ���: ";
			cin >> k;
			k = k;//���� �����, ����������� � ���� �������� ������
			a->key = k;                                                            //������������ ���� "����" ������ �������� ����
			cout << "������� �����: ";
			cin.ignore();
			cin.getline(str, 100);
			a->mas = str;                                                          //������������ ���� "������" ������ �������� ������
			H.insert(a);                                                           //������� �������� � �����-�������
		}
			  break;
		case 1: H.Scan();
			break;
		case 3: {	  AAA* b = new AAA;
			cout << "������� ���: ";
			cin >> k;
			b->key = k;
			H.deleteByData(b);
		}
			  break;
		case 4: {AAA* c = new AAA;
			cout << "������� ���: ";
			cin >> k;
			c->key = k;
			if (H.search(c) == NULL)
				cout << "������� �� ������" << endl;
			else
			{
				cout << "������ ������� � ������ �����: ";
				AAA_print(H.search(c));
				cout << endl;
			}
		}
			  break;
		
		}
	}
	return 0;
}