#include <iostream>
#include <chrono>
#include <iomanip> // ��� std::fixed � std::setprecision
using namespace std;

// ������� ���������� �������
void selectSort(int B[], int size)
{
    int k, i, j;
    for (i = 0; i < size - 1; i++)
    {
        // ������� ������ ������������� �������� � ����������������� ����� �������
        for (j = i + 1, k = i; j < size; j++)
            if (B[j] > B[k])
                k = j;
        // ����� ������� �������� �������� � ������������� ��������
        int c = B[k];
        B[k] = B[i];
        B[i] = c;
    }
}

// ������� ��� ��������� ������� ���������� ������� � ���������� �����
int getHoarBorder(int B[], int sm, int em)
{
    int i = sm - 1, j = em + 1;
    int brd = B[sm];
    int buf;
    while (i < j)
    {
        // ������� ��������, ������� ����� �������� �������
        while (B[--j] < brd);
        while (B[++i] > brd);
        if (i < j)
        {
            // ����� ������� ���������
            buf = B[j];
            B[j] = B[i];
            B[i] = buf;
        };
    }
    return j; // ���������� ������ �����������
}

// ������� ������� ���������� �����
int* sortHoar(int B[], int sm, int em)
{
    if (sm < em)
    {
        int hb = getHoarBorder(B, sm, em);
        // ���������� ��������� ����� � ������ ����� �������
        sortHoar(B, sm, hb);
        sortHoar(B, hb + 1, em);
    }
    return B; // ���������� ��������������� ������
}

int main() {
    setlocale(LC_ALL, "Rus");
    int size, i, j, sizeB = 0, ind = 0, ch = 3;
    int A[10000], B[10000];
    cout << "���������� ��������� = ";
    cin >> size;
    cout << "������ A: \n";
    for (i = 0; i < size; i++)
    {
        A[i] = rand() % 100;
        cout << A[i] << " ";
        if (i % 10 == 0 && i > 0) cout << "\n";
    }

    for (i = 0; i < size; i++)
    {
        j = i + 1;
        if (i % 2 == 0 && A[j] % 2 != 0) {
            B[ind] = A[i];
            sizeB++;
            ind++;
        }
    }

    cout << "\n������ B: ";
    for (int i = 0; i < sizeB; i++)
    {
        cout << B[i] << " ";
    }

    cout << "\n��� �����������? 1 - �������, 2 - ����\n";
    cin >> ch;

    auto startTime = chrono::high_resolution_clock::now(); // ������ �������

    switch (ch) {
    case 1:
        selectSort(B, sizeB);
        break; // ���������� �������
    case 2:
        sortHoar(B, 0, sizeB - 1);
        break; // ������� ���������� �����
    }

    auto endTime = chrono::high_resolution_clock::now(); // ��������� �������
    double duration = chrono::duration_cast<chrono::duration<double, std::milli>>(endTime - startTime).count(); // ������� ������� � �������������

    cout << "\n��������������� ������ B: ";
    for (int i = 0; i < sizeB; i++)
    {
        cout << B[i] << " ";
    }

    cout << fixed << setprecision(2); // ������������� ������ ������ ��� �������
    cout << "\n����� ����������: " << duration << " �����������" << endl;

    return 0;
}
