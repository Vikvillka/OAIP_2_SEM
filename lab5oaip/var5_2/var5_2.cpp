#include <iostream>
#include <string>
using namespace std;

#define len 30 
#define records 30
# define Size 30

void add32();
void del32();
void show32();
void search32();
void outputOneStructure();

int decision32;
int decision31;
int current_year = 2023;

enum origin32 {
	purchase32 = 1, theft32, gift32
} orig32;
enum origin {
	purchase = 1, theft, gift
} orig;
struct library32 {
	string author;
	string auth;
	string title;
	string press;
	string rasdel;
	string availability;
	origin orig;
	int year;
} book[records], zero32;

struct library32 bad;

union un_library {
	char author[len];
	char auth[len];
	char title[len];
	char press[len];
	char rasdel[len];
	char availability[len];
	origin orig[len];
	int year;
} un_book;

string aut;
string yo;
int codow32 = 0;
bool flag;
void main() {
	setlocale(LC_ALL, "russian");
	cout << "\n��������, ��� �������:\n1 � ���� ����������;\n2 � �������� ����������;\n3 � ����� ����������;\n4 � ����� �� ������;\n";
	cin >> decision32;
	do {
		switch (decision32) {
		case 1: add32(); break;
		case 2: del32(); break;
		case 3: show32(); break;
		case 4:
			/*while (true) {
				flag = false;
				cout << "������� �������: ";
				cin >> yo;
				
				if (flag) {
					continue;
				}
				break;
			}
			aut = yo;*/
			
			search32();
			break;
		
		}
	} while (decision32 != 5);
}
//void search32(string lastName) {
//	system("cls");
//	bool flag = false;
//	for (int j = 0; j < codow32; j++) {
//		if (book[j].author == lastName) {
//			cout << "������� ������ - ";
//			cout << book[j].author << endl;
//			cout << "��� ������ - ";
//			cout << book[j].auth << endl;
//			cout << "�������� - ";
//			cout << book[j].title << endl;
//			cout << "������������ - ";
//			cout << book[j].press << endl;
//			cout << "������ ����������� - ";
//			if (book[j].rasdel == "1") cout << "����������� ����������\n";
//			else if (book[j].rasdel == "2") cout << "�����\n";
//			else if (book[j].rasdel == "3") cout << "�������� ���������\n";
//			else if (book[j].rasdel == "4") cout << "�������������\n";
//			cout << "������� - ";
//			cout << book[j].availability << endl;
//			cout << "������������� - ";
//			if (book[j].orig == purchase) cout << "�������\n";
//			else if (book[j].orig == theft) cout << "�����\n";
//			else if (book[j].orig == gift) cout << "�������\n";
//			cout << "��� ������������: ";
//			cout << book[j].year << endl;
//			flag = true;
//			cout << endl;
//		}
//	}
//	if (!flag)
//		cout << "������ �� �������\n";
//	
//	cout << "\n��������, ��� �������:\n1 � ���� ����������;\n2 � �������� ����������;\n3 � ����� ����������;\n4 � ����� �� ���� ������������;\n5 � �����.\n";
//	cin >> decision32;
//	cout << endl;
//}
void add32() {
	setlocale(LC_ALL, "russian");
	int o, t;
	orig32 = purchase32;
	if (codow32 < records) {
		cout << "������� ������ - ";
		cin.get();
		cin.getline(un_book.author, len);
		book[codow32].author = un_book.author;
		cout << "��� ������ - ";
		cin.get();
		cin.getline(un_book.auth, len);
		book[codow32].author = un_book.auth;
		cout << "�������� - ";
		cin.get();
		cin.getline(un_book.title, len);
		book[codow32].title = un_book.title;
		cout << "������������: ";
		cin.get();
		cin.getline(un_book.press, len);
		book[codow32].press = un_book.press;
		do {
			cout << "������ ���������� (����������� ���������� - 1, ����� - 2, �������� ��������� - 3, ������������� - 4) - ";
			cin >> un_book.rasdel;
			book[codow32].rasdel = un_book.rasdel;
		} while (book[codow32].rasdel != "1" && book[codow32].rasdel != "2" && book[codow32].rasdel != "3" && book[codow32].rasdel != "4");
		cout << "�������: ";
		cin.get();
		cin.getline(un_book.availability, len);
		book[codow32].availability = un_book.availability;
		do {
			cout << "������������� (������� - 1, ����� - 2, ������� - 3): ";
			cin >> o;
		} while (o != 1 && o != 2 && o != 3);
		t = (int)orig - o;
		if (t == 0) {
			book[codow32].orig = purchase;
		}
		else if (t == 1) {
			book[codow32].orig = theft;
		}
		else {
			book[codow32].orig = gift;
		}

		bool is_correct_year = false;
		do {
			cout << "��� ������������: ";
			cin >> un_book.year;
			book[codow32].year = un_book.year;
			if (book[codow32].year <= current_year)
				is_correct_year = true;
			else
				cout << "Incorrect input" << endl;
		} while (is_correct_year == false);

		codow32++;
	}
	else {
		cout << "�� ����� ������������ ���������� �������";
	}
	cout << "\n��������, ��� �������:\n1 � ���� ����������;\n2 � �������� ����������;\n3 � ����� ����������;\n4 � ����� ������;\n5 � �����.\n";
	cin >> decision32;
	cout << endl;
}

void del32()
{
	setlocale(LC_ALL, "russian");
	int purge = 1;
	for (int de = (purge - 1); de < codow32; de++)
		book[de] = book[de + 1];
	codow32 = codow32 - 1;
	cout << "\n��������, ��� �������:\n1 � ���� ����������;\n2 � �������� ����������;\n3 � ����� ����������;\n4 � ����� �� ���� ������������;\n5 � �����.\n";
	cin >> decision32;
	cout << endl;
}


void outputOneStructure(library32 oneGorozhanin)
{
	cout << "������� ������ - ";
	cout << oneGorozhanin.author << endl;
	cout << "��� ������ - ";
	cout << oneGorozhanin.auth << endl;
	cout << "�������� - ";
	cout << oneGorozhanin.title << endl;
	cout << "������������ - ";
	cout << oneGorozhanin.press << endl;
	cout << "������ ����������� - ";
	if (oneGorozhanin.rasdel == "1") cout << "����������� ����������\n";
	else if (oneGorozhanin.rasdel == "2") cout << "�����\n";
	else if (oneGorozhanin.rasdel == "3") cout << "�������� ���������\n";
	else if (oneGorozhanin.rasdel == "4") cout << "�������������\n";
	cout << "������� - ";
	cout << oneGorozhanin.availability << endl;
	cout << "������������� - ";
	if (oneGorozhanin.orig == purchase) cout << "�������\n";
	else if (oneGorozhanin.orig == theft) cout << "�����\n";
	else if (oneGorozhanin.orig == gift) cout << "�������\n";
	cout << "��� ������������: ";
	cout << oneGorozhanin.year << endl;
}

void show32() {
	setlocale(LC_ALL, "russian");
	for (int i = 0; i < codow32; i++)
	{
		cout << "������� ������ - ";
		cout << book[i].author << endl;
		cout << "��� ������ - ";
		cout << book[i].auth << endl;
		cout << "�������� - ";
		cout << book[i].title << endl;
		cout << "������������ - ";
		cout << book[i].press << endl;
		cout << "������ ����������� - ";
		if (book[i].rasdel == "1") cout << "����������� ����������\n";
		else if (book[i].rasdel == "2") cout << "�����\n";
		else if (book[i].rasdel == "3") cout << "�������� ���������\n";
		else if (book[i].rasdel == "4") cout << "�������������\n";
		cout << "������� - ";
		cout << book[i].availability << endl;
		cout << "������������� - ";
		if (book[i].orig == purchase) cout << "�������\n";
		else if (book[i].orig == theft) cout << "�����\n";
		else if (book[i].orig == gift) cout << "�������\n";
		cout << "��� ������������: ";
		cout << book[i].year << endl;
	}
	cout << "\n��������, ��� �������:\n1 � ���� ����������;\n2 � �������� ����������;\n3 � ����� ����������;\n4 � ����� ������;\n5 � �����.\n";
	cin >> decision32;
	cout << endl;
}

void search32() {
	setlocale(LC_ALL, "russian");
	
	cout << "������� ������, �� �������� ����� ������: ";
	cin >> yo;
	for (int i = 0; i < codow32; i++)
	{
		if (yo.compare(book[i].author) == 0) {
			outputOneStructure(book[i]);
		}
	}
	cout << "\n��������, ��� �������:\n1 � ���� ����������;\n2 � �������� ����������;\n3 � ����� ����������;\n4 � ����� ������;\n5 � �����.\n";
	cin >> decision32;
	cout << endl;
}