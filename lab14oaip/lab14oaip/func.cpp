#include <iostream>
#include "Header.h"
int HashFunction(int key, int size, int p)
// ���-������� ��� ������� ������� ������������ ��� �������� �-�
// int key - �������� �����, int size - ������������ �-�� �-�, int p - �-�� ��������
// ������� ������������ ��� ������ � ��� �������, � ��� �������� ������������ ������� ������, � �������������, 

{
return ((int)(key % size + (key % size + 1) * p) % size);
}

// ��� ������� 
//int Next_hash(int key, int size, int p)// p - ������� ������� 
//{
//	return ((key % size + (key % size + 1) * p) % size);// ������ ���-������� �� �������
//}

//������� 1

int Next_hash(int key, int size, int p)
{
	int c1 = 1; // ����������� c1 ��� ������������ �������
	int c2 = 1; // ����������� c2 ��� ������������ �������

	int hash = key % size;
	int i = p;
	int step = (c1 * i + c2 * i * i) % size;

	return (hash + step) % size;
}

//������� 10

//int Next_hash(int key, int size, int p)
//{
//	int hash = key % size;
//	int step = p;
//
//	return (hash + step) % size;
//}

//������� 15

//int Next_hash(int key, int size, int p)
//{
//	int h1 = (key % size);
//	int h2 = 1 + (key % size);
//	int hash = (h1 + p * h2) % size;
//
//	return hash;
//}

int universal(int key, int size, int p)	// ������������ ����������� �����������: ��� ���������� ����� ����������� ��������� ��� � ����� ������ ���������
{
	int h = 0, a = 314445, b = 37542;
	h = (a * h + key) % size;
	return (h < 0) ? (h + size) : h;
}


Object Create(int size, int(*getkey)(void*)) // ������� �������� ���-������� 
 
	
{
return *(new Object(size, getkey));// ������ ����� ���-�������� � ���������� � 
// new - ������ ������� � 

// * - �������� 

// size- ������ ���-
// getkey - ������� ��� 

}

Object::Object(int size, int(*getkey)(void*))// ����������� ���-������
{
	N = 0;// ����� ������� ����� ���������, ������ ����
	// this - ��������� �� ������� ��������� (�.�. ���-�������)
	this->Size = size;// ����� ��������� ������������ ������ 
	this->GetKey = getkey;// ���������� ������� ��� ��������� ����� �� ��������
	this->Data = new void* [size];// ��������� ������ ��� ������ ��������� 
	for (int i = 0; i < size; ++i)// ������������� ��� ��������� ���� ��� ����������� �� �������
		Data[i] = NULL;
}

bool Object::Insert(void* d)// ������� ������� ��������� � ���-�������
{

	int key = GetKey(d);

	if (SearchInd(key) != -1) {
		// ������� � ����� ������ ��� ����������
		return false;
	}

	bool b = false;

	if (N != Size) // ���� ������� ���������� �� ����� ������� ���-������ (��� ���� ��������� �����)
	   // i - ������� �������, t - ���� ������������ ��������, ���������� �������� 
		
		// j - ������� ��� �������, ����������� �� ���-������� HashFunction
		for (int i = 0, t = GetKey(d), j = HashFunction(t, Size, 0); i != Size * Size && !b; j = Next_hash(j, Size,
			++i))

			// i != Size&&!b - ���� ������� ������� �� ��������� ������� ���-������� � ���� 
			
			// j = Next_hash(j, Size, ++i) - ��� �������� ����������� ������� � 
			
			if (Data[j] == NULL || Data[j] == DEL)
				// ���� ����������� ������� ���������� �������� ��� �������, ������� �� ��� 
				
			{
			Data[j] = d;
	// ���������� � ������������ ������� ����������� �-�, �� ���� ���������, 
	
	N++; // ����������� ������� �-��
	b = true;// ������� ������ �� �����, �� ���� �-� ��� ��������
			}
	return b;
}
//int Object::SearchInd(int key) // ������� ������ ������� �-� (���������) �� ����� � ���-�������
//{
//	int t = -1;// ����� ���������� �-�, ���� ������ �� �����, �� ���������� ������� -1
//	bool b = false;// ������� ������ �-� ��� ���
//	if (N != 0) // ���� � ������� ��� ���� �-��, �� ���� ������� �-�� �-�!=0 
//		for (int i = 0, j = HashFunction(key, Size, 0); Data[j] != NULL && i != Size * Size && !b; j =
//			HashFunction(key, Size, ++i))
//			// i - ������� �������, j - ������� ��� ������ �������� �-�, ����������� �� ���-
//
//			if (Data[j] != DEL) // ���� �� ������� ������� �� ����� �-�
//				if (GetKey(Data[j]) == key)
//					// ���������� ���� ��-�� �� ���. ������� � ������� ������
//				{
//					// ���� ��������� �����, �� ���������� ������� ��������� ��-�� 
//					t = j; // ����� ���������� ��-��
//					b = true; // -1 , ���� ��-� �� ������
//				}
//	return t; // �������. ������� ���������� ��-��
//}
int Object::SearchInd(int hash) {
	int t = -1; // ����� ���������� ��������
	bool b = false; // ������� ���������� ��������

	if (N != 0) {
		for (int i = 0; i < Size * Size && !b; ++i) {
			int j = HashFunction(hash, Size, i); // ��������� ������� �� ���-�������
			if (Data[j] != NULL && Data[j] != DEL) {
				int h = HashFunction(GetKey(Data[j]), Size, 0); // �������� ���-����� �������� ��������
				if (h == hash) {
					t = j; // ���������� ������� ���������� ��������
					b = true; // ������������� ���� ���������� ��������
				}
			}
		}
	}

	if (t >= 0) {
		std::cout << "������� � ���-������� " << hash << " ������ � ������� " << t << std::endl;
	}
	else {
		std::cout << "������� � ���-������� " << hash << " �� ������" << std::endl;
	}

	return t; // ���������� ������� ���������� �������� ��� -1, ���� ������� �� ������
}


void* Object::Search(int key) // ������� ������ �-�� �� �����
{
	int t = SearchInd(key);
	// �������� ������� ������ ������� �� ����� � ���������� � ��������� t ��� �������
	return (t >= 0) ? (Data[t]) : (NULL);
	// ���� ��-� ������ (t >= 0), ���������� ���������� � ��� ������, ����� �������. 0
}

void* Object::Delete(int key) // ������� �������� �� �����, ������� ���������� �-�� �� ������, �-�� �� ������� 

{
int i = SearchInd(key);
// �������� ������� ������ ������� �� ����� � ���������� � ��������� t ��� �������
void* t = Data[i]; // �-�� �� ������ � ������� ���-������� � ��������� ��������
if (t != NULL) // ���� ������ ����
{
Data[i] = DEL; // � �������� ������ �������� ��������� ���������� -1, �� ���� ����������, ��� �-

N--; // �������� ���-�� ������� �-�
}
return t;
}

bool Object::Delete(void* d) // ������� �������� �-� �� ������
{
	// 1. �������� ���� �� ���������� ������: (GetKey(d)
	// 2. ��������������� �������� �� ���������� �����
	// 3. ���������� ��������� ���������� ������ �������� � NULL��
	return (Delete(GetKey(d)) != NULL);
}

void Object::Scan(void(*f)(void*))
// ������� ������ ���-�������, ������� ��������� ������� ��� ������ ������ �-�
// � �� � ���� ������� ��������� � �������� ��������� �-�� �� ������������ ������
{
	for (int i = 0; i < this->Size; i++) // ���� ��� ������ ���-������� ���������
	{
		std::cout << " ������� " << i << ": ";
		if ((this->Data)[i] == NULL)
			std::cout << " �����" << std::endl;
		else if ((this->Data)[i] == DEL)

			std::cout << " ������" << std::endl;
		else f((this->Data)[i]);
	}
}