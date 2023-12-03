#include <iostream>
#include <string>

#define black 0
#define red 1

using namespace std;

struct Tree //��������� �������� ������
{
	int val;
	bool color;
	Tree* left;
	Tree* right;
	Tree* parent;
} *head;

int add_k = 0;

void create(int); //�������� ������
void add(int); //������� ���������� ��������� � ������
void output(); //����� ������

void insert_case1(Tree*);
void insert_case2(Tree*);
void insert_case3(Tree*);
void insert_case4(Tree*);
void insert_case5(Tree*);
void rotate_right(Tree*);
void rotate_left(Tree*);

Tree* Ded(Tree*);
Tree* uncle(Tree*);

int main()
{
	create(20);
	add(1);
	add(3);
	add(5);
	add(20);
	add(4);
	add(6);
	add(13);
	add(17);
	add(15);
	add(21);
	output();
	Tree* iu = head;
	system("pause");
	return 0;
}

void create(int data) //�������� ������ (������ ������� �����)
{
	add_k++;
	head = new Tree;
	head->val = data;

	head->left = new Tree; //����� ���� ������
	head->left->val = NULL;
	head->left->left = NULL;
	head->left->right = NULL;
	head->left->color = black;

	head->right = new Tree; //������ ���� ������ 
	head->right->val = NULL;
	head->right->left = NULL;
	head->right->right = NULL;
	head->right->color = black;

	head->color = 0; //

	head->parent = NULL;
}

void add(int data) // ���������� ��������� 
{
	add_k++;
	Tree* kul = head;
	Tree* buff = NULL;
	while (kul->val != NULL) //���������� ��� � ��������� ������
	{
		buff = kul;
		if (data > buff->val)
		{
			kul = kul->right;
		}
		else
		{
			kul = kul->left;
		}
	}

	kul->val = data;

	kul->left = new Tree;  //����� ������ ����
	kul->left->val = NULL;
	kul->left->left = NULL;
	kul->left->right = NULL;
	kul->left->color = black;

	kul->right = new Tree;//������ ������ ����
	kul->right->val = NULL;
	kul->right->left = NULL;
	kul->right->right = NULL;
	kul->right->color = black;

	kul->color = red; // ���� �������

	kul->parent = buff;

	if (data < buff->val) // �������� �� ����� ����� �������� 
	{
		buff->left = kul;
	}
	else
	{
		buff->right = kul;
	}
	insert_case1(kul);
}

Tree* Ded(Tree* n) //�������� �� ������������� ��������� 2 ������ 
{
	if ((n != NULL) && (n->parent != NULL))
		return n->parent->parent;
	else
		return NULL;
}

Tree* uncle(Tree* n)
{
	Tree* g = Ded(n);
	if (g == NULL)
		return NULL;
	if (n->parent == g->left) //�������� �� 
		return g->right;
	else
		return g->left;
}

void insert_case1(Tree* n) // ���� ��� ������ ������� (head) �� ���� ������ 
{
	if (n->parent == NULL)
		n->color = black;
	else
		insert_case2(n);
}

void insert_case2(Tree* n)  //�������� �������� �� ����
{
	if (n->parent->color == black) //���� ������ ������������ � ��������� ��� ������� 
		return;
	else
		insert_case3(n);
}

void insert_case3(Tree* n) //�������� �� ��������� ����� �� ������� �� ����� 
{
	Tree* u = uncle(n), * g;
	if ((u != NULL) && (u->color == red)) {

		n->parent->color = black;
		u->color = black;
		g = Ded(n);
		g->color = red;
		insert_case1(g);
	}
	else {
		insert_case4(n);
	}
}

void insert_case4(Tree* n)
{
	Tree* g = Ded(n);

	if ((n == n->parent->right) && (n->parent == g->left)) {
		rotate_left(n->parent);
		n = n->left;
	}
	else if ((n == n->parent->left) && (n->parent == g->right)) {
		rotate_right(n->parent);
		n = n->right;
	}
	insert_case5(n);
}

void insert_case5(Tree* n)
{
	Tree* g = Ded(n);

	n->parent->color = black;
	g->color = red;
	if ((n == n->parent->left) && (n->parent == g->left)) {
		rotate_right(g);
	}
	else {
		rotate_left(g);
	}
}

void rotate_left(Tree* n)
{
	Tree* pivot = n->right;
	pivot->parent = n->parent;
	if (n->parent != NULL) {
		if (n->parent->left == n)
			n->parent->left = pivot;
		else
			n->parent->right = pivot;
	}

	n->right = pivot->left;
	if (pivot->left != NULL)
		pivot->left->parent = n;

	n->parent = pivot;
	pivot->left = n;
}

void rotate_right(Tree* n)
{
	Tree* pivot = n->left;

	pivot->parent = n->parent; /* ��� ����, ��������, pivot ���������� ������ ������ */
	if (n->parent != NULL) {
		if (n->parent->left == n)
			n->parent->left = pivot;
		else
			n->parent->right = pivot;
	}

	n->left = pivot->right;
	if (pivot->right != NULL)
		pivot->right->parent = n;

	n->parent = pivot;
	pivot->right = n;
}

char get_color(bool x)
{
	return (x == true ? 'r' : 'b');
}

void print_Tree(Tree* p, int level) //����� ������
{
	if (p)
	{
		print_Tree(p->left, level + 1);
		for (int i = 0; i < level; i++) cout << "   ";
		cout << p->val << get_color(p->color) << endl;
		print_Tree(p->right, level + 1);
	}
}

void output() // ����� ������
{
	Tree* temp = new Tree;
	temp = head;
	while (temp->parent != NULL) //���� head
		temp = temp->parent;
	print_Tree(temp, 0);
}