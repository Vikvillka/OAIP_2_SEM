//��� ��������� p1 �� ������ ��������� ������. �������� ������� ����������� ���������� ����� � ������� �������.
#include <iostream>
#include <fstream>
using namespace std;

struct Tree          //������
{
	int key;         //����
	int data1, data2;		 //����� - �� ����� 4 ����
	Tree* Left, * Right;
};

int countChet = 0;

Tree* Root = NULL; 	//��������� �����
Tree* Root1 = NULL;
int maxi = 0;
Tree* makeTree(Tree* Root);       //�������� ������
Tree* list(int i, int d1, int d2);       //�������� ������ ��������
Tree* insertElem(Tree* Root, int key, int data1, int data2);  //���������� ������ ��������
Tree* search(Tree* n, int key);   //����� �������� �� ����� 
Tree* delet(Tree* Root, int key); //�������� �������� �� �����
void leafes(Tree* Root);
void view(Tree* t, int level);    //����� ������ 
int counter = 0;
void delAll(Tree* t);             //������� ������
void searchmax();
void searchmaxi(Tree* Root);
void sum(Tree* t, int level);

void main()
{

	setlocale(0, "Russian");
	int key, choice, n;
	Tree* rc;
	for (;;)
	{
		cout << "��������, ��� �������:\n1 - ������� ������;\n2 - �������� �������;\n3 - ����� �� �����;\n4 - ������� �������;"
			"\n5 - ������� ������;\n6 - �������� ������;\n7 - ������� ������� � ������������ ������ ���� �������� ����;\n8 - �����.\n";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case 1:  Root = makeTree(Root);	break;
		case 2:  int data1, data2; cout << "\n������� ���� � ��� �����: "; cin >> key >> data1 >> data2;

			insertElem(Root, key, data1, data2); break;
		case 3:  cout << "\n������� ����: ";  cin >> key;
			rc = search(Root, key);
			break;
		case 4:  cout << "\n������� ��������� ����: "; cin >> key;
			Root = delet(Root, key);  break;
		case 5:  if (Root->key >= 0)
		{
			cout << "������ ��������� �� 90 �������� �����" << endl;
			view(Root, 0);
		}
			  else cout << "������ ������\n";
			break;
		case 6:  delAll(Root); break;
		case 7: cout << "���������� ������ ���������: "; sum(Root, 0); cout << countChet << '\n'; break;
		case 8:  exit(0);
		}
	}
}

Tree* makeTree(Tree* Root)    //�������� ������
{
	int key, data1, data2;
	cout << "����� ����� - ������������� �����\n\n";
	if (Root == NULL)	// ���� ������ �� �������
	{
		cout << "������� ���� �����: "; cin >> key;
		cout << "������� ��� ����� �����: "; cin >> data1 >> data2;
		Root = list(key, data1, data2);	// ��������� ��������� �� ������
	}
	while (1)                //���������� ���������
	{
		cout << "\n������� ����: ";  cin >> key;
		if (key < 0) break;       //������� ������ (���� < 0)   
		cout << "������� ��� �����: "; cin >> data1 >> data2;
		insertElem(Root, key, data1, data2);
	}
	return Root;
}

Tree* list(int i, int d1, int d2)     //�������� ������ ��������
{
	Tree* t = new Tree[sizeof(Tree)];
	t->key = i;
	t->data1 = d1;
	t->data2 = d2;
	t->Left = t->Right = NULL;
	return t;
}

Tree* insertElem(Tree* t, int key, int data1, int data2)  //���������� ������ ��������
{
	Tree* Prev = nullptr;	     // Prev - ������� ����� �������
	int find = 0;        // ������� ������
	while (t && !find)
	{
		Prev = t;
		//	if (key == t->key)
	//			find = 1;	   //����� ������ ���� ���������
		//	else
		if (key <= t->key) t = t->Left;
		else t = t->Right;
	}
	if (!find)              //������� ����� � ������� Prev
	{
		t = list(key, data1, data2);           //��������� ����� ���� 
		if (key <= Prev->key)  // � �������������� ���� 
			Prev->Left = t;    //������� �� ����� �����,
		else
			Prev->Right = t;   // ���� �� ������ 
	}
	return t;
}

Tree* delet(Tree* Root, int key)  //�������� �������� �� �����
{	// Del, Prev_Del - ��������� ������� � ��� ���������� ;
	// R, Prev_R - �������, �� ������� ���������� ���������, � ��� ��������; 
	Tree* Del, * Prev_Del, * R, * Prev_R;
	Del = Root;
	Prev_Del = NULL;
	while (Del != NULL && Del->key != key)//����� �������� � ��� �������� 
	{
		Prev_Del = Del;
		if (Del->key > key)
			Del = Del->Left;
		else
			Del = Del->Right;
	}
	if (Del == NULL)              // ������� �� ������
	{
		puts("\n��� ������ �����");
		return Root;
	}
	if (Del->Right == NULL) // ����� �������� R ��� ������
		R = Del->Left;
	else
		if (Del->Left == NULL)
			R = Del->Right;
		else
		{
			Prev_R = Del; //����� ������ ������� �������� � ����� ���������
			R = Del->Left;
			while (R->Right != NULL)
			{
				Prev_R = R;
				R = R->Right;
			}
			if (Prev_R == Del) // ������ ������� ��� ������ R � ��� �������� Prev_R 
				R->Right = Del->Right;
			else
			{
				R->Right = Del->Right;
				Prev_R->Right = R->Left;
				R->Left = Prev_R;
			}
		}
	if (Del == Root) Root = R;	//�������� ����� � ������ ��� �� R
	else
		// ��������� R �������������� � �������� ���������� ����
		if (Del->key < Prev_Del->key)
			Prev_Del->Left = R; // �� ����� ����� 
		else
			Prev_Del->Right = R;	// �� ������ �����
	int tmp = Del->key;
	cout << "\n������ ������� � ������ " << tmp << endl;
	delete Del;
	return Root;
}

Tree* search(Tree* n, int key)  //����� �������� �� ����� 
{
	Tree* rc = n;
	if (rc != NULL)
	{
		if (key < (key, n->key))
			rc = search(n->Left, key);
		else
			if (key > (key, n->key))
				rc = search(n->Right, key);
	}
	else
		cout << "��� ������ ��������\n";
	return rc;
}



void view(Tree* t, int level) //����� ������ 
{
	if (t)
	{
		view(t->Right, level + 1);	//����� ������� ���������
		for (int i = 0; i < level; i++)
			cout << "   ";
		int tm = t->key;
		cout << tm << ' ';
		cout << endl;
		view(t->Left, level + 1);	//����� ������ ���������
	}
}


void delAll(Tree* t) //������� ������
{
	if (t != NULL)
	{
		delAll(t->Left);
		delAll(t->Right);
		delete t;
	}
}


void leafes(Tree* Root)
{
	if (Root->Left == NULL && Root->Right == NULL)
	{
		counter++;
		return;
	}
	else
	{
		if (Root->Left) {
			leafes(Root->Left);
		}
		if (Root->Right) {
			leafes(Root->Right);
		}
	}

}

void searchmaxi(Tree* Root) {
	if (maxi <= Root->data1 + Root->data2)
	{
		maxi = Root->data1 + Root->data2;
		Root1 = Root;
	}
	if (Root->Left) {
		searchmaxi(Root->Left);
	}
	if (Root->Right) {
		searchmaxi(Root->Right);
	}
}
void searchmax() {
	Root1 = Root;
	maxi = Root->data1 + Root->data2;
	searchmaxi(Root);
	Root = delet(Root, Root1->key);
	cout << "������� � ������������ ������ " << maxi << " ��� �����. ";
}

void sum(Tree* t, int level)
{

	if (t)
	{
		sum(t->Right, level + 1);	//����� ������� ���������	
		if (t->key % 2 == 0)
			countChet++;

		sum(t->Left, level + 1);	//����� ������ ���������
	}


}