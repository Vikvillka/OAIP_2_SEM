//Номер поезда, пункт назначения, время прибытия,
//время отправления. 
//Выбор по пункту назначения.
#include <iostream>  
#include<fstream>
# include <iostream> 
#include <iostream>
#include <fstream>
#include <string>
# define size 100  
using namespace std;
void enter_new();
void out();
void search();

union forvokzal
{
	char str[40];
	int limb;
};
struct vokzal
{
	forvokzal name;
	string punct;
	forvokzal vremzot;
	forvokzal vremzpr;
};
vokzal raspisanie[size];
int current_size = 0; int choice;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "Введите число:" << endl;
	cout << "1-для ввода записи" << endl;
	cout << "2-для вывода записи" << endl;
	cout << "3-для поиска информации" << endl;
	
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1:  enter_new();	break;
		case 2:  out();  break;
		case 3:  search();	break;
		
		}
	} while (choice != 4);
}


void enter_new()
{
	cout << "Ввод информации" << endl;
	if (current_size < size)
	{
		cout << "Строка номер  ";
		cout << current_size + 1;
		cout << "\n";
		
		cout << endl << "номер поезда:" << endl;
		cin >> raspisanie[current_size].name.str;
		cout << "пункт назначения:" << endl;
		cin.ignore();
		getline(cin, raspisanie[current_size].punct);
		cout << "время отправления:" << endl;
		cin >> raspisanie[current_size].vremzot.str;
		cout << "время прибытия:" << endl;
		cin >> raspisanie[current_size].vremzpr.str;
		current_size++;

	}
	else
		cout << "Введено максимальное кол-во строк";
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void out()
{
	int sw, n;
	cout << "1-вывести 1 строку" << endl;
	cout << "2-вывести все строки" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "Номер выводимой строки: " << endl;
		cin >> n;
		cout << endl;
		
		cout << "номер поезда ";
		cout << raspisanie[n - 1].name.str;
		cout << endl;
		cout << "пункт назначения ";
		cout << raspisanie[n - 1].punct;
		cout << endl;
		cout << "время отправления ";
		cout << raspisanie[n - 1].vremzot.str;
		cout << endl;
		cout << "время прибытия ";
		cout << raspisanie[n - 1].vremzpr.str;
		cout << endl;


	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << "номер поезда ";
			cout << raspisanie[i].name.str;
			cout << endl;
			cout << "пункт назначения ";
			cout << raspisanie[i].punct;
			cout << endl;
			cout << "время отправления ";
			cout << raspisanie[i].vremzot.str;
			cout << endl;
			cout << "время прибытия ";
			cout << raspisanie[i].vremzpr.str;
			cout << endl;
		}
	}
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void search()
{
	string name;
	cout << "Введите фамилию:" << "\n";
	cin.ignore();
	getline(cin, name);
	for (int z = 0; z < current_size; z++)
	{
		if (raspisanie[z].punct==name)
		{
			cout << "номер поезда ";
			cout << raspisanie[z].name.str;
			cout << endl;
			cout << "пункт назначения ";
			cout << raspisanie[z].punct;
			cout << endl;
			cout << "время отправления ";
			cout << raspisanie[z].vremzot.str;
			cout << endl;
			cout << "время прибытия ";
			cout << raspisanie[z].vremzpr.str;
			cout << endl;
		}
	}
	cout << "Что дальше?" << endl;
	cin >> choice;
}