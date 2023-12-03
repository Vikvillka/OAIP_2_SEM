//#include <iostream>
//#include <fstream>
//using namespace std;
//const unsigned int NAME_SIZE = 30;
//const unsigned int CITY_SIZE = 20;
//	
//struct Address
//{
//	char name[NAME_SIZE];
//	char city[CITY_SIZE];
//	Address* next;
//	Address* prev;
//};
//int counter = 0;
////-----------------------------------------------------------
//void insert(Address* e, Address** phead, Address** plast) //���������� � ����� ������
//{
//	Address* p = *plast;
//	if (*plast == NULL)
//	{
//		e->next = NULL;
//		e->prev = NULL;
//		*plast = e;
//		*phead = e;
//		counter++;
//		return;
//	}
//	else
//	{
//		p->next = e;
//		e->next = NULL;
//		e->prev = p;
//		*plast = e;
//		counter++;
//	}
//}
////-----------------------------------------------------------
//Address* setElement() // �������� �������� � ���� ��� �������� � ����������
//{
//	Address* temp = new Address();
//	if (!temp)
//	{
//		cerr << "������ ��������� ������ ������";
//		return NULL;
//	}
//	cout << "������� ���: ";
//	cin.getline(temp->name, NAME_SIZE - 1, '\n');
//	cin.ignore(cin.rdbuf()->in_avail());
//	cin.clear();
//	cout << "������� �����: ";
//	cin.getline(temp->city, CITY_SIZE - 1, '\n');
//	cin.ignore(cin.rdbuf()->in_avail());
//	cin.clear();
//
//	temp->next = NULL;
//	temp->prev = NULL;
//	return temp;
//}
////-----------------------------------------------------------
//void outputList(Address** phead, Address** plast) //����� ������ �� �����
//{
//	Address* t = *phead;
//	while (t)
//	{
//		cout << t->name << ' ' << t->city << endl;
//		t = t->next;
//	}
//	cout << "" << endl;
//}
////-----------------------------------------------------------
//void find(char name[NAME_SIZE], Address** phead) // ����� ����� � ������
//{
//	Address* t = *phead;
//	while (t)
//	{
//		if (!strcmp(name, t->name)) break;
//		t = t->next;
//	}
//	if (!t)
//		cerr << "��� �� �������" << endl;
//	else
//		cout << t->name << ' ' << t->city << endl;
//}
////-----------------------------------------------------------
//void delet(char name[NAME_SIZE], Address** phead, Address** plast)// �������� �������� �� �����
//{
//	struct Address* t = *phead;
//	while (t)
//	{
//		if (!strcmp(name, t->name)) break;
//		t = t->next;
//	}
//	if (!t)
//		cerr << "��� �� �������" << endl;
//	else
//	{
//		if (*phead == t)
//		{
//			*phead = t->next;
//			if (*phead)
//				(*phead)->prev = NULL;
//			else
//				*plast = NULL;
//		}
//		else
//		{
//			t->prev->next = t->next;
//			if (t != *plast)
//				t->next->prev = t->prev;
//			else
//				*plast = t->prev;
//		}
//		delete t;
//		cout << "������� ������" << endl;
//	}
//}
////-----------------------------------------------------------
//void writeToFile(Address** phead) //������ � ����
//{
//	struct Address* t = *phead;
//	ofstream file1("Lip.txt");
//	if (file1.fail())
//	{
//		cerr << "���� �� �����������" << endl;
//		exit(1);
//	}
//	cout << "���������� � ����" << endl;
//	while (t)
//	{
//		file1 << t->name << " " << t->city << endl;
//		t = t->next;
//	}
//	file1.close();
//}
////---------------------------------------------------------------
//void fromFile(Address** phead)
//{
//
//	char buf[256];
//	ifstream file2("Lip.txt");
//	if (file2.fail())
//	{
//		cout << "\n ������ �������� �����";
//		exit(1);
//	}
//	while (!file2.eof())
//	{
//		file2.getline(buf, 256);
//		if (strlen(buf))
//			cout << " " << buf;
//		cout << endl;
//	}
//
//	file2.close();
//}
//void deleteKElements(int k, Address*& phead, Address*& plast) {
//	Address* t;
//
//	if (counter < 2) {
//		cout << "������������ ��������\n";
//	}
//	else {
//		for (int i = 0; i < k; i++)
//		{
//			t = plast;
//			if (phead == t)
//			{
//				phead = t->next;
//				if (phead)
//					(phead)->prev = NULL;
//				else
//					plast = NULL;
//			}
//			else
//			{
//				t->prev->next = t->next;
//				if (t != plast)
//					t->next->prev = t->prev;
//				else
//					plast = t->prev;
//			}
//			delete t;
//		}
//		counter -= k;
//		cout << "�������� �������" << endl;
//	}
//
//}
////void deleteKElements(Address*& phead, int k) {
//////	Address* t;
//////	// ���������, ��� ������ ������ �� �������� NULL
//////	if (phead == NULL) {
//////		return;
//////	}
//////
//////	// ������� k ��������� � ������
//////	
//////	for (int i = 0; i < k && t != NULL; i++) {
//////		t = t->next;
//////	}
//////
//////	// ���� ����� �������, ��������� �� k-�, �� ������� ������ k ���������
//////	if (t != NULL) {
//////		// ��������� ������ ������
//////		phead = t;
//////
//////		// ������� ������ k ���������
//////		t->prev = NULL;
//////		while (t != NULL) {
//////			Address* next = t->next;
//////			delete t;
//////			t = next;
//////		}
//////	}
//////	// ���� ����� �� ����� ������, �� ������� ���� ������
//////	else {
//////		Address* t = phead;
//////		while (t != NULL) {
//////			Address* next = t->next;
//////			delete t;
//////			t = next;
//////		}
//////		phead = NULL;
//////	}
//////}
/////*( int k, Address** phead) */
////	Address* t =phead;
////	for (int i = 0; i < k; i++) {
////		if (!t) {
////			return;
////		}
////		t = t->next;
////	}
////	if (!t) {
////		phead->prev = nullptr;
////		phead = nullptr;
////		return;
////	}
////	t->prev = nullptr;
////	phead = t;
////}
//
//int main()
//{
//	Address* head = NULL;
//	Address* last = NULL;
//	setlocale(LC_CTYPE, "Rus");
//	int choice;
//	char s[80]; int c, k;
//	cout << endl;
//	cout << "1. ���� ������" << endl;
//	cout << "2. �������� �����" << endl;
//	cout << "3. ����� �� �����" << endl;
//	cout << "4. �����" << endl;
//	cout << "5. � ����" << endl;
//	cout << "6. �� �����" << endl;
//	cout << "7. ������� �������� k ������ " << endl;
//	cout << "8. �����" << endl;
//	cout << endl;
//	for (;;)
//	{
//		cout << "��� �����: ";
//		cin.sync();
//		gets_s(s);
//		cout << endl;
//		c = atoi(s);
//
//		switch (c)
//		{
//		case 1: insert(setElement(), &head, &last);
//			break;
//		case 2: {	  char dname[NAME_SIZE];
//			cout << "������� ���: ";
//			cin.getline(dname, NAME_SIZE - 1, '\n');
//			cin.ignore(cin.rdbuf()->in_avail());
//			cin.sync();
//			delet(dname, &head, &last);
//		}
//			  break;
//
//		case 3: outputList(&head, &last);
//			break;
//		case 4: {	  
//			char fname[NAME_SIZE];
//			cout << "������� ���: ";
//			cin.getline(fname, NAME_SIZE - 1, '\n');
//			cin.ignore(cin.rdbuf()->in_avail());
//			cin.sync();
//			find(fname, &head);
//		}
//			  break;
//		case 5: {
//			writeToFile(&head);
//		}
//			  break;
//		case 6: {
//			fromFile(&head);
//		}
//			  break;
//		case 7: 
//			cout << "������� �: ";
//			cin >> k;
//			deleteKElements(k, head, last);
//			break;
//		case 8: exit(0);
//		default: exit(1);
//		}
//	}
//	return 0;
//}

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;

struct Address
{
    char name[NAME_SIZE];
    char city[CITY_SIZE];
    Address* next;
    Address* prev;
};

int counter = 0;

int menu(void)
{
    char s[80];  int c;
    cout << endl;
    cout << "1. ���� �����" << endl;
    cout << "2. �������� �����" << endl;
    cout << "3. ����� �� �����" << endl;
    cout << "4. �����" << endl;
    cout << "5. ������ � ����" << endl;
    cout << "6. ������ �� �����" << endl;
    cout << "7. �������� K ��������� ���������" << endl;
    cout << "8. �����" << endl;
    cout << endl;
    do
    {
        cout << "��� �����: ";
        cin.sync();
        cin.ignore(cin.rdbuf()->in_avail());
        cin.clear();
        gets_s(s);
        cout << endl;
        c = atoi(s);
    } while (c < 0 || c > 8);
    return c;
}

void insert(Address* e, Address** phead, Address** plast) //���������� � ����� ������
{
    Address* p = *plast;
    if (*plast == NULL)
    {
        e->next = NULL;
        e->prev = NULL;
        *plast = e;
        *phead = e;
        counter++;
        return;
    }
    else
    {
        p->next = e;
        e->next = NULL;
        e->prev = p;
        *plast = e;
        counter++;
    }

}
//----------------------------------------------------------- 
Address* setElement()      // �������� �������� � ���� ��� �������� � ����������
{
    Address* temp = new  Address();
    if (!temp)
    {
        cerr << "������ ��������� ������ ������";
        return NULL;
    }
    cout << "������� ���: ";
    cin.getline(temp->name, NAME_SIZE - 1, '\n');
    cin.ignore(cin.rdbuf()->in_avail());
    cin.clear();
    cout << "������� �����: ";
    cin.getline(temp->city, CITY_SIZE - 1, '\n');
    cin.ignore(cin.rdbuf()->in_avail());
    cin.clear();
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
//-----------------------------------------------------------
void outputList(Address** phead, Address** plast)      //����� ������ �� �����
{
    Address* t = *phead;
    while (t)
    {

        cout << t->name << ' ' << t->city << endl;
        t = t->next;
    }
    cout << "" << endl;
}
//-----------------------------------------------------------
void find(char name[NAME_SIZE], Address** phead)    // ����� ����� � ������
{
    Address* t = *phead;
    while (t)
    {
        if (!strcmp(name, t->name))
            break;
        t = t->next;
    }
    if (!t)
        cerr << "��� �� �������" << endl;
    else
        cout << t->name << ' ' << t->city << endl;
}
//-----------------------------------------------------------
void delet(char name[NAME_SIZE], Address** phead, Address** plast)  // �������� ����� 
{
    struct Address* t = *phead;
    while (t)
    {
        if (!strcmp(name, t->name))
            break;
        t = t->next;
    }

    if (!t)
        cerr << "��� �� �������" << endl;
    else
    {
        if (*phead == t)
        {
            *phead = t->next;
            if (*phead)
                (*phead)->prev = NULL;
            else
                *plast = NULL;
        }
        else
        {
            t->prev->next = t->next;
            if (t != *plast)
                t->next->prev = t->prev;
            else
                *plast = t->prev;
        }
        delete t;
        counter--;
        cout << "������� ������" << endl;
    }
}

void writeToFile(Address** phead)  //������ � ����
{
    ofstream fout;
    fout.open("file.txt");
    Address* t = *phead;
    if (phead == NULL) {
        cout << "������ ����" << endl;
    }
    else {
        if (fout.is_open()) {
            while (t != NULL) {
                fout << t->name << ' ' << t->city << endl;
                t = t->next;
            }

            cout << "������ � ���� ������� ���������" << endl;
            fout.close();
        }
        else {
            cout << "error" << endl;
        }
    }
}
//-----------------------------------------------------------
void readFromFile(Address** phead, Address** plast)   //���������� �� �����
{
    string str;
    ifstream fin;

    fin.open("file.txt");
    if (fin.is_open()) {
        while (!fin.eof()) {
            getline(fin, str);
            cout << str << endl;
        }
    }
    else {
        cout << "error" << endl;
    }
}


void deleteKLast(int k, Address*& phead, Address*& plast) {
    Address* t;

    if (counter < k) {
        cout << "������������ ��������\n";
    }
    else {
        for (int i = 0; i < k; i++)
        {
            t = phead;
            if (phead == t)
            {
                phead = t->next;
                if (phead)
                    (phead)->prev = NULL;
                else
                    plast = NULL;
            }
            else
            {
                t->prev->next = t->next;
                if (t != plast)
                    t->next->prev = t->prev;
                else
                    plast = t->prev;
            }
            delete t;
        }
        counter += k;
        cout << "�������� �������" << endl;
    }

}

//-----------------------------------------------------------
int main(void) {
    setlocale(LC_CTYPE, "Rus");
    Address* head = NULL;
    Address* last = NULL;


    while (true)
    {
        switch (menu())
        {
        case 1:  insert(setElement(), &head, &last);
            break;
        case 2: {
            char dname[NAME_SIZE];
            cout << "������� ���: ";
            cin.getline(dname, NAME_SIZE - 1, '\n');
            cin.ignore(cin.rdbuf()->in_avail());
            cin.sync();
            delet(dname, &head, &last);
        }
              break;
        case 3: outputList(&head, &last);
            break;
        case 4: {
            char fname[NAME_SIZE];
            cout << "������� ���: ";
            cin.getline(fname, NAME_SIZE - 1, '\n');
            cin.ignore(cin.rdbuf()->in_avail());
            cin.sync();
            find(fname, &head);
        }
              break;
        case 5:writeToFile(&head); break;
        case 6:readFromFile(&head, &last); break;
        case 7:
            int k;
            cout << "������� ���������� k: ";
            cin >> k;
            deleteKLast(k, head, last);
            break;
        case 8: exit(0);
        default: exit(1);
        }
    }
    return 0;
}






