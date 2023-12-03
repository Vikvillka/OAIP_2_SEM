#include <iostream>
#include <string>

using namespace std;

int n = 100;

struct date {
	unsigned int day : 5;
	unsigned int month : 4;
	unsigned int year : 16;
};

enum exams { opi = 1, OAIP, aisd };

struct teacher {
	string surname;
	string exam;
	date date_now;
} teachers[20];

void input();
void output();
void find();

string str, surname;
bool flag1, check;
int i;

void del() {
	int d;
	cout << "\nНомер строки, которую надо удалить " << endl;
	cin >> d;
	if (d != 22)
	{
		for (int j = (d-1); j < i; j++) {
			teachers[j] = teachers[j + 1];
			i = i - 1;
		}
		cout << "Строка удалена" << endl;
	}
}
int main() {
	setlocale(LC_CTYPE, "Rus");

	while (true) {
		
		cout << "\n1 - Ввести новую запись\n2 - Показать записи\n3 - Найти по дате\n4 - Удаление\n";
		cin >> str;

		if (str[0] < '0' || str[0] > '5' || size(str) > 1) {
			system("cls");
			cout << "Некорректное значение" << endl;
			system("pause");
			continue;
		}

		n = stoi(str);
		switch (n) {
		case 1:
			input();
			break;
		case 2:
			output();
			break;
		case 3:
			find();
			break;
		case 4:
			del();
		}
	}
	return 0;
}

void input() {
	

	while (true) {
		flag1 = false;
		cout << "Фамилия: ";
		cin >> str;
		for (int j = 0; j < size(str); j++) {
			if (!isalpha(str[j])) {
				
				cout << "Некорректное значение" << endl;
				
				flag1 = true;
				break;
			}

		}
		if (flag1) {
			continue;
		}
		break;
	}
	teachers[i].surname = str;

	while (true) {
		flag1 = false;
		cout << "Экзамен(1 - опи, 2 - оаип, 3 - аисд): ";
		cin >> str;
		for (int j = 0; j < size(str); j++) {
			if (str[0] < '0' || str[0] > '3' || size(str) > 1) {
				
				cout << "Некорректное значение" << endl;
				
				flag1 = true;
				break;
			}

		}
		if (flag1) {
			continue;
		}
		break;
	}
	switch (stoi(str)) {
	case opi: teachers[i].exam = "ОПИ"; break;
	case OAIP: teachers[i].exam = "ОАИП"; break;
	case aisd: teachers[i].exam = "АиСД"; break;
	}

	cout << "Дата экзамена:\n";
	int months[]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	while (true) {
		check = true;
		cout << "Месяц ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (!isdigit(str[j])) {
				check = false;
			}
		}
		if (!check || stoi(str) > 12) {
			
			cout << "Некорректное значение" << endl;
			
			continue;
		}
		break;
	}
	teachers[i].date_now.month = stoi(str);

	while (true) {
		check = true;
		cout << "Год: ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (!isdigit(str[j])) {
				check = false;
			}
		}
		if (!check || stoi(str) > 2023) {
			
			cout << "Некорректное значение" << endl;
			
			continue;
		}
		break;
	}
	teachers[i].date_now.year = stoi(str);
	int year;
	while (true) {
		check = true;
		cout << "День: ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (!isdigit(str[j])) {
				check = false;
			}
		}
		year = 2000 + teachers[i].date_now.year;
		if ((year % 4 == 0) || ((year % 100 == 0) && (year % 400 == 0))) {
			if (teachers[i].date_now.month == 2 && stoi(str) > 29) {
				check = false;
			}
			if (teachers[i].date_now.month != 2 && stoi(str) > months[teachers[i].date_now.month - 1]) {
				check = false;
			}
		}
		else {
			if (stoi(str) > months[teachers[i].date_now.month - 1]) {
				check = false;
			}
		}
		if (!check) {
			
			cout << "Некорректное значение" << endl;
			
			continue;
		}

		break;
	}
	teachers[i].date_now.day = stoi(str);
	i++;
}

void output() {

	for (int j = 0; j < i; j++) {
		cout << teachers[j].surname << " " << teachers[j].exam << " ";
		if (teachers[j].date_now.day < 10)
			cout << "0" << teachers[j].date_now.day << ".";
		else
			cout << teachers[j].date_now.day << ".";
		if (teachers[j].date_now.month < 10)
			cout << "0" << teachers[j].date_now.month << ".";
		else
			cout << teachers[j].date_now.month << ".";
		if (teachers[j].date_now.year < 10)
			cout << "0" << teachers[j].date_now.year << endl;
		else
			cout << teachers[j].date_now.year << endl;

	}
}

void find() {
	
	int day, month, year;
	bool flag = false;
	cout << "Введите дату: \n";

	int months[]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	while (true) {
		check = true;
		cout << "Месяц ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (!isdigit(str[j])) {
				check = false;
			}
		}
		if (!check || stoi(str) > 12) {
			
			cout << "Некорректное значение" << endl;
			
			continue;
		}
		break;
	}
	month = stoi(str);

	while (true) {
		check = true;
		cout << "Год: ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (str[j] < '0' || str[j] > '9') {
				check = false;
			}
		}
		if (!check || stoi(str) > 23) {
			
			cout << "Некорректное значение" << endl;
			
			continue;
		}
		break;
	}
	year = 2000 + stoi(str);
	while (true) {
		check = true;
		cout << "День: ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (!isdigit(str[j])) {
				check = false;
			}
		}
		if ((year % 4 == 0) || ((year % 100 == 0) && (year % 400 == 0))) {
			if (month == 2 && stoi(str) > 29) {
				check = false;
			}
			if (month != 2 && stoi(str) > months[month - 1]) {
				check = false;
			}
		}
		else {
			if (stoi(str) > months[month - 1]) {
				check = false;
			}
		}
		if (!check) {
			system("cls");
			cout << "Некорректное значение" << endl;
			system("pause");
			continue;
		}

		break;
	}
	day = stoi(str);

	for (int j = 0; j < i; j++) {
		if (teachers[j].date_now.day == day) {
			if (teachers[j].date_now.month == month) {
				if (teachers[j].date_now.year + 2000 == year) {
					cout << teachers[j].surname << " " << teachers[j].exam << " ";
					if (teachers[j].date_now.day < 10)
						cout << "0" << teachers[j].date_now.day << ".";
					else
						cout << teachers[j].date_now.day << ".";
					if (teachers[j].date_now.month < 10)
						cout << "0" << teachers[j].date_now.month << ".";
					else
						cout << teachers[j].date_now.month << ".";
					if (teachers[j].date_now.year < 10)
						cout << "0" << teachers[j].date_now.year << endl;
					else
						cout << teachers[j].date_now.year << endl;

					flag = true;
					cout << endl;
				}
			}
		}
	}
	if (!flag)
		cout << "Ничего не найдено\n";
	system("pause");
}