//Горожанин. Ф.И.О., дата рождения, адрес, пол (м, ж). Выборка по году рождения.
//Дату рождения организовать с помощью битового поля, пол  с помощью перечисления.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<fstream>
# include <iostream> 
#include <iostream>
#include <fstream>
#include <string>
# define str_len 256
# define size 100
using namespace std;

struct notebook
{
	char name[str_len];
	char surname[30];
	char middlename[str_len];
	unsigned day : 4;
	unsigned mounth : 4;
	unsigned year : 16;
	string addres;
	int pol;
};
struct notebook people_in_notebook[size];
int current_size = 0;
int choice; 
char ff[30];
notebook all;
notebook b;
enum poll
{
	woman=1, man
};

int l, z, x;
void enter_new()
{
	cout << "ввод информации" << endl;
	if (current_size < size)
	{
		cout << "строка номер ";
		cout << current_size + 1;
		cout << endl << "фамилия" << endl;
		cin >> people_in_notebook[current_size].surname;
		cout << "имя" << endl;
		cin >> people_in_notebook[current_size].name;
		cout << "отчество" << endl;
		cin >> people_in_notebook[current_size].middlename;
		cout << "дата рождения: " << endl;
		cout << "день:";
		cin >> l; 
		if (l < 31)
		{
			b.day = l;

		}
		else
		{
			cout << "неправильно введен день" << endl;
			cin >> l;
			b.day = l;
		}
		cout << endl;
		cout << "месяц:";
		cin >> z; 
		if (z < 13)
		{
			b.mounth = z;
		}
		else
		{
			cout << "неправильно введен месяц"<<endl;
			cin >> z;
			b.mounth = z;
		}
		cout << endl;
		cout << "год:";
		cin >> x;
		if (x < 2022)
		{
			b.year = x;
		}
		else
		{
			cout << "не могли родиться в этом году" << endl;
			cin >> x;
			b.year = x;
		}
		cout << endl;
		cout << "адрес:" << endl;
		cin.ignore();
		getline(cin, people_in_notebook[current_size].addres);
		cout << "пол(1 = женский, 2 = мужской):" << endl;
		cin >> people_in_notebook[current_size].pol;
		current_size++;
	}
	else
		cout << "введено максимальное кол-во строк";
	
}
void outputOneStructure( notebook one) //вывод одной строки 
{
	cout << "фамилия ";
	cout << one.surname << endl;
	cout << "имя ";
	cout << one.name << endl;
	cout << "отчество ";
	cout << one.middlename << endl;
	cout << "день  ";
	cout << b.day << endl;
	cout << "месяц ";
	cout << b.mounth << endl;
	cout << "год ";
	cout << b.year << endl;
	cout << "адрес ";
	cout << one.addres << endl;
	cout << "пол:" << endl;
	if (one.pol == 1)
		cout << "woman" << endl;
	else if (one.pol == 2)
		cout << "man" << endl;
	
}

void out() //функция вывода информации
{
	int sw, n;
	cout << "1-вывод 1 строки" << endl;
	cout << "2-вывод всех строк" << endl;
	
	cin >> sw;
	if (sw == 1)
	{
		cout << "Номер выводимой строки " << endl;   cin >> n;  cout << endl;
		outputOneStructure(people_in_notebook[n-1]);
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			outputOneStructure(people_in_notebook[i]);
		}
	}

}
void del()
{
	int d;
	cout << "\nномер строки, которую надо удалить (для удаления всех строк нажать 99)" << endl;
	cin >> d;
	if (d != 99)
	{
		for (int de1 = (d - 1); de1 < current_size; de1++)
			people_in_notebook[de1] = people_in_notebook[de1 + 1];
		current_size = current_size - 1;
	}
	if (d == 99)
		for (int i = 0; i < size; i++)
			people_in_notebook[i] = all;

}
void search()
{
	int god;
	cout << "год:" << endl << endl;
	cin >> god;
	cout << endl;
	for (int q = 0; q < 1; q++)
	{
		if (god == x)
		{
			outputOneStructure(people_in_notebook[q]);
		}
	}
	
}
int main()
{do
	{
	setlocale(LC_CTYPE, "Russian");
	cout << "введите:" << endl;
	cout << "1-для ввода записи" << endl;
	cout << "2-для вывода записи" << endl;
	cout << "3-для удаления" << endl;
	cout << "4-для поиска информации" << endl;
	cout << "5-для выхода" << endl;
	cin >> choice;
	
		switch (choice)
		{
		case 1: enter_new(); break;
		case 2: out(); break;
		case 3: del(); break;
		case 4: search(); break;


		}
	} while (choice != 5);
}
