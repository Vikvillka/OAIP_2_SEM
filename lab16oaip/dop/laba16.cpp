#include "Funct.h"

void main_var(int A[], int size)
{
    int* B = new int[size];

    cout << "Array A:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << ' ';
    }
    cout << endl;

    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (A[i] % 2 == 0)
        {
            B[j] = A[i];
            j++;
        }
    }
    cout << endl << "Array B:" << endl;

    for (int i = 0; i < j; i++)
    {
        cout << B[i] << ' ';
    }
    cout << endl << "Sorted array:" << endl;

    auto start = chrono::steady_clock::now();
    shellSort(B, j);
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    for (int i = 0; i < j; i++)
    {
        cout << B[i] << ' ';
    }
    cout << endl;
    cout << "Time shell: " << chrono::duration <double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    selectSort(B, j);
    end = chrono::steady_clock::now();
    diff = end - start;
    for (int i = 0; i < j; i++)
    {
        cout << B[i] << ' ';
    }
    cout << endl;
    cout << "Time selection: " << chrono::duration <double, milli>(diff).count() << " ms" << endl;
}

void firstAdd(int A[], int size)//12 var
{
    int* B = new int[size / 2 + 1];

    cout << "Array A:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << ' ';
    }
    cout << endl;

    int j = 0;
    for (int i = 0; i < size; i += 2)
    {
        B[j] = A[i];
        j++;
    }
    cout << endl << "Array B:" << endl;

    for (int i = 0; i < j; i++)
    {
        cout << B[i] << ' ';
    }
    cout << endl << "Sorted array:" << endl;

    auto start = chrono::steady_clock::now();
    bubbleSort(B, j);
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    for (int i = 0; i < j; i++)
    {
        cout << B[i] << ' ';
    }
    cout << endl;
    cout << "Time bubble: " << chrono::duration <double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    selectSort(B, j);
    end = chrono::steady_clock::now();
    diff = end - start;
    for (int i = 0; i < j; i++)
    {
        cout << B[i] << ' ';
    }
    cout << endl;
    cout << "Time selection: " << chrono::duration <double, milli>(diff).count() << " ms" << endl;
}

void secondAdd(int A[], int size)//9 var
{
    int* B = new int[size / 2 + 1];

    cout << "Array A:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << ' ';
    }
    cout << endl;

    int j = 0;
    for (int i = 1; i < size; i += 2)
    {
        if (A[i + 1] % 2 != 0)
        {
            B[j] = A[i];
            j++;
        }
    }
    cout << endl << "Array B:" << endl;

    for (int i = 0; i < j; i++)
    {
        cout << B[i] << ' ';
    }
    cout << endl << "Sorted array:" << endl;

    auto start = chrono::steady_clock::now();
    bubbleSort(B, j);
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    for (int i = 0; i < j; i++)
    {
        cout << B[i] << ' ';
    }
    cout << endl;
    cout << "Time bubble: " << chrono::duration <double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    shakeSort(B, j);
    end = chrono::steady_clock::now();
    diff = end - start;
    for (int i = 0; i < j; i++)
    {
        cout << B[i] << ' ';
    }
    cout << endl;
    cout << "Time shake: " << chrono::duration <double, milli>(diff).count() << " ms" << endl;
}

void thirdAdd(int A[], int size)//5 var
{
    int* B = new int[size];
    int* C = new int[size * 2];

    cout << "Array A:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << ' ';
    }
    cout << endl;

    int j = 0;
    cout << "Array B: " << endl;
    for (int i = 0; i < size; i++)
    {
        B[i] = rand() % 20;
        cout << B[i] << " ";
        if (A[i] % 2 == 0)
        {
            C[j] = A[i];
            j++;
        }
        if (B[i] % 2 != 0)
        {
            C[j] = B[i];
            j++;
        }
    }
    cout << endl << "Array C:" << endl;

    for (int i = 0; i < j; i++)
    {
        cout << C[i] << ' ';
    }
    cout << endl << "Sorted array:" << endl;

    auto start = chrono::steady_clock::now();
    bubbleSort(C, j);
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    for (int i = 0; i < j; i++)
    {
        cout << C[i] << ' ';
    }
    cout << endl;
    cout << "Time bubble: " << chrono::duration <double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    selectSort(C, j);
    end = chrono::steady_clock::now();
    diff = end - start;
    for (int i = 0; i < j; i++)
    {
        cout << C[i] << ' ';
    }
    cout << endl;
    cout << "Time selection: " << chrono::duration <double, milli>(diff).count() << " ms" << endl;
}


int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    int size;
    cout << "Size: ";
    cin >> size;

    int* A = new int[size];

    for (int i = 0; i < size; i++)
    {
        A[i] = rand() % 20;

    }

    int choise;
    while (true)
    {
        cout << "\n1 - 5 вариант\n2 - 9 вариант\n3 - 12 вариант\n0 - exit\n";
        cin >> choise;
        system("cls");
        switch (choise)
        {
        case 5:
            main_var(A, size);
            system("pause");
            system("cls");
            break;
        case 1:
           thirdAdd(A, size);
            system("pause");
            system("cls");
            break;
        case 2:
            secondAdd(A, size);
            system("pause");
            system("cls");
            break;
        case 3:
       firstAdd(A, size);
            system("pause");
            system("cls");
            
            break;
        case 0:
            exit(0);
        default:
            cout << "Uncorrect choise\n";
            break;
        }
    }
}