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
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — удаление информации;\n3 — вывод информации;\n4 — поиск по автору;\n";
	cin >> decision32;
	do {
		switch (decision32) {
		case 1: add32(); break;
		case 2: del32(); break;
		case 3: show32(); break;
		case 4:
			/*while (true) {
				flag = false;
				cout << "Введите фамилию: ";
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
//			cout << "Фамилия автора - ";
//			cout << book[j].author << endl;
//			cout << "Имя автора - ";
//			cout << book[j].auth << endl;
//			cout << "Название - ";
//			cout << book[j].title << endl;
//			cout << "Издательство - ";
//			cout << book[j].press << endl;
//			cout << "Раздел бибилиотеки - ";
//			if (book[j].rasdel == "1") cout << "специальная литература\n";
//			else if (book[j].rasdel == "2") cout << "хобби\n";
//			else if (book[j].rasdel == "3") cout << "домашнее хозяйство\n";
//			else if (book[j].rasdel == "4") cout << "беллетристика\n";
//			cout << "Наличие - ";
//			cout << book[j].availability << endl;
//			cout << "Происхождение - ";
//			if (book[j].orig == purchase) cout << "покупка\n";
//			else if (book[j].orig == theft) cout << "кража\n";
//			else if (book[j].orig == gift) cout << "подарок\n";
//			cout << "Год издательства: ";
//			cout << book[j].year << endl;
//			flag = true;
//			cout << endl;
//		}
//	}
//	if (!flag)
//		cout << "Ничего не найдено\n";
//	
//	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — удаление информации;\n3 — вывод информации;\n4 — поиск по году издательства;\n5 — выход.\n";
//	cin >> decision32;
//	cout << endl;
//}
void add32() {
	setlocale(LC_ALL, "russian");
	int o, t;
	orig32 = purchase32;
	if (codow32 < records) {
		cout << "Фамилия автора - ";
		cin.get();
		cin.getline(un_book.author, len);
		book[codow32].author = un_book.author;
		cout << "Имя автора - ";
		cin.get();
		cin.getline(un_book.auth, len);
		book[codow32].author = un_book.auth;
		cout << "Название - ";
		cin.get();
		cin.getline(un_book.title, len);
		book[codow32].title = un_book.title;
		cout << "Издательство: ";
		cin.get();
		cin.getline(un_book.press, len);
		book[codow32].press = un_book.press;
		do {
			cout << "Раздел библиотеки (специальная литература - 1, хобби - 2, домашнее хозяйство - 3, беллетристика - 4) - ";
			cin >> un_book.rasdel;
			book[codow32].rasdel = un_book.rasdel;
		} while (book[codow32].rasdel != "1" && book[codow32].rasdel != "2" && book[codow32].rasdel != "3" && book[codow32].rasdel != "4");
		cout << "Наличие: ";
		cin.get();
		cin.getline(un_book.availability, len);
		book[codow32].availability = un_book.availability;
		do {
			cout << "Происхождение (покупка - 1, кража - 2, подарок - 3): ";
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
			cout << "Год издательства: ";
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
		cout << "Вы ввели максимальное количество записей";
	}
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — удаление информации;\n3 — вывод информации;\n4 — поиск автору;\n5 — выход.\n";
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
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — удаление информации;\n3 — вывод информации;\n4 — поиск по году издательства;\n5 — выход.\n";
	cin >> decision32;
	cout << endl;
}


void outputOneStructure(library32 oneGorozhanin)
{
	cout << "Фамилия автора - ";
	cout << oneGorozhanin.author << endl;
	cout << "Имя автора - ";
	cout << oneGorozhanin.auth << endl;
	cout << "Название - ";
	cout << oneGorozhanin.title << endl;
	cout << "Издательство - ";
	cout << oneGorozhanin.press << endl;
	cout << "Раздел бибилиотеки - ";
	if (oneGorozhanin.rasdel == "1") cout << "специальная литература\n";
	else if (oneGorozhanin.rasdel == "2") cout << "хобби\n";
	else if (oneGorozhanin.rasdel == "3") cout << "домашнее хозяйство\n";
	else if (oneGorozhanin.rasdel == "4") cout << "беллетристика\n";
	cout << "Наличие - ";
	cout << oneGorozhanin.availability << endl;
	cout << "Происхождение - ";
	if (oneGorozhanin.orig == purchase) cout << "покупка\n";
	else if (oneGorozhanin.orig == theft) cout << "кража\n";
	else if (oneGorozhanin.orig == gift) cout << "подарок\n";
	cout << "Год издательства: ";
	cout << oneGorozhanin.year << endl;
}

void show32() {
	setlocale(LC_ALL, "russian");
	for (int i = 0; i < codow32; i++)
	{
		cout << "Фамилия автора - ";
		cout << book[i].author << endl;
		cout << "Имя автора - ";
		cout << book[i].auth << endl;
		cout << "Название - ";
		cout << book[i].title << endl;
		cout << "Издательство - ";
		cout << book[i].press << endl;
		cout << "Раздел бибилиотеки - ";
		if (book[i].rasdel == "1") cout << "специальная литература\n";
		else if (book[i].rasdel == "2") cout << "хобби\n";
		else if (book[i].rasdel == "3") cout << "домашнее хозяйство\n";
		else if (book[i].rasdel == "4") cout << "беллетристика\n";
		cout << "Наличие - ";
		cout << book[i].availability << endl;
		cout << "Происхождение - ";
		if (book[i].orig == purchase) cout << "покупка\n";
		else if (book[i].orig == theft) cout << "кража\n";
		else if (book[i].orig == gift) cout << "подарок\n";
		cout << "Год издательства: ";
		cout << book[i].year << endl;
	}
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — удаление информации;\n3 — вывод информации;\n4 — поиск автору;\n5 — выход.\n";
	cin >> decision32;
	cout << endl;
}

void search32() {
	setlocale(LC_ALL, "russian");
	
	cout << "Введите автора, по которому нужно искать: ";
	cin >> yo;
	for (int i = 0; i < codow32; i++)
	{
		if (yo.compare(book[i].author) == 0) {
			outputOneStructure(book[i]);
		}
	}
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — удаление информации;\n3 — вывод информации;\n4 — поиск автору;\n5 — выход.\n";
	cin >> decision32;
	cout << endl;
}