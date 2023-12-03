#include <iostream>
#include <string>
using namespace std;

#define len 30 
#define records 30
# define size 30


void add31();
void del31();
void show31();
void search31();

int decision31;
int current_year = 2023;


enum origin {
	purchase = 1, theft, gift
} orig;

struct library {
	unsigned int year : 16;
	string author;
	string title;
	string press;
	string rasdel;
	string availability;
	origin orig;

} Book[records], zeroo;

int codow31 = 0;

void main() {
	setlocale(LC_CTYPE, "Russian");
	cout << "\n��������, ��� �������:\n1 � ���� ����������;\n2 � �������� ����������;\n3 � ����� ����������;\n4 � ����� �� ���� ������������;\n\n";
	cin >> decision31;
	do {
		switch (decision31) {
		case 1: add31(); break;
		case 2: del31(); break;
		case 3: show31(); break;
		case 4: search31(); break;
		
		}
	} while (decision31 != 5);
}

void add31() {
	setlocale(LC_CTYPE, "Russian");
	int o, t;
	orig = purchase;
	if (codow31 < records) {
		cout << "����� - ";
		cin.get();
		getline(cin, Book[codow31].author);
		cout << "�������� - ";
		cin.get();
		getline(cin, Book[codow31].title);
		cout << "������������: ";
		cin.get();
		getline(cin, Book[codow31].press);
		do {
			cout << "������ ���������� (����������� ���������� - 1, ����� - 2, �������� ��������� - 3, ������������� - 4) - ";
			cin >> Book[codow31].rasdel;
		} while (Book[codow31].rasdel != "1" && Book[codow31].rasdel != "2" && Book[codow31].rasdel != "3" && Book[codow31].rasdel != "4");
		cout << "������� - ";
		cin.get();
		getline(cin, Book[codow31].availability);
		do {
			cout << "������������� (������� - 1, ����� - 2, ������� - 3) - ";
			cin >> o;
		} while (o != 1 && o != 2 && o != 3);
		t = (int)orig - o;
		if (t == 0) {
			Book[codow31].orig = purchase;
		}
		else if (t == 1) {
			Book[codow31].orig = theft;
		}
		else {
			Book[codow31].orig = gift;
		}

		bool is_correct_year = false;
		do {
			cout << "������� ��� ������������: ";
			int year;
			cin >> year;
			Book[codow31].year = year;
			if (Book[codow31].year <= current_year)
				is_correct_year = true;
			else
				cout << "�������" << endl;
		} while (is_correct_year == false);


		codow31++;
	}
	else {
		cout << "�� ����� ������������ ���������� �������";
	}
	cout << "\n��������, ��� �������:\n1 � ���� ����������;\n2 � �������� ����������;\n3 � ����� ����������;\n4 � ����� �� ���� ������������;\n5 � �����.\n";
	cin >> decision31;
	cout << endl;
}

void del31()
{

	int purge = 1;
	setlocale(LC_CTYPE, "Russian");
	for (int de = (purge - 1); de < codow31; de++)
		Book[de] = Book[de + 1];
	codow31 = codow31 - 1;
	cout << "\n��������, ��� �������:\n1 � ���� ����������;\n2 � �������� ����������;\n3 � ����� ����������;\n4 � ����� �� ���� ������������;\n5 � �����.\n";
	cin >> decision31;
	cout << "������ �������" << endl;
}

void show31() {
	setlocale(LC_CTYPE, "Russian");
	for (int i = 0; i < codow31; i++)
	{
		cout << "����� - ";
		cout << Book[i].author << endl;
		cout << "�������� - ";
		cout << Book[i].title << endl;
		cout << "������������ - ";
		cout << Book[i].press << endl;
		cout << "������ ���������� - ";
		if (Book[i].rasdel == "1") cout << "����������� ����������\n";
		if (Book[i].rasdel == "2") cout << "�����\n";
		if (Book[i].rasdel == "3") cout << "�������� ���������\n";
		if (Book[i].rasdel == "4") cout << "�������������\n";
		cout << "������� - ";
		cout << Book[i].availability << endl;
		cout << "������������� - ";
		if (Book[i].orig == purchase) cout << "�������\n";
		else if (Book[i].orig == theft) cout << "�����\n";
		else if (Book[i].orig == gift) cout << "�������\n";
		cout << "��� ������������: ";
		cout << Book[i].year << endl;
		
	}
	cout << "\n��������, ��� �������:\n1 � ���� ����������;\n2 � �������� ����������;\n3 � ����� ����������;\n4 � ����� �� ���� ������������;\n5 � �����.\n";
	cin >> decision31;
	cout << endl;
}

void search31() {
	setlocale(LC_CTYPE, "Russian");
	int yo;
	cout << "������� ���, �� �������� ������� ����������� ����� - ";
	cin >> yo;
	for (int i = 0; i < codow31; i++) {
		if (yo == Book[i].year) {
			cout << "����� - ";
			cout << Book[i].author << endl;
			cout << "�������� - ";
			cout << Book[i].title << endl;
			cout << "������������ - ";
			cout << Book[i].press << endl;
			cout << "������ ���������� - ";
			if (Book[i].rasdel == "1") cout << "����������� ����������\n";
			if (Book[i].rasdel == "2") cout << "�����\n";
			if (Book[i].rasdel == "3") cout << "�������� ���������\n";
			if (Book[i].rasdel == "4") cout << "�������������\n";
			cout << "������� - ";
			cout << Book[i].availability << endl;
			cout << "������������� - ";
			if (Book[i].orig == purchase) cout << "�������\n";
			else if (Book[i].orig == theft) cout << "�����\n";
			else if (Book[i].orig == gift) cout << "�������\n";
			cout << "��� ������������: ";
			cout << Book[i].year << endl;
		}
	}
	cout << "\n��������, ��� �������:\n1 � ���� ����������;\n2 � �������� ����������;\n3 � ����� ����������;\n4 � ����� �� ���� ������������;\n5 � �����.\n";
	cin >> decision31;
	cout << endl;
}
