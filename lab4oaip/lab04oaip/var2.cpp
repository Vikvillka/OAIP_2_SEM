//#include <iostream>
//#include <fstream>
//#include <string>
//
//using namespace std;
//
//int _stateMenu;
//
//struct BASE {
//    string name;
//    string sername;
//    string klass;
//    int scoreSub;
//    string subjects[50];
//    int mark[50];
//    float mm;
//};
//
//void Menu()
//{
//    cout << "Выберите действие" << endl;
//    cout << "Добавить ученика(1)" << endl;
//    cout << "Список учеников(2)" << endl;
//    cout << "Исключить ученика(3)" << endl;
//    cout << "Поиск по среднему баллу(4)" << endl;
//    cout << "Выход(5)" << endl;
//    cin >> _stateMenu;
//}
//
//int scoreElements = 0;
//
//void addItem(BASE base[])
//{
//    int sumMark = 0;
//
//    ofstream add("data.txt", ios::app);
//
//    cout << "Введите имя:";
//    cin >> base[scoreElements].name;
//    add << base[scoreElements].name << endl;
//    system("cls");
//
//    cout << "Введите фамилию:";
//    cin >> base[scoreElements].sername;
//    add << base[scoreElements].sername << endl;
//    system("cls");
//
//    cout << "Введите класс:";
//    cin >> base[scoreElements].klass;
//    add << base[scoreElements].klass << endl;
//    system("cls");
//
//    cout << "Введите количество предметов:";
//    cin >> base[scoreElements].scoreSub;
//    add << base[scoreElements].scoreSub << endl;
//    system("cls");
//
//    for (int i = 0; i < base[scoreElements].scoreSub; i++)
//    {
//        cout << "Введите " << i + 1 << " предмет" << endl;
//        cin >> base[scoreElements].subjects[i];
//        add << base[scoreElements].subjects[i] << " ";
//    }
//    add << endl;
//    for (int i = 0; i < base[scoreElements].scoreSub; i++)
//    {
//        cout << "Введите оценку по " << i + 1 << " предмету" << endl;
//        cin >> base[scoreElements].mark[i];
//        add << base[scoreElements].mark[i] << " ";
//    }
//    add << endl;
//    system("cls");
//
//    for (int i = 0; i < base[scoreElements].scoreSub; i++)
//    {
//        sumMark += base[scoreElements].mark[i];
//    }
//
//    base[scoreElements].mm = static_cast<float>(sumMark) / base[scoreElements].scoreSub;
//    add << base[scoreElements].mm << endl;
//
//    cout << "Данные успешно записаны" << endl;
//
//    scoreElements++;
//
//    add.close();
//}
//
//void showData(BASE base[])
//{
//    for (int i = 0; i < scoreElements; i++)
//    {
//        cout << base[i].sername << " " << base[i].name << " ============== " << base[i].mm << endl;
//    }
//}
//
//void delItem(BASE base[])
//{
//    ofstream del("data.txt");
//
//    int delIndex;
//    cout << "Введите элемент, который необходимо удалить" << endl;
//    cin >> delIndex;
//
//    for (int i = delIndex - 1; i + 1 < scoreElements; i++) {
//        base[i] = base[i + 1];
//    }
//    scoreElements--;
//
//    for (int i = 0; i < scoreElements; i++)
//    {
//        del << base[i].name << endl;
//        del << base[i].sername << endl;
//        del << base[i].klass << endl;
//        del << base[i].scoreSub << endl;
//        for (int j = 0; j < base[i].scoreSub; j++)
//        {
//            del << base[i].subjects[j] << " ";
//        }
//        del << endl;
//        for (int j = 0; j < base[i].scoreSub; j++)
//        {
//            del << base[i].mark[j] << " ";
//        }
//        del << endl;
//        del << base[i].mm << endl;
//    }
//}
//
//void findElement(BASE base[])
//{
//    float findIndex;
//
//    cout << "Введите средний балл" << endl;
//    cin >> findIndex;
//
//    for (int i = 0; i < scoreElements; i++)
//    {
//        if (base[i].mm == findIndex)
//        {
//            cout << base[i].name << " === " << base[i].mm << endl;
//        }
//    }
//}
//
//void getFile(BASE base[])
//{
//    ifstream out("data.txt");
//    string str;
//    int lineIndex = 0;
//    int markIndex = 0;
//    int subIndex = 0;
//    scoreElements = 0;
//
//    while (getline(out, str))
//    {
//        lineIndex++;
//    }
//    out.close();
//
//    scoreElements = lineIndex / 7;
//
//    ifstream out2("data.txt");
//    for (int i = 0; i < scoreElements; i++)
//    {
//        getline(out2, str);
//        base[i].name = str;
//
//        getline(out2, str);
//        base[i].sername = str;
//
//        getline(out2, str);
//        base[i].klass = str;
//
//        getline(out2, str);
//        base[i].scoreSub = stoi(str);
//
//        getline(out2, str);
//        for (int j = 0; j < (base[i].scoreSub * 2); j++)
//        {
//            base[i].subjects[subIndex] = str[j];
//            subIndex++;
//        }
//
//        getline(out2, str);
//        for (int j = 0; j < (base[i].scoreSub * 2); j += 2)
//        {
//            base[i].mark[markIndex] = str[j];
//            markIndex++;
//        }
//
//        getline(out2, str);
//
//        base[i].mm = strtof(str.c_str(), nullptr);
//    }
//
//    out2.close();
//}
//int main()
//{
//    setlocale(LC_ALL, "rus");
//    setlocale(LC_NUMERIC, "C");
//
//    BASE base[50];
//    getFile(base);
//
//    Menu();
//    while (_stateMenu != 5) {
//
//        switch (_stateMenu)
//        {
//        case 1:
//            system("cls");
//            addItem(base);
//            system("pause");
//            system("cls");
//            Menu();
//            break;
//        case 2:
//            system("cls");
//            showData(base);
//            system("pause");
//            system("cls");
//            Menu();
//            break;
//        case 3:
//            system("cls");
//            delItem(base);
//            system("pause");
//            system("cls");
//            Menu();
//            break;
//        case 4:
//            system("cls");
//            findElement(base);
//            system("pause");
//            system("cls");
//            Menu();
//            break;
//        default:
//            system("cls");
//            cout << "Неверно введен номер действия!" << endl;
//            system("pause");
//            system("cls");
//            Menu();
//            break;
//        }
//    }
//}
// Ломбард. База хранимых товаров и недвижимости: анкетные данные клиента, наименование товара, оценочная стоимость;
//сумма, выданная под залог, дата сдачи, срок хранения. Выбор по наименованию товара. 

//В программу должны войти функции:
//	ввод элементов структуры с клавиатуры;
//  вывод элементов структуры в консольное окно;
//	удаление заданной структурированной переменной;
//	поиск информации;
//	запись информации в файл;
//	чтение данных из файла.

#include <iostream>                    
# define str_len 30                               
# define size 30  
using namespace std;
void enter_new();
void input();
void del();
void out();
void search();
typedef struct Lombard
{
	char nameclient[str_len];
	char nametovar[40];
	int ocenka;
	int summa;
	int god;
	int hranenie;

} STUD;

int number; FILE* f; errno_t err;

struct Lombard lomb[size];
struct Lombard bad;

int current_size = 0; int choice;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "Введите:" << endl;
	cout << "1-для удаления записи" << endl;
	cout << "2-для ввода новой записи" << endl;
	cout << "3-для вывода записи(ей)" << endl;
	cout << "4-для записи информации в файл" << endl;
	cout << "5-для выхода" << endl;
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1:  del();	break;
		case 2:  enter_new();  break;
		case 3:  search();	break;
		case 4:  input();	break;
		}
	} while (choice != 5);
}
void search() //функция поиска информаци
{
	/*for (int i = 1; i <= kol; i++) {
		if (strcmp(lastname, list_of_gorozhanin[i].lastname) == 0) {
			cout << "Имя ";
			cout << list_of_gorozhanin[i].name << endl;
			cout << "Фамилия ";
			cout << list_of_gorozhanin[i].lastname << endl;
			cout << "Номер паспорта ";
			cout << list_of_gorozhanin[i].nomer_pasporta << endl;
			cout << "Дата приезда и отъезда ";
			cout << list_of_gorozhanin[i].data << endl;
			cout << "Гостиничный номер  ";
			cout << list_of_gorozhanin[i].nomer << endl;
			cout << "Тип размещения ";
			cout << list_of_gorozhanin[i].tip_nomera << endl;
			cout << endl;
		}
		else
			cout << "Клиент не найден";
	}*/

	char year_for_search[255];
	char  pol_for_search[str_len];
	cout << "Введите год рождения для поиска" << endl;;
	cin >> year_for_search;
	cout << endl;;
	int amount = 0;
	bool ignorePol = false;
	if (strcmp(pol_for_search, "*") == 0) {
		ignorePol = true;
	}
	printf("Результат:\n");
	for (int i = 0; i < size; i++)
	{

		if (year_for_search == lomb[i].nametovar)
		{
			amount++;
			cout << "tcn000000000000000";
		}

	}
	printf("Всего найдено:%d\n\n", amount);

}
void enter_new()
{
	cout << "Ввод информации" << endl;
	if (current_size < size)
	{
		cout << "Строка номер ";
		cout << current_size + 1;
		cout << endl << "Фамилия " << endl;
		cin >> lomb[current_size].nameclient;
		cout << endl << "Название товара " << endl;
		cin >> lomb[current_size].nametovar;
		cout << endl << "Оценочная стоимость " << endl;
		cin >> lomb[current_size].ocenka;
		cout << endl << "Сумма, выданная под залог " << endl;
		cin >> lomb[current_size].summa;
		cout << endl << "Дата сдачи " << endl;
		cin >> lomb[current_size].god;
		cout << endl << "Срок хранения " << endl;
		cin >> lomb[current_size].hranenie;
		current_size++;
	}
	else
		cout << "Введено максимальное кол-во строк";
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void del()
{
	int d;
	cout << "\nНомер строки, которую надо удалить (для удаления всех строк нажать 99)" << endl;  cin >> d;
	if (d != 99)
	{
		for (int de1 = (d - 1); de1 < current_size; de1++)
			lomb[de1] = lomb[de1 + 1];
		current_size = current_size - 1;
	}
	if (d == 99)
		for (int i = 0; i < size; i++)
			lomb[i] = bad;
	cout << "Что дальше?" << endl;
	cin >> choice;
}

void out()
{
	int sw, n;
	cout << "1-вывод 1 строки" << endl;
	cout << "2-вывод всех строк" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "Номер выводимой строки " << endl;   cin >> n;  cout << endl;
		cout << endl << "Фамилия " << endl;
		cout << lomb[n - 1].nameclient;
		cout << endl << "Название товара " << endl;
		cout << lomb[n - 1].nametovar;
		cout << "Оценочная стоимость " << endl;
		cout << lomb[n - 1].ocenka;
		cout << "Сумма, выданная под залог " << endl;
		cout << lomb[n - 1].summa;
		cout << "Дата сдачи " << endl;
		cout << lomb[n - 1].god;
		cout << "Срок хранения " << endl;
		cout << lomb[n - 1].hranenie;
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << endl << "Фамилия " << endl;
			cout << lomb[i].nameclient;
			cout << endl << "Название товара " << endl;
			cout << lomb[i].nametovar;
			cout << "Оценочная стоимость " << endl;
			cout << lomb[i].ocenka;
			cout << "Сумма, выданная под залог " << endl;
			cout << lomb[i].summa;
			cout << "Дата сдачи " << endl;
			cout << lomb[i].god;
			cout << "Срок хранения " << endl;
			cout << lomb[i].hranenie;
		}
	}
	cout << "Что дальше?" << endl;
	cin >> choice;
}

void input()
{
	if (!fopen_s(&f, "base.txt", "ab"))
	{
		for (int p = 0; p < 1; p++)
		{
			fwrite(&lomb[p].nameclient, sizeof(lomb[p].nameclient), 1, f);
		}
		fclose(f);
	}
	else {
		cout << "Ошибка открытия файла";
		return;
	}
}
