//���������. �.�.�., ���� ��������, �����, ��� (�, �).����������� ������� �� ���� � ���� ��������. 
# include <iostream> 
#include <iostream>
#include <fstream>
#include <string>
# define str_len 30                               
# define size 30  
#define chislo 9
int choice;
using namespace std;
struct Klient //���������
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

//�������� ����
void chek()
{
	int dol;
	//���������� ������ �� ����
	int mes = (list_of_gorozhanin[current_size].data_pr[2] - '0') * 10 + list_of_gorozhanin[current_size].data_pr[3] - '0';
	//���������� ��� �� ����
	int den = (list_of_gorozhanin[current_size].data_pr[0] - '0') * 10 + list_of_gorozhanin[current_size].data_pr[1] - '0';
	//��� �������� ������������ ����
	int cel = 0;
	int god = (list_of_gorozhanin[current_size].data_pr[4] - '0') * 1000 + (list_of_gorozhanin[current_size].data_pr[5] - '0') * 100 + (list_of_gorozhanin[current_size].data_pr[6] - '0') * 10 + list_of_gorozhanin[current_size].data_pr[7] - '0';

	while (list_of_gorozhanin[current_size].data_pr[0] > '3' || list_of_gorozhanin[current_size].data_pr[0] < '0' || mes > 12 || mes < 1 || den < 1 || den > 31) {

		

		cout << "||           �� ����������� ����� ����!               ||\n";


		cout << "||           ������� ����(� ������� ��������):          ||\n";
		
		cout << ">";
		cin >> list_of_gorozhanin[current_size].data_pr;
		//���������� ������ �� ����
		mes = (list_of_gorozhanin[current_size].data_pr[2] - '0') * 10 + list_of_gorozhanin[current_size].data_pr[3] - '0';
		//���������� ��� �� ����
		den = (list_of_gorozhanin[current_size].data_pr[0] - '0') * 10 + list_of_gorozhanin[current_size].data_pr[1] - '0';
		god = (list_of_gorozhanin[current_size].data_pr[4] - '0') * 1000 + (list_of_gorozhanin[current_size].data_pr[5] - '0') * 100 + (list_of_gorozhanin[current_size].data_pr[6] - '0') * 10 + list_of_gorozhanin[current_size].data_pr[7] - '0';

	}
	//���������� ���� �� ����
	god = (list_of_gorozhanin[current_size].data_ot[4] - '0') * 1000 + (list_of_gorozhanin[current_size].data_pr[5] - '0') * 100 + (list_of_gorozhanin[current_size].data_ot[6] - '0') * 10 + list_of_gorozhanin[current_size].data_pr[7] - '0';
	
}
void chek_ot()
{
	int dol;
	//���������� ������ �� ����
	int mes = (list_of_gorozhanin[current_size].data_ot[2] - '0') * 10 + list_of_gorozhanin[current_size].data_ot[3] - '0';
	//���������� ��� �� ����
	int den = (list_of_gorozhanin[current_size].data_ot[0] - '0') * 10 + list_of_gorozhanin[current_size].data_ot[1] - '0';
	//��� �������� ������������ ����
	int cel = 0;
	int god = (list_of_gorozhanin[current_size].data_ot[4] - '0') * 1000 + (list_of_gorozhanin[current_size].data_ot[5] - '0') * 100 + (list_of_gorozhanin[current_size].data_ot[6] - '0') * 10 + list_of_gorozhanin[current_size].data_ot[7] - '0';

	while (list_of_gorozhanin[current_size].data_pr[0] > '3' || list_of_gorozhanin[current_size].data_pr[0] < '0' || mes > 12 || mes < 1 || den < 1 || den > 31) {



		cout << "||           �� ����������� ����� ����!               ||\n";


		cout << "||           ������� ����(� ������� ��������):          ||\n";

		cout << ">";
		cin >> list_of_gorozhanin[current_size].data_ot;
		//���������� ������ �� ����
		mes = (list_of_gorozhanin[current_size].data_ot[2] - '0') * 10 + list_of_gorozhanin[current_size].data_ot[3] - '0';
		//���������� ��� �� ����
		den = (list_of_gorozhanin[current_size].data_ot[0] - '0') * 10 + list_of_gorozhanin[current_size].data_ot[1] - '0';
		god = (list_of_gorozhanin[current_size].data_ot[4] - '0') * 1000 + (list_of_gorozhanin[current_size].data_ot[5] - '0') * 100 + (list_of_gorozhanin[current_size].data_ot[6] - '0') * 10 + list_of_gorozhanin[current_size].data_ot[7] - '0';

	}
	//���������� ���� �� ����
	god = (list_of_gorozhanin[current_size].data_ot[4] - '0') * 1000 + (list_of_gorozhanin[current_size].data_ot[5] - '0') * 100 + (list_of_gorozhanin[current_size].data_ot[6] - '0') * 10 + list_of_gorozhanin[current_size].data_ot[7] - '0';

}
void enter_new() //������� �����
{
	ofstream file1("information.txt", ios::app);
	cout << "���� ����������" << endl;
	
	if (current_size < size)
	{
		cout << "������ ����� ";
		cout << current_size + 1;
		cout << endl << "��� ������� " << endl;
		cin >> list_of_gorozhanin[current_size].name;
		file1 << list_of_gorozhanin[current_size].name<<"\n";
		cout << endl << "������� ������� " << endl;
		cin >> list_of_gorozhanin[current_size].lastname;
		file1 << list_of_gorozhanin[current_size].lastname<<"\n";
		cout << endl << "����� �������� " << endl;
		cin >> list_of_gorozhanin[current_size].nomer_pasporta;
		file1 << list_of_gorozhanin[current_size].nomer_pasporta << "\n";
		cout << endl << "���� ������� (� ������� ��������)" << endl;
		static char data_pr[chislo];
		cin >> list_of_gorozhanin[current_size].data_pr;
		/*static char data_pr[chislo];
		cin >> data_pr;*/
		for (int i = 0; i < 8; i++)
		{
			if (list_of_gorozhanin[current_size].data_pr[i] > '9' || list_of_gorozhanin[current_size].data_pr[i] < '0') {
				
				cout << "\n";
				cout << "||       �� ����������o ����� ����     || \t\n";
				
				cout << "||   ������� ���� � ������� ��������   || \t\n";
				
				cin >> list_of_gorozhanin[current_size].data_pr;
			}
		}
		chek();
		file1 << list_of_gorozhanin[current_size].data_pr << "\n";
		static char data_ot[chislo];
		cout << endl << "���� ������� (� ������� ��������)" << endl;
		cin >> list_of_gorozhanin[current_size].data_ot;
		for (int i = 0; i < 8; i++)
		{
			if (list_of_gorozhanin[current_size].data_ot[i] > '9' || list_of_gorozhanin[current_size].data_ot[i] < '0') {

				cout << "\n";
				cout << "||       �� ����������o ����� ����     || \t\n";
				
				cout << "||   ������� ���� � ������� ��������   || \t\n";
				
				cin >> list_of_gorozhanin[current_size].data_ot;
			}
		}
		chek_ot();
		file1 << list_of_gorozhanin[current_size].data_ot << "\n";
		cout << endl << "����������� ����� " << endl;
		cin >> list_of_gorozhanin[current_size].nomer;
		file1 << list_of_gorozhanin[current_size].nomer << "\n";
		cout << endl << "��� ������ " << endl;
		cin >> list_of_gorozhanin[current_size].tip_nomera;
		file1 << list_of_gorozhanin[current_size].tip_nomera << "\n\n";
		current_size++;
	}
	else
		cout << "������� ������������ ���-�� �����";
}
void ofile()
{
	int N = 10;
	string buf;
	char num[10];
	
		cout << "������� ���������� ��������: ";
		
			cin >> num;
			while 
			 (num[0] != '1' || num[0] != '2' || num[0] != '3' || num[0] != '4' || num[0] != '5') {
				cout << "������� �����: ";
				cin >> num;
			
		
	fflush(stdin);
	ofstream file1("information.txt");
	for (int i = 0; i < 2; i++)
	{
		cout << "\t������ �" << i + 1 << '\n';
		file1 << "\t������ �" << i + 1 << '\n';
		cout << "������� ��� �������:\n";
		file1 << "��� �������: ";
		cin >> list_of_gorozhanin[current_size].name;
		file1 << list_of_gorozhanin[current_size].name;

		cout << "������� ������� �������:\n";
		file1 << "������� �������: ";
		cin >> list_of_gorozhanin[current_size].lastname;
		file1 << list_of_gorozhanin[current_size].lastname;

		cout << "������� ����� ��������:\n";
		file1 << "\n����� ��������: ";
		cin >> list_of_gorozhanin[current_size].nomer_pasporta;
		file1 << list_of_gorozhanin[current_size].nomer_pasporta << "\n";
		
		cout << "������� ���� �������:\n";
		file1 << "���� �������: ";
		cin >> list_of_gorozhanin[current_size].data_pr;
		file1 << list_of_gorozhanin[current_size].data_pr << "\n";

		cout << "������� ���� �������:\n";
		file1 << "���� �������: ";
		cin >> list_of_gorozhanin[current_size].data_ot;
		file1 << list_of_gorozhanin[current_size].data_ot << "\n";

		cout << "������� ����������� �����:\n";
		file1 << "� ������: ";
		cin >> list_of_gorozhanin[current_size].nomer;
		file1 << list_of_gorozhanin[current_size].nomer << "\n";

		cout << "������e ��� ������:\n";
		file1 << "��� ����������: ";
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
void del() //������� ��������
{
	int d;
	cout << "\n����� ������, ������� ���� ������� (��� �������� ���� ����� ������ 22)" << endl;
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


void outputOneStructure(Klient oneGorozhanin) //����� ����� ������ 
{
	cout << "��� ";
	cout << oneGorozhanin.name << endl;
	cout << "������� ";
	cout << oneGorozhanin.lastname << endl;
	cout << "����� �������� ";
	cout << oneGorozhanin.nomer_pasporta << endl;
	cout << "���� ������� ";
	cout << oneGorozhanin.data_pr << endl;
	cout << "���� ������� ";
	cout << oneGorozhanin.data_ot << endl;
	cout << "����������� ����� ";
	cout << oneGorozhanin.nomer << endl;
	cout << "��� ���������� ";
	cout << oneGorozhanin.tip_nomera << endl;
	cout << endl;
}


void out() //������� ������ ����������
{
	int sw, n;
	cout << "1-����� 1 ������" << endl;
	cout << "2-����� ���� �����" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "����� ��������� ������ " << endl;   cin >> n;  cout << endl;
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
void search() //������� ������ ���������

{
	char for_search[30];
	
	cout << "������� ������� ��� ������" << endl;;
	cin >> for_search;
	cout << endl;;
	int amount = 0;

	printf("���������:\n");
	for (int i = 0; i < size; i++)
	{

		if (strcmp(for_search, list_of_gorozhanin[i].lastname) == 0)
		{
			amount++;
			outputOneStructure(list_of_gorozhanin[i]);
		}

	}
	printf("����� �������:%d\n\n", amount);

	
}


int main()
{
	setlocale(LC_CTYPE, "Russian");
	char lastname[255];
	cout << "������ ���" << endl;
	do
	{
		cout << "�������:" << endl;
		cout << "1-��� �������� ������ " << endl;
		cout << "2-��� ����� ����� ������ " << endl;
		cout << "3-��� ������ �� ������� " << endl;
		cout << "4-��� ������ ������ " << endl;
		cout << "5-��� ����� � ���� " << endl;
		cout << "6-��� ������ �� ����� " << endl;
		cout << "7-��� ������ " << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:  del();	break;
		case 2:  enter_new();  break;

		case 3: {
			cout << "������� �������\n";
			search(); 
			break; 
		}
		case 4:  out();	break;
		case 5: ofile();	break;
		case 6: ifile();	break;
		}
	} while (choice != 7);
}
