#include <iostream>
#include <chrono>
#include <iomanip> // Для std::fixed и std::setprecision
using namespace std;

// Функция сортировки выбором
void selectSort(int B[], int size)
{
    int k, i, j;
    for (i = 0; i < size - 1; i++)
    {
        // Находим индекс максимального элемента в неотсортированной части массива
        for (j = i + 1, k = i; j < size; j++)
            if (B[j] > B[k])
                k = j;
        // Обмен местами текущего элемента и максимального элемента
        int c = B[k];
        B[k] = B[i];
        B[i] = c;
    }
}

// Функция для получения границы разделения массива в сортировке Хоара
int getHoarBorder(int B[], int sm, int em)
{
    int i = sm - 1, j = em + 1;
    int brd = B[sm];
    int buf;
    while (i < j)
    {
        // Находим элементы, которые нужно поменять местами
        while (B[--j] < brd);
        while (B[++i] > brd);
        if (i < j)
        {
            // Обмен местами элементов
            buf = B[j];
            B[j] = B[i];
            B[i] = buf;
        };
    }
    return j; // Возвращаем индекс разделителя
}

// Функция быстрой сортировки Хоара
int* sortHoar(int B[], int sm, int em)
{
    if (sm < em)
    {
        int hb = getHoarBorder(B, sm, em);
        // Рекурсивно сортируем левую и правую части массива
        sortHoar(B, sm, hb);
        sortHoar(B, hb + 1, em);
    }
    return B; // Возвращаем отсортированный массив
}

int main() {
    setlocale(LC_ALL, "Rus");
    int size, i, j, sizeB = 0, ind = 0, ch = 3;
    int A[10000], B[10000];
    cout << "Количество элементов = ";
    cin >> size;
    cout << "Массив A: \n";
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

    cout << "\nМассив B: ";
    for (int i = 0; i < sizeB; i++)
    {
        cout << B[i] << " ";
    }

    cout << "\nКак сортировать? 1 - выбором, 2 - Хоар\n";
    cin >> ch;

    auto startTime = chrono::high_resolution_clock::now(); // Запуск таймера

    switch (ch) {
    case 1:
        selectSort(B, sizeB);
        break; // Сортировка выбором
    case 2:
        sortHoar(B, 0, sizeB - 1);
        break; // Быстрая сортировка Хоара
    }

    auto endTime = chrono::high_resolution_clock::now(); // Остановка таймера
    double duration = chrono::duration_cast<chrono::duration<double, std::milli>>(endTime - startTime).count(); // Разница времени в миллисекундах

    cout << "\nОтсортированный массив B: ";
    for (int i = 0; i < sizeB; i++)
    {
        cout << B[i] << " ";
    }

    cout << fixed << setprecision(2); // Устанавливаем формат вывода для времени
    cout << "\nВремя сортировки: " << duration << " миллисекунд" << endl;

    return 0;
}
