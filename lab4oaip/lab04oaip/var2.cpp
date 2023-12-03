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
//    cout << "�������� ��������" << endl;
//    cout << "�������� �������(1)" << endl;
//    cout << "������ ��������(2)" << endl;
//    cout << "��������� �������(3)" << endl;
//    cout << "����� �� �������� �����(4)" << endl;
//    cout << "�����(5)" << endl;
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
//    cout << "������� ���:";
//    cin >> base[scoreElements].name;
//    add << base[scoreElements].name << endl;
//    system("cls");
//
//    cout << "������� �������:";
//    cin >> base[scoreElements].sername;
//    add << base[scoreElements].sername << endl;
//    system("cls");
//
//    cout << "������� �����:";
//    cin >> base[scoreElements].klass;
//    add << base[scoreElements].klass << endl;
//    system("cls");
//
//    cout << "������� ���������� ���������:";
//    cin >> base[scoreElements].scoreSub;
//    add << base[scoreElements].scoreSub << endl;
//    system("cls");
//
//    for (int i = 0; i < base[scoreElements].scoreSub; i++)
//    {
//        cout << "������� " << i + 1 << " �������" << endl;
//        cin >> base[scoreElements].subjects[i];
//        add << base[scoreElements].subjects[i] << " ";
//    }
//    add << endl;
//    for (int i = 0; i < base[scoreElements].scoreSub; i++)
//    {
//        cout << "������� ������ �� " << i + 1 << " ��������" << endl;
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
//    cout << "������ ������� ��������" << endl;
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
//    cout << "������� �������, ������� ���������� �������" << endl;
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
//    cout << "������� ������� ����" << endl;
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
//            cout << "������� ������ ����� ��������!" << endl;
//            system("pause");
//            system("cls");
//            Menu();
//            break;
//        }
//    }
//}
// �������. ���� �������� ������� � ������������: �������� ������ �������, ������������ ������, ��������� ���������;
//�����, �������� ��� �����, ���� �����, ���� ��������. ����� �� ������������ ������. 

//� ��������� ������ ����� �������:
//	���� ��������� ��������� � ����������;
//  ����� ��������� ��������� � ���������� ����;
//	�������� �������� ����������������� ����������;
//	����� ����������;
//	������ ���������� � ����;
//	������ ������ �� �����.

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
	cout << "�������:" << endl;
	cout << "1-��� �������� ������" << endl;
	cout << "2-��� ����� ����� ������" << endl;
	cout << "3-��� ������ ������(��)" << endl;
	cout << "4-��� ������ ���������� � ����" << endl;
	cout << "5-��� ������" << endl;
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
void search() //������� ������ ���������
{
	/*for (int i = 1; i <= kol; i++) {
		if (strcmp(lastname, list_of_gorozhanin[i].lastname) == 0) {
			cout << "��� ";
			cout << list_of_gorozhanin[i].name << endl;
			cout << "������� ";
			cout << list_of_gorozhanin[i].lastname << endl;
			cout << "����� �������� ";
			cout << list_of_gorozhanin[i].nomer_pasporta << endl;
			cout << "���� ������� � ������� ";
			cout << list_of_gorozhanin[i].data << endl;
			cout << "����������� �����  ";
			cout << list_of_gorozhanin[i].nomer << endl;
			cout << "��� ���������� ";
			cout << list_of_gorozhanin[i].tip_nomera << endl;
			cout << endl;
		}
		else
			cout << "������ �� ������";
	}*/

	char year_for_search[255];
	char  pol_for_search[str_len];
	cout << "������� ��� �������� ��� ������" << endl;;
	cin >> year_for_search;
	cout << endl;;
	int amount = 0;
	bool ignorePol = false;
	if (strcmp(pol_for_search, "*") == 0) {
		ignorePol = true;
	}
	printf("���������:\n");
	for (int i = 0; i < size; i++)
	{

		if (year_for_search == lomb[i].nametovar)
		{
			amount++;
			cout << "tcn000000000000000";
		}

	}
	printf("����� �������:%d\n\n", amount);

}
void enter_new()
{
	cout << "���� ����������" << endl;
	if (current_size < size)
	{
		cout << "������ ����� ";
		cout << current_size + 1;
		cout << endl << "������� " << endl;
		cin >> lomb[current_size].nameclient;
		cout << endl << "�������� ������ " << endl;
		cin >> lomb[current_size].nametovar;
		cout << endl << "��������� ��������� " << endl;
		cin >> lomb[current_size].ocenka;
		cout << endl << "�����, �������� ��� ����� " << endl;
		cin >> lomb[current_size].summa;
		cout << endl << "���� ����� " << endl;
		cin >> lomb[current_size].god;
		cout << endl << "���� �������� " << endl;
		cin >> lomb[current_size].hranenie;
		current_size++;
	}
	else
		cout << "������� ������������ ���-�� �����";
	cout << "��� ������?" << endl;
	cin >> choice;
}
void del()
{
	int d;
	cout << "\n����� ������, ������� ���� ������� (��� �������� ���� ����� ������ 99)" << endl;  cin >> d;
	if (d != 99)
	{
		for (int de1 = (d - 1); de1 < current_size; de1++)
			lomb[de1] = lomb[de1 + 1];
		current_size = current_size - 1;
	}
	if (d == 99)
		for (int i = 0; i < size; i++)
			lomb[i] = bad;
	cout << "��� ������?" << endl;
	cin >> choice;
}

void out()
{
	int sw, n;
	cout << "1-����� 1 ������" << endl;
	cout << "2-����� ���� �����" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "����� ��������� ������ " << endl;   cin >> n;  cout << endl;
		cout << endl << "������� " << endl;
		cout << lomb[n - 1].nameclient;
		cout << endl << "�������� ������ " << endl;
		cout << lomb[n - 1].nametovar;
		cout << "��������� ��������� " << endl;
		cout << lomb[n - 1].ocenka;
		cout << "�����, �������� ��� ����� " << endl;
		cout << lomb[n - 1].summa;
		cout << "���� ����� " << endl;
		cout << lomb[n - 1].god;
		cout << "���� �������� " << endl;
		cout << lomb[n - 1].hranenie;
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << endl << "������� " << endl;
			cout << lomb[i].nameclient;
			cout << endl << "�������� ������ " << endl;
			cout << lomb[i].nametovar;
			cout << "��������� ��������� " << endl;
			cout << lomb[i].ocenka;
			cout << "�����, �������� ��� ����� " << endl;
			cout << lomb[i].summa;
			cout << "���� ����� " << endl;
			cout << lomb[i].god;
			cout << "���� �������� " << endl;
			cout << lomb[i].hranenie;
		}
	}
	cout << "��� ������?" << endl;
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
		cout << "������ �������� �����";
		return;
	}
}
