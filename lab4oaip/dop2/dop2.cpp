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
		
		cout << "��� �� ������ �������?\n1 - �������� �����\n2 - ����� ����������\n0 - �����" << endl;
		cin >> str;

		if (str[0] < '0' || str[0] > '2' || size(str) > 1) {
			
			cout << "������������ ��������" << endl;
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
		cout << "����� ������: ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (str[j] < '1' || str[j] > '9') {
				check = false;
			}
		}
		if (!check) {
			
			cout << "������������ ��������" << endl;
			system("pause");
			continue;
		}
		break;
	}

	trains[i].number_of_train = stoi(str);
	bool flag1;
	while (true) {
		flag1 = false;
		cout << "���� ����������: ";
		cin.ignore();
		getline(cin, str);
		
		for (int j = 0; j < size(str); j++) {
			if (!((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'a' && str[j] <= 'z') || (str[j] >= '�' && str[j] <= '�') || (str[j] >= '�' && str[j] <= '�'))) {
				if (str[j] == ' '|| str[j] == '-') {
					break;
				}
				else {
					cout << "������������ ��������" << endl;
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
		cout << "�����\t����: ";
		cin >> trains[i].time.hours;
		if (trains[i].time.hours > 23) {
			cout << "������������ ��������\n";
			continue;
		}
		break;
	}
	while (true) {
		cout << "������: ";
		cin >> trains[i].time.minutes;
		if (trains[i].time.minutes > 59) {
			cout << "������������ ��������\n";
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
		cout << "������� �����" << endl;
		cout << "����: ";
		cin >> usershour;
		if (usershour > 23) {
			cout << "������������ ��������\n";
			continue;
		}
		break;
	}
	while (true) {
		cout << "������: ";
		cin >> usersmin;
		if (usersmin > 59) {
			cout << "������������ ��������\n";
			continue;
		}
		break;
	}

	for (int j = 0; j < i; j++) {
		if ((trains[j].time.hours > usershour) || ((trains[j].time.hours == usershour) && (trains[j].time.minutes > usersmin))) {
			cout << "\n�" << trains[j].number_of_train << " " << trains[j].destination << " " << trains[j].time.hours << ":" << trains[j].time.minutes << endl;
			flag = true;
		}
	}
	if (!flag) {
		cout << "�� ������� " << endl;
	}
	system("pause");
}