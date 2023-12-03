#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void input();
void output();

struct time {
	int hours;
	int minutes;
};

struct train {
	int number_of_train;
	string destination;
	struct time time;
};

int choice;
int i = 0;
struct train trains[8];
string str;

int main() {
	setlocale(LC_CTYPE, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (true) {
		
		cout << "Что вы хотите сделать?\n1 - Добавить поезд\n2 - Найти подходящие\n0 - Выход" << endl;
		cin >> str;

		if (str[0] < '0' || str[0] > '2' || size(str) > 1) {
			
			cout << "Некорректное значение" << endl;
			system("pause");
			continue;
		}

		choice = stoi(str);

		switch (choice) {
		case 1:
			input();
			break;
		case 2:
			output();
			break;
		case 0:
			exit(0);
			break;
		}
	}
}

void input() {
	system("cls");


	bool check;
	while (true) {
		check = true;
		cout << "Номер поезда: ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (str[j] < '1' || str[j] > '9') {
				check = false;
			}
		}
		if (!check) {
			
			cout << "Некорректное значение" << endl;
			system("pause");
			continue;
		}
		break;
	}

	trains[i].number_of_train = stoi(str);
	bool flag1;
	while (true) {
		flag1 = false;
		cout << "Пунк назначения: ";
		cin.ignore();
		getline(cin, str);
		
		for (int j = 0; j < size(str); j++) {
			if (!((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'a' && str[j] <= 'z') || (str[j] >= 'А' && str[j] <= 'Я') || (str[j] >= 'а' && str[j] <= 'я'))) {
				if (str[j] == ' '|| str[j] == '-') {
					break;
				}
				else {
					cout << "Некорректное значение" << endl;
					system("pause");
					flag1 = true;
					break;
				}
			}

		}
		if (flag1) {
			continue;
		}
		break;
	}
	trains[i].destination = str;
	while (true) {
		cout << "Время\tЧасы: ";
		cin >> trains[i].time.hours;
		if (trains[i].time.hours > 23) {
			cout << "Некорректное значение\n";
			continue;
		}
		break;
	}
	while (true) {
		cout << "Минуты: ";
		cin >> trains[i].time.minutes;
		if (trains[i].time.minutes > 59) {
			cout << "Некорректное значение\n";
			continue;
		}
		break;
	}
	i++;
	cout << endl << endl;
}

void sort() {
	struct train buf;
	for (int j = 0; j < i - 1; j++) {
		for (int k = j; k < i; k++) {
			if (trains[j].destination > trains[k].destination) {
				buf = trains[k];
				trains[k] = trains[j];
				trains[j] = buf;
			}
		}
	}
}

void output() {
	
	sort();

	int usershour, usersmin; bool flag = false;
	while (true) {
		cout << "Введите время" << endl;
		cout << "Часы: ";
		cin >> usershour;
		if (usershour > 23) {
			cout << "Некорректное значение\n";
			continue;
		}
		break;
	}
	while (true) {
		cout << "Минуты: ";
		cin >> usersmin;
		if (usersmin > 59) {
			cout << "Некорректное значение\n";
			continue;
		}
		break;
	}

	for (int j = 0; j < i; j++) {
		if ((trains[j].time.hours > usershour) || ((trains[j].time.hours == usershour) && (trains[j].time.minutes > usersmin))) {
			cout << "\n№" << trains[j].number_of_train << " " << trains[j].destination << " " << trains[j].time.hours << ":" << trains[j].time.minutes << endl;
			flag = true;
		}
	}
	if (!flag) {
		cout << "Не найдено " << endl;
	}
	system("pause");
}