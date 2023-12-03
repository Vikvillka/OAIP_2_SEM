#include <iostream>
#include <algorithm>

using namespace std;
struct Tri
{
	int value;
	Tri* left;
	Tri* right;
};

int* create();
Tri* makeTree(Tri* Root, int key);
Tri* list(int i);
Tri* insertElem(Tri* t, int key);
void view(Tri* t, int level);
int N;
int main()
{
	setlocale(LC_ALL, "rus");
	int* delta = create();
	Tri* Root = new Tri;
	Root = makeTree(Root, delta[0]);
	for (int i = 1; i < N; i++)
	{
		insertElem(Root, delta[i]);
	}
	view(Root, 0);
	system("pause");
	return 0;
}
int* create()
{
	cout << "������� ���������� ���������: "; cin >> N;
	int* mass = new int[N];
	for (int i = 0; i < N; i++)
	{
		cout << "������� ����� ������� �������: "; cin >> mass[i];
	}
	std::sort(mass, mass + N);
	for (int i = 1; i < N; i += 2)
	{
		int t = mass[i - 1];
		mass[i - 1] = mass[i];
		mass[i] = t;
	}
	for (int i = 0; i < N; i++)
	{
		cout << "�������� �������: "; cout << mass[i] << endl;
	}
	return mass;
}
Tri* list(int i)     //�������� ������ ��������
{
	Tri* t = new Tri[sizeof(Tri)];
	t->value = i;
	t->left = t->right = NULL;
	return t;
}
Tri* makeTree(Tri* Root, int key)    //�������� ������
{
	Root = list(key);	// ��������� ��������� �� ������
	
	return Root;
}
Tri* insertElem(Tri* t, int key)  //���������� ������ ��������
{
	Tri* Prev = NULL;	     // Prev - ������� ����� �������
	int find = 0;        // ������� ������
	while (t && !find)
	{
		Prev = t;
		if (key == t->value)
			find = 1;	   //����� ������ ���� ���������
		else
			if (key < t->value) t = t->left;
			else t = t->right;
	}
	if (!find)              //������� ����� � ������� Prev
	{
		t = list(key);           //��������� ����� ���� 
		if (key < Prev->value)  // � �������������� ���� 
			Prev->left = t;    //������� �� ����� �����,
		else
			Prev->right = t;   // ���� �� ������ 
	}
	return t;
}

void view(Tri* t, int level) //����� ������ 
{
	cout << t->value;
	if (t)
	{
		view(t->right, level + 1);	//����� ������� ���������
		for (int i = 0; i < level; i++)
			cout << "   ";
		int tm = t->value;
		cout << tm << endl;
		view(t->left, level + 1);	//����� ������ ���������
	}
}
