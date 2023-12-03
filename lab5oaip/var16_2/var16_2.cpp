#include <iostream>
#include <string>

using namespace std;

int n = 100;

struct date {
	unsigned int day : 5;
	unsigned int month : 4;
	unsigned int year : 16;
};

union buff {
	char str1[50];
	int n;
} buff;

struct student {
	string name;
	string surname;
	string secondname;
	date date_now;
	string speciality;
	int group;
	string faculty;
	float mark;
} students[20];

void input();
void output();
void find();

string str, surname;
bool flag1, check;
int i;

void del() {
	int d;
	cout << "\n����� ������, ������� ���� ������� " << endl;
	cin >> d;
	if (d != 22)
	{
		for (int j = (d-1); j < i; j++) {
			students[j] = students[j + 1];
			i = i - 1;
		}
		cout << "������ �������" << endl;
	}
}
int main() {
	setlocale(LC_CTYPE, "Rus");

	while (true) {
		cout << "\n1 - ������ ����� ������\n2 - �������� ������\n3 - ����� �� �������� �����\n 4 - ��������\n";
		cin >> buff.str1;
		str = buff.str1;

		if (str[0] < '0' || str[0] > '5' || size(str) > 1) {
			cout << "������������ ��������" << endl;
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
		cout << "���: ";
		cin >> str;
		for (int j = 0; j < size(str); j++) {
			if (!isalpha(str[j])) {
				cout << "������������ ��������" << endl;
				flag1 = true;
				break;
			}

		}
		if (flag1) {
			continue;
		}
		break;
	}
	students[i].name = str;

	while (true) {
		flag1 = false;
		cout << "�������: ";
		cin >> str;
		for (int j = 0; j < size(str); j++) {
			if (!isalpha(str[j])) {
				cout << "������������ ��������" << endl;
				flag1 = true;
				break;
			}

		}
		if (flag1) {
			continue;
		}
		break;
	}
	students[i].surname = str;

	while (true) {
		flag1 = false;
		cout << "��������: ";
		cin >> str;
		for (int j = 0; j < size(str); j++) {
			if (!isalpha(str[j])) {
				cout << "������������ ��������" << endl;
				flag1 = true;
				break;
			}

		}
		if (flag1) {
			continue;
		}
		break;
	}
	students[i].secondname = str;

	cout << "���� �����������:\n";
	int months[]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	while (true) {
		check = true;
		cout << "����� ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (!isdigit(str[j])) {
				check = false;
			}
		}
		if (!check || stoi(str) > 12) {
			cout << "������������ ��������" << endl;
			continue;
		}
		break;
	}
	students[i].date_now.month = stoi(str);

	while (true) {
		check = true;
		cout << "���: ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (!isdigit(str[j])) {
				check = false;
			}
		}
		if (!check || stoi(str) > 2023) {
			
			cout << "������������ ��������" << endl;
			
			continue;
		}
		break;
	}
	students[i].date_now.year = stoi(str);
	int year;
	while (true) {
		check = true;
		cout << "����: ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (!isdigit(str[j])) {
				check = false;
			}
		}
		year = 2000 + students[i].date_now.year;
		if ((year % 4 == 0) || ((year % 100 == 0) && (year % 400 == 0))) {
			if (students[i].date_now.month == 2 && stoi(str) > 29) {
				check = false;
			}
			if (students[i].date_now.month != 2 && stoi(str) > months[students[i].date_now.month - 1]) {
				check = false;
			}
		}
		else {
			if (stoi(str) > months[students[i].date_now.month - 1]) {
				check = false;
			}
		}
		if (!check) {
			
			cout << "������������ ��������" << endl;
			
			continue;
		}

		break;
	}
	students[i].date_now.day = stoi(str);

	while (true) {
		flag1 = false;
		cout << "�������������: ";
		cin.ignore();
		getline(cin, str);
		for (int j = 0; j < size(str); j++) {
			if (!isalpha(str[j])) {
				if (str[j] == ' ') {
					continue;
				}
				
				cout << "������������ ��������" << endl;
				
				flag1 = true;
				break;
			}

		}
		if (flag1) {
			continue;
		}
		break;
	}
	students[i].speciality = str;

	while (true) {
		check = true;
		cout << "������: ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (!isdigit(str[j])) {
				check = false;
			}
		}
		if (!check) {
			
			cout << "������������ ��������" << endl;
			
			continue;
		}
		break;
	}
	students[i].group = stoi(str);

	while (true) {
		flag1 = false;
		cout << "���������: ";
		cin.ignore();
		getline(cin, str);
		for (int j = 0; j < size(str); j++) {
			if (!isalpha(str[j])) {
				if (str[j] == ' ') {
					continue;
				}
				
				cout << "������������ ��������" << endl;
				
				flag1 = true;
				break;
			}

		}
		if (flag1) {
			continue;
		}
		break;
	}
	students[i].faculty = str;

	while (true) {
		check = true;
		cout << "������� ����: ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (!isdigit(str[j])) {
				if (str[j] == '.')
					continue;
				check = false;
			}
		}
		if (!check || stof(str) > 10.0) {
			
			cout << "������������ ��������" << endl;
			
			continue;
		}
		break;
	}
	students[i].mark = stof(str);

	i++;
}

void output() {
	for (int j = 0; j < i; j++) {
		cout << students[j].surname << " " << students[j].name << " " << students[j].secondname << " ";
		if (students[j].date_now.day < 10)
			cout << "0" << students[j].date_now.day << ".";
		else
			cout << students[j].date_now.day << ".";
		if (students[j].date_now.month < 10)
			cout << "0" << students[j].date_now.month << ".";
		else
			cout << students[j].date_now.month << ".";
		if (students[j].date_now.year < 10)
			cout << "0" << students[j].date_now.year << " ";
		else
			cout << students[j].date_now.year << " ";
		cout << students[j].speciality << " " << students[j].group << " " << students[j].faculty << " " << students[j].mark << endl;
	}
	
}

void find() {
	bool flag = false, flag1 = false;


	while (true) {
		check = true;
		cout << "������� ������� ����: ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (!isdigit(str[j])) {
				if (str[j] = '.')
					flag1 = true;
				continue;
				check = false;
			}
		}
		if (!check || stoi(str) > 9.9) {
			
			cout << "������������ ��������" << endl;
			
			continue;
		}
		break;
	}
	for (int j = 0; j < i; j++) {
		if (students[j].mark == stof(str)) {
			cout << students[j].surname << " " << students[j].name << " " << students[j].secondname << " ";
			if (students[j].date_now.day < 10)
				cout << "0" << students[j].date_now.day << ".";
			else
				cout << students[j].date_now.day << ".";
			if (students[j].date_now.month < 10)
				cout << "0" << students[j].date_now.month << ".";
			else
				cout << students[j].date_now.month << ".";
			if (students[j].date_now.year < 10)
				cout << "0" << students[j].date_now.year << " ";
			else
				cout << students[j].date_now.year << " ";
			cout << students[j].speciality << " " << students[j].group << " " << students[j].faculty << " " << students[j].mark << endl;

			flag = true;
			cout << endl;
		}
	}
	if (!flag)
		cout << "������ �� �������\n";
}