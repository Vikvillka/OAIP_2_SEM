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
	cout << "\n����� ������, ������� ���� ������� " << endl;
	cin >> d;
	if (d != 22)
	{
		for (int j = (d-1); j < i; j++) {
			clients[j] = clients[j + 1];
			i = i - 1;
		}
		cout << "������ �������" << endl;
	}
}
int main() {
	setlocale(LC_CTYPE, "Rus");

	while (true) {
		
		cout << "\n1 - ������ �������\n2 - ������� ����������\n3 - ����� �������\n4 - ��������\n";
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
		cout << "���: ";
		cin >> str;
		for (int j = 0; j < size(str); j++) {
			if (!((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'a' && str[j] <= 'z') || (str[j] >= '�' && str[j] <= '�') || (str[j] >= '�' && str[j] <= '�'))) {
				
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
	clients[i].name = str;

	while (true) {
		flag1 = false;
		cout << "�������: ";
		cin >> str;
		for (int j = 0; j < size(str); j++) {
			if (!((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'a' && str[j] <= 'z') || (str[j] >= '�' && str[j] <= '�') || (str[j] >= '�' && str[j] <= '�'))) {
				
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
	clients[i].surname = str;

	while (true) {
		flag1 = false;
		cout << "��������: ";
		cin >> str;
		for (int j = 0; j < size(str); j++) {
			if (!((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'a' && str[j] <= 'z') || (str[j] >= '�' && str[j] <= '�') || (str[j] >= '�' && str[j] <= '�'))) {
				
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
	clients[i].secondname = str;

	while (true) {
		cout << "1 - �������\n2 - ��������\n3 - ���������\n4 - ���������\n";
		cin >> str;

		if (str[0] < '1' || str[0] > '4' || size(str) > 1) {
			
			cout << "������������ ��������" << endl;
			
			continue;
		}
		break;
	}
	clients[i].type = stoi(str);
	while (true) {
		check = true;
		cout << "����� �����: ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (str[j] < '0' || str[j] > '9') {
				check = false;
			}
		}
		if (!check) {
			
			cout << "������������ ��������" << endl;
			
			continue;
		}
		break;
	}
	clients[i].number = stoi(str);

	while (true) {
		check = true;
		cout << "����� �� �����: ";
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
			
			cout << "������������ ��������" << endl;
			
			continue;
		}
		break;
	}
	clients[i].sum = stof(str);

	cout << "���� ���������� ���������:\n";
	int months[]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	while (true) {
		check = true;
		cout << "����� ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (str[j] < '0' || str[j] > '9') {
				check = false;
			}
		}
		if (!check || stoi(str) > 12) {
			
			cout << "������������ ��������" << endl;
			
			continue;
		}
		break;
	}
	clients[i].data_now.month = stoi(str);

	while (true) {
		check = true;
		cout << "���: ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (str[j] < '0' || str[j] > '9') {
				check = false;
			}
		}
		if (!check || stoi(str) > 2023) {
			
			cout << "������������ ��������" << endl;
			
			continue;
		}
		break;
	}
	clients[i].data_now.year = stoi(str);
	int year;
	while (true) {
		check = true;
		cout << "����: ";
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
			
			cout << "������������ ��������" << endl;
			
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
		case emergency: cout << "�������" << " "; break;
		case preferential: cout << "��������" << " "; break;
		case payment: cout << "���������" << " "; break;
		case credit: cout << "���������" << " "; break;
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
	cout << "1 - �� 100, 2 - ����� 100 ";
	cin >> var;
	switch (var)
	{
	case 1:
		for (int j = 0; j < i; j++)
		{
			if (clients[j].sum < 100)
			{
				cout << "���              " << clients[j].name << " " << clients[j].surname << " " << clients[j].secondname << " " << endl;
				cout << "��� �����        ";
				switch (clients[j].type) {
				case emergency: cout << "�������" << " "; break;
				case preferential: cout << "��������" << " "; break;
				case payment: cout << "���������" << " "; break;
				case credit: cout << "���������" << " "; break;
				}
				cout << endl << "����� �����     |" << clients[j].number << endl
					<< "����� �� �����   " << clients[j].sum << endl;
				cout << "���� ���� �����  ";
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
				cout << "���              " << clients[j].name << " " << clients[j].surname << " " << clients[j].secondname << " " << endl;
				cout << "��� �����        ";
				switch (clients[j].type) {
				case emergency: cout << "�������" << " "; break;
				case preferential: cout << "��������" << " "; break;
				case payment: cout << "���������" << " "; break;
				case credit: cout << "���������" << " "; break;
				}
				cout << endl << "����� �����      " << clients[j].number << endl
					<< "����� �� �����   " << clients[j].sum << endl;
				cout << "���� ���� �����  ";
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
		cout << "������ �� �������\n";
	
}