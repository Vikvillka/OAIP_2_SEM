//Горожанин. Ф.И.О., дата рождения, адрес, пол (м, ж).Реализовать выборку по полу и году рождения. 
# include <iostream> 
#include <iostream>
#include <fstream>
#include <string>
# define str_len 30                               
# define size 30  
#define chislo 9
int choice;
using namespace std;
struct Klient //структура
{
	char name[str_len];
	char lastname[255];
	char nomer_pasporta[str_len];
	char data_pr[chislo];
	char data_ot[9];
	char nomer[str_len];
	char tip_nomera[str_len];
};

struct Klient list_of_gorozhanin[size];
struct Klient bad;
int current_size = 0;

//ПРОВЕРКА ДАТЫ
void chek()
{
	int dol;
	//извлечение месяца из даты
	int mes = (list_of_gorozhanin[current_size].data_pr[2] - '0') * 10 + list_of_gorozhanin[current_size].data_pr[3] - '0';
	//извлечение дня из даты
	int den = (list_of_gorozhanin[current_size].data_pr[0] - '0') * 10 + list_of_gorozhanin[current_size].data_pr[1] - '0';
	//Доп проверка корректности даты
	int cel = 0;
	int god = (list_of_gorozhanin[current_size].data_pr[4] - '0') * 1000 + (list_of_gorozhanin[current_size].data_pr[5] - '0') * 100 + (list_of_gorozhanin[current_size].data_pr[6] - '0') * 10 + list_of_gorozhanin[current_size].data_pr[7] - '0';

	while (list_of_gorozhanin[current_size].data_pr[0] > '3' || list_of_gorozhanin[current_size].data_pr[0] < '0' || mes > 12 || mes < 1 || den < 1 || den > 31) {

		

		cout << "||           Вы некорректно ввели дату!               ||\n";


		cout << "||           Введите дату(в формате ДДММГГГГ):          ||\n";
		
		cout << ">";
		cin >> list_of_gorozhanin[current_size].data_pr;
		//извлечение месяца из даты
		mes = (list_of_gorozhanin[current_size].data_pr[2] - '0') * 10 + list_of_gorozhanin[current_size].data_pr[3] - '0';
		//извлечение дня из даты
		den = (list_of_gorozhanin[current_size].data_pr[0] - '0') * 10 + list_of_gorozhanin[current_size].data_pr[1] - '0';
		god = (list_of_gorozhanin[current_size].data_pr[4] - '0') * 1000 + (list_of_gorozhanin[current_size].data_pr[5] - '0') * 100 + (list_of_gorozhanin[current_size].data_pr[6] - '0') * 10 + list_of_gorozhanin[current_size].data_pr[7] - '0';

	}
	//извлечение года из даты
	god = (list_of_gorozhanin[current_size].data_ot[4] - '0') * 1000 + (list_of_gorozhanin[current_size].data_pr[5] - '0') * 100 + (list_of_gorozhanin[current_size].data_ot[6] - '0') * 10 + list_of_gorozhanin[current_size].data_pr[7] - '0';
	
}
void chek_ot()
{
	int dol;
	//извлечение месяца из даты
	int mes = (list_of_gorozhanin[current_size].data_ot[2] - '0') * 10 + list_of_gorozhanin[current_size].data_ot[3] - '0';
	//извлечение дня из даты
	int den = (list_of_gorozhanin[current_size].data_ot[0] - '0') * 10 + list_of_gorozhanin[current_size].data_ot[1] - '0';
	//Доп проверка корректности даты
	int cel = 0;
	int god = (list_of_gorozhanin[current_size].data_ot[4] - '0') * 1000 + (list_of_gorozhanin[current_size].data_ot[5] - '0') * 100 + (list_of_gorozhanin[current_size].data_ot[6] - '0') * 10 + list_of_gorozhanin[current_size].data_ot[7] - '0';

	while (list_of_gorozhanin[current_size].data_pr[0] > '3' || list_of_gorozhanin[current_size].data_pr[0] < '0' || mes > 12 || mes < 1 || den < 1 || den > 31) {



		cout << "||           Вы некорректно ввели дату!               ||\n";


		cout << "||           Введите дату(в формате ДДММГГГГ):          ||\n";

		cout << ">";
		cin >> list_of_gorozhanin[current_size].data_ot;
		//извлечение месяца из даты
		mes = (list_of_gorozhanin[current_size].data_ot[2] - '0') * 10 + list_of_gorozhanin[current_size].data_ot[3] - '0';
		//извлечение дня из даты
		den = (list_of_gorozhanin[current_size].data_ot[0] - '0') * 10 + list_of_gorozhanin[current_size].data_ot[1] - '0';
		god = (list_of_gorozhanin[current_size].data_ot[4] - '0') * 1000 + (list_of_gorozhanin[current_size].data_ot[5] - '0') * 100 + (list_of_gorozhanin[current_size].data_ot[6] - '0') * 10 + list_of_gorozhanin[current_size].data_ot[7] - '0';

	}
	//извлечение года из даты
	god = (list_of_gorozhanin[current_size].data_ot[4] - '0') * 1000 + (list_of_gorozhanin[current_size].data_ot[5] - '0') * 100 + (list_of_gorozhanin[current_size].data_ot[6] - '0') * 10 + list_of_gorozhanin[current_size].data_ot[7] - '0';

}
void enter_new() //функция ввода
{
	ofstream file1("information.txt", ios::app);
	cout << "Ввод информации" << endl;
	
	if (current_size < size)
	{
		cout << "Строка номер ";
		cout << current_size + 1;
		cout << endl << "Имя клиента " << endl;
		cin >> list_of_gorozhanin[current_size].name;
		file1 << list_of_gorozhanin[current_size].name<<"\n";
		cout << endl << "Фамилия клиента " << endl;
		cin >> list_of_gorozhanin[current_size].lastname;
		file1 << list_of_gorozhanin[current_size].lastname<<"\n";
		cout << endl << "Номер паспорта " << endl;
		cin >> list_of_gorozhanin[current_size].nomer_pasporta;
		file1 << list_of_gorozhanin[current_size].nomer_pasporta << "\n";
		cout << endl << "Дата приезда (в формате ДДММГГГГ)" << endl;
		static char data_pr[chislo];
		cin >> list_of_gorozhanin[current_size].data_pr;
		/*static char data_pr[chislo];
		cin >> data_pr;*/
		for (int i = 0; i < 8; i++)
		{
			if (list_of_gorozhanin[current_size].data_pr[i] > '9' || list_of_gorozhanin[current_size].data_pr[i] < '0') {
				
				cout << "\n";
				cout << "||       Вы некорректнo ввели дату     || \t\n";
				
				cout << "||   Введите дату в формате ДДММГГГГ   || \t\n";
				
				cin >> list_of_gorozhanin[current_size].data_pr;
			}
		}
		chek();
		file1 << list_of_gorozhanin[current_size].data_pr << "\n";
		static char data_ot[chislo];
		cout << endl << "Дата отъезда (в формате ДДММГГГГ)" << endl;
		cin >> list_of_gorozhanin[current_size].data_ot;
		for (int i = 0; i < 8; i++)
		{
			if (list_of_gorozhanin[current_size].data_ot[i] > '9' || list_of_gorozhanin[current_size].data_ot[i] < '0') {

				cout << "\n";
				cout << "||       Вы некорректнo ввели дату     || \t\n";
				
				cout << "||   Введите дату в формате ДДММГГГГ   || \t\n";
				
				cin >> list_of_gorozhanin[current_size].data_ot;
			}
		}
		chek_ot();
		file1 << list_of_gorozhanin[current_size].data_ot << "\n";
		cout << endl << "Гостинечный номер " << endl;
		cin >> list_of_gorozhanin[current_size].nomer;
		file1 << list_of_gorozhanin[current_size].nomer << "\n";
		cout << endl << "Тип номера " << endl;
		cin >> list_of_gorozhanin[current_size].tip_nomera;
		file1 << list_of_gorozhanin[current_size].tip_nomera << "\n\n";
		current_size++;
	}
	else
		cout << "Введено максимальное кол-во строк";
}
void ofile()
{
	int N = 10;
	string buf;
	char num[10];
	
		cout << "Введите количество клиентов: ";
		
			cin >> num;
			while 
			 (num[0] != '1' || num[0] != '2' || num[0] != '3' || num[0] != '4' || num[0] != '5') {
				cout << "Введите цифру: ";
				cin >> num;
			
		
	fflush(stdin);
	ofstream file1("information.txt");
	for (int i = 0; i < 2; i++)
	{
		cout << "\tКлиент №" << i + 1 << '\n';
		file1 << "\tКлиент №" << i + 1 << '\n';
		cout << "Введите имя клиента:\n";
		file1 << "Имя клиента: ";
		cin >> list_of_gorozhanin[current_size].name;
		file1 << list_of_gorozhanin[current_size].name;

		cout << "Введите фамилию клиента:\n";
		file1 << "Фамилия клиента: ";
		cin >> list_of_gorozhanin[current_size].lastname;
		file1 << list_of_gorozhanin[current_size].lastname;

		cout << "Введите номер паспорта:\n";
		file1 << "\nНомер паспорта: ";
		cin >> list_of_gorozhanin[current_size].nomer_pasporta;
		file1 << list_of_gorozhanin[current_size].nomer_pasporta << "\n";
		
		cout << "Введите дату приезда:\n";
		file1 << "Дата приезда: ";
		cin >> list_of_gorozhanin[current_size].data_pr;
		file1 << list_of_gorozhanin[current_size].data_pr << "\n";

		cout << "Введите дату отъезда:\n";
		file1 << "Дата отъезда: ";
		cin >> list_of_gorozhanin[current_size].data_ot;
		file1 << list_of_gorozhanin[current_size].data_ot << "\n";

		cout << "Введите гостинечный номер:\n";
		file1 << "№ номера: ";
		cin >> list_of_gorozhanin[current_size].nomer;
		file1 << list_of_gorozhanin[current_size].nomer << "\n";

		cout << "Введитe тип номера:\n";
		file1 << "Тип размещения: ";
		cin >> list_of_gorozhanin[current_size].tip_nomera;
		file1 << list_of_gorozhanin[current_size].tip_nomera << "\n\n";
	}
	cout << "\n\n";
}}
void ifile()
{
	string strInf;
	ifstream file1("information.txt");
	while (file1)
	{
		getline(file1, strInf);
		cout << strInf << '\n';
	}
}
void del() //функция удаления
{
	int d;
	cout << "\nНомер строки, которую надо удалить (для удаления всех строк нажать 22)" << endl;
	cin >> d;
	if (d != 22)
	{
		for (int de1 = (d - 1); de1 < current_size; de1++)
			list_of_gorozhanin[de1] = list_of_gorozhanin[de1 + 1];
		current_size = current_size - 1;
	}
	if (d == 22)
		for (int i = 0; i < size; i++)
			list_of_gorozhanin[i] = bad;
}


void outputOneStructure(Klient oneGorozhanin) //вывод одной строки 
{
	cout << "Имя ";
	cout << oneGorozhanin.name << endl;
	cout << "Фамилия ";
	cout << oneGorozhanin.lastname << endl;
	cout << "Номер паспорта ";
	cout << oneGorozhanin.nomer_pasporta << endl;
	cout << "Дата приезда ";
	cout << oneGorozhanin.data_pr << endl;
	cout << "Дата отъезда ";
	cout << oneGorozhanin.data_ot << endl;
	cout << "Гостиничный номер ";
	cout << oneGorozhanin.nomer << endl;
	cout << "Тип размещения ";
	cout << oneGorozhanin.tip_nomera << endl;
	cout << endl;
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
		outputOneStructure(list_of_gorozhanin[n - 1]);
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			outputOneStructure(list_of_gorozhanin[i]);
		}
	}
}
void search() //функция поиска информаци

{
	char for_search[30];
	
	cout << "Введите фамилия для поиска" << endl;;
	cin >> for_search;
	cout << endl;;
	int amount = 0;

	printf("Результат:\n");
	for (int i = 0; i < size; i++)
	{

		if (strcmp(for_search, list_of_gorozhanin[i].lastname) == 0)
		{
			amount++;
			outputOneStructure(list_of_gorozhanin[i]);
		}

	}
	printf("Всего найдено:%d\n\n", amount);

	
}


int main()
{
	setlocale(LC_CTYPE, "Russian");
	char lastname[255];
	cout << "Данных нет" << endl;
	do
	{
		cout << "Введите:" << endl;
		cout << "1-для удаления записи " << endl;
		cout << "2-для ввода новой записи " << endl;
		cout << "3-для поиска по фамилии " << endl;
		cout << "4-для вывода записи " << endl;
		cout << "5-для ввода в файл " << endl;
		cout << "6-для вывода из файла " << endl;
		cout << "7-для выхода " << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:  del();	break;
		case 2:  enter_new();  break;

		case 3: {
			cout << "Введите фамилию\n";
			search(); 
			break; 
		}
		case 4:  out();	break;
		case 5: ofile();	break;
		case 6: ifile();	break;
		}
	} while (choice != 7);
}
