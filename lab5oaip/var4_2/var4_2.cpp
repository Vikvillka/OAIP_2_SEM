#include <iostream>
#include <string>

using namespace std;

struct dat {
	unsigned day : 5;
	unsigned month : 4;
	unsigned year : 16;
};

enum type {
	emergency = 1, preferential, payment, credit
};

struct client {
	string name;
	string surname;
	string secondname;
	int type;
	int number;
	float sum;
	dat data_now;
};

union buff {
	char str1[50];
	int number;
	int n;
} buff;

void input();
void output();
void find(int numb);

string str;
bool flag1, check;
int i;
client clients[10];

void del() {
	int d;
	cout << "\nНомер строки, которую надо удалить " << endl;
	cin >> d;
	if (d != 22)
	{
		for (int j = (d-1); j < i; j++) {
			clients[j] = clients[j + 1];
			i = i - 1;
		}
		cout << "Строка удалена" << endl;
	}
}
int main() {
	setlocale(LC_CTYPE, "Rus");

	while (true) {
		
		cout << "\n1 - ввести клиента\n2 - вывести информацию\n3 - найти клиента\n4 - удаление\n";
		cin >> buff.str1;
		str = buff.str1;

		if (str[0] < '0' || str[0] > '5' || size(str) > 1) {
			
			cout << "Некорректное значение" << endl;
			
			continue;
		}

		buff.n = stoi(str);
		switch (buff.n) {
		case 1:
			input();
			break;
		case 2:
			output();
			break;
		case 3:
			
			find(buff.number);
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
		cout << "Имя: ";
		cin >> str;
		for (int j = 0; j < size(str); j++) {
			if (!((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'a' && str[j] <= 'z') || (str[j] >= 'А' && str[j] <= 'Я') || (str[j] >= 'а' && str[j] <= 'я'))) {
				
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
	clients[i].name = str;

	while (true) {
		flag1 = false;
		cout << "Фамилия: ";
		cin >> str;
		for (int j = 0; j < size(str); j++) {
			if (!((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'a' && str[j] <= 'z') || (str[j] >= 'А' && str[j] <= 'Я') || (str[j] >= 'а' && str[j] <= 'я'))) {
				
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
	clients[i].surname = str;

	while (true) {
		flag1 = false;
		cout << "Отчество: ";
		cin >> str;
		for (int j = 0; j < size(str); j++) {
			if (!((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'a' && str[j] <= 'z') || (str[j] >= 'А' && str[j] <= 'Я') || (str[j] >= 'а' && str[j] <= 'я'))) {
				
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
	clients[i].secondname = str;

	while (true) {
		cout << "1 - срочный\n2 - льготный\n3 - расчётный\n4 - кредитный\n";
		cin >> str;

		if (str[0] < '1' || str[0] > '4' || size(str) > 1) {
			
			cout << "Некорректное значение" << endl;
			
			continue;
		}
		break;
	}
	clients[i].type = stoi(str);
	while (true) {
		check = true;
		cout << "Номер счёта: ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (str[j] < '0' || str[j] > '9') {
				check = false;
			}
		}
		if (!check) {
			
			cout << "Некорректное значение" << endl;
			
			continue;
		}
		break;
	}
	clients[i].number = stoi(str);

	while (true) {
		check = true;
		cout << "Сумма на счёте: ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (str[j] < '0' || str[j] > '9') {
				check = false;
			}
			if (str[j] == '.') {
				check = true;
			}
		}
		if (!check) {
			
			cout << "Некорректное значение" << endl;
			
			continue;
		}
		break;
	}
	clients[i].sum = stof(str);

	cout << "Дата последнего изменения:\n";
	int months[]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	while (true) {
		check = true;
		cout << "Месяц ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (str[j] < '0' || str[j] > '9') {
				check = false;
			}
		}
		if (!check || stoi(str) > 12) {
			
			cout << "Некорректное значение" << endl;
			
			continue;
		}
		break;
	}
	clients[i].data_now.month = stoi(str);

	while (true) {
		check = true;
		cout << "Год: ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (str[j] < '0' || str[j] > '9') {
				check = false;
			}
		}
		if (!check || stoi(str) > 2023) {
			
			cout << "Некорректное значение" << endl;
			
			continue;
		}
		break;
	}
	clients[i].data_now.year = stoi(str);
	int year;
	while (true) {
		check = true;
		cout << "День: ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (str[j] < '0' || str[j] > '9') {
				check = false;
			}
		}
		year = 2000 + clients[i].data_now.year;
		if ((year % 4 == 0) || ((year % 100 == 0) && (year % 400 == 0))) {
			if (clients[i].data_now.month == 2 && stoi(str) > 29) {
				check = false;
			}
			if (clients[i].data_now.month != 2 && stoi(str) > months[clients[i].data_now.month - 1]) {
				check = false;
			}
		}
		else {
			if (stoi(str) > months[clients[i].data_now.month - 1]) {
				check = false;
			}
		}
		if (!check) {
			
			cout << "Некорректное значение" << endl;
			
			continue;
		}

		break;
	}
	clients[i].data_now.day = stoi(str);
	i++;
}

void output() {
	
	for (int j = 0; j < i; j++) {
		cout << clients[j].name << " " << clients[j].surname << " " << clients[j].secondname << " ";
		switch (clients[j].type) {
		case emergency: cout << "срочный" << " "; break;
		case preferential: cout << "льготный" << " "; break;
		case payment: cout << "расчётный" << " "; break;
		case credit: cout << "кредитный" << " "; break;
		}
		cout << clients[j].number << " " << clients[j].sum << " ";
		if (clients[j].data_now.day < 10)
			cout << "0" << clients[j].data_now.day << ".";
		else
			cout << clients[j].data_now.day << ".";
		if (clients[j].data_now.month < 10)
			cout << "0" << clients[j].data_now.month << ".";
		else
			cout << clients[j].data_now.month << ".";
		if (clients[j].data_now.year < 10)
			cout << "0" << clients[j].data_now.year << endl;
		else
			cout << clients[j].data_now.year << endl;

	}
	
}

void find(int numb) {

	
	bool flag = false;
	int var;
	cout << "1 - до 100, 2 - более 100 ";
	cin >> var;
	switch (var)
	{
	case 1:
		for (int j = 0; j < i; j++)
		{
			if (clients[j].sum < 100)
			{
				cout << "ФИО              " << clients[j].name << " " << clients[j].surname << " " << clients[j].secondname << " " << endl;
				cout << "Тип счета        ";
				switch (clients[j].type) {
				case emergency: cout << "срочный" << " "; break;
				case preferential: cout << "льготный" << " "; break;
				case payment: cout << "расчётный" << " "; break;
				case credit: cout << "кредитный" << " "; break;
				}
				cout << endl << "Номер счета     |" << clients[j].number << endl
					<< "Сумма на счете   " << clients[j].sum << endl;
				cout << "Дата посл измен  ";
				if (clients[j].data_now.day < 10)
					cout << "0" << clients[j].data_now.day << ".";
				else
					cout << clients[j].data_now.day << ".";
				if (clients[j].data_now.month < 10)
					cout << "0" << clients[j].data_now.month << ".";
				else
					cout << clients[j].data_now.month << ".";
				if (clients[j].data_now.year < 10)
					cout << "0" << clients[j].data_now.year << endl;
				else
					cout << clients[j].data_now.year << endl;
				flag = true;
			}
			//break;
		}break;
	case 2:
		for (int j = 0; j < i; j++)
		{
			if (clients[j].sum >= 100)
			{
				cout << "ФИО              " << clients[j].name << " " << clients[j].surname << " " << clients[j].secondname << " " << endl;
				cout << "Тип счета        ";
				switch (clients[j].type) {
				case emergency: cout << "срочный" << " "; break;
				case preferential: cout << "льготный" << " "; break;
				case payment: cout << "расчётный" << " "; break;
				case credit: cout << "кредитный" << " "; break;
				}
				cout << endl << "Номер счета      " << clients[j].number << endl
					<< "Сумма на счете   " << clients[j].sum << endl;
				cout << "Дата посл измен  ";
				if (clients[j].data_now.day < 10)
					cout << "0" << clients[j].data_now.day << ".";
				else
					cout << clients[j].data_now.day << ".";
				if (clients[j].data_now.month < 10)
					cout << "0" << clients[j].data_now.month << ".";
				else
					cout << clients[j].data_now.month << ".";
				if (clients[j].data_now.year < 10)
					cout << "0" << clients[j].data_now.year << endl;
				else
					cout << clients[j].data_now.year << endl;
				flag = true;
			}
		}
		break;

	}
	if (!flag)
		cout << "Ничего не найдено\n";
	
}