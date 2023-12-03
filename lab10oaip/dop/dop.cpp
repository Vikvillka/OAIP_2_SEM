//#include <iostream>
//#include<tchar.h>
//#include<fstream>
//using namespace std;
//
//
//ofstream file1("file.txt");
//int arr[256];
//int A;
//void ch(int k) {
//	int i, j, t, p;
//	for (i = 0; i < A - k; i++)
//	{
//		if (k < A - 2)
//			ch(k + 1);
//		else {
//			for (p = 0; p < A; p++)
//				file1 << arr[p];
//			file1 << endl;
//		}
//		t = arr[k];
//		for (j = k + 1; j < A; j++)
//			arr[j - 1] = arr[j];
//		arr[j - 1] = t;
//	}
//
//}
//const int z = 5;
//int a[z];
//void perm(int k) {
//	int q, j, t, p;
//	for (q = 0; q < z - k; q++) {
//		if (k < z - 2)
//			perm(k + 1);
//		else {
//			for (p = 0; p < z; p++)
//				cout << " " << a[p];
//			cout << endl;
//		}
//		t = a[k];
//		for (j = k + 1; j < z; j++)
//			a[j - 1] = a[j];
//		a[j - 1] = t;
//	}
//}
//void dop1(int size, int* arr, int tmp)
//{
//
//	ofstream file("data.txt", ios_base::app);
//	for (int i = 0; i <= size; i++) {
//		arr[tmp] = i;
//		if (tmp == size - 1) {
//			for (int j = 0; j < size; j++)
//			{
//				cout << arr[j];
//				file << arr[j];
//			}
//			cout << " ";
//			file << " ";
//		}
//		else
//			dop1(size, arr, tmp + 1);
//	}
//}
//int counter = 0;
//int posled(int v, int counter, int r)
//{
//	while (counter != 10)
//	{
//		cout << v << " ";
//		return posled(v + r, counter + 1, r);
//	}
//
//}
//int ct = 1;
//int find(int ct, int v, int position, int r)
//{
//	while (ct != 26)
//	{
//		if (position == ct)
//		{
//			cout << std::endl;
//			cout << "Число на позиции n=" << v << std::endl;
//		}
//		return find(ct + 1, v + r, position, r);
//	}
//}
//int main() {
//
//	setlocale(LC_ALL, "Rus");
//	int choice;
//	for (;;)
//	{
//		cout << "Выберите команду:" << endl;
//		cout << "1 - 1 доп задание" << endl;
//		cout << "2 - 2 доп задание" << endl;
//		cout << "3 - 3 доп задание" << endl;
//		cout << "4 - Выход" << endl;
//		cin >> choice;
//		switch (choice)
//		{
//
//		case 1: {
//			cout << "Введите цифру:";
//			cin >> A;
//			cout << endl;
//			int i;
//			for (i = 0; i < A; i++)
//				arr[i] = i + 1;
//			ch(0);
//			file1.close();
//			cout << "Данные записаны в файл." << endl;
//		}
//			  break;
//		case 2: {
//			int q;
//			for (q = 0; q < z; q++)
//				a[q] = q + 1;
//			perm(0); }
//			  break;
//		case 3: {
//			int position, v, r;
//			cout << "Введите начальное значение последовательности:";
//			cin >> v;
//			cout << endl;
//			cout << "Введите число на которое будет изменяться последовательность:";
//			cin >> r;
//			cout << endl;
//			cout << "Введите n:";
//			cin >> position;
//			cout << endl;
//			cout << "Последовательность:";
//			posled(v, counter, r);
//			find(ct, v, position, r); }
//			  break;
//		case 4:
//			return 0;
//			break;
//		}
//	}
//}

//#include <iostream>
//#include <fstream>
//#include <string> 
//using namespace std;
//
//
//// ============================ ДОП 1 ============================
//
//void dop1(int size, int* arr, int tmp)
//{
//
//	ofstream file("data.txt", ios_base::app);
//	for (int i = 0; i <= size; i++) {
//		arr[tmp] = i;
//		if (tmp == size - 1) {
//			for (int j = 0; j < size; j++)
//			{
//				cout << arr[j];
//				file << arr[j];
//			}
//			cout << " ";
//			file << " ";
//		}
//		else
//			dop1(size, arr, tmp + 1);
//	}
//}
//
//// ============================  MAIN  ============================
//
//int main()
//{
//	setlocale(LC_ALL, "russian");
//	int A;
//	cout << "Dop 1:\nВведите A: ";
//	cin >> A;
//	int* arr = new int[A];
//	if (A == 1)
//	{
//		cout << 0 << " ";
//		cout << 1 << '\n';
//
//	}
//	else
//		for (int i = 1; i <= A; i++)
//		{
//			arr[0] = i;
//			dop1(A, arr, 1);
//		}
//
//}

#include <iostream>
#include <string>

using namespace std;
char simb;
int n, counter = -1;

char step(string str, int i) {
    counter++;
    while (i < 26 + n) {
        if (i - counter * size(str) < size(str)) {
            simb = str[i - counter * size(str)];
        }
        else {
            step(str, i);
        }
        i++;
    }
    cout << simb;
    exit(0);
}

int main() {
    setlocale(LC_ALL, "rus");
    string str;
    cout << "Введите строку ";
    getline(cin, str);
    cout << "Введите n ";
    int i = 0;
    cin >> n;

    step(str, i);

    return 0;
}