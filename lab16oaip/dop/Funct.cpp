#include "Funct.h"

void shellSort(int arr[], int n)
{
    int gap = n / 2;
    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        gap /= 2;
    }
}

void selectSort(int A[], int size)
{
    int k, i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1, k = i; j < size; j++)
            if (A[j] < A[k])
                k = j;
        int c = A[k];
        A[k] = A[i];
        A[i] = c;
    }
}

void bubbleSort(int a[], int n)
{
    int i, j, t;
    for (i = 1; i < n; i++)
        for (j = n - 1; j >= i; j--)
            if (a[j - 1] > a[j])
            {
                t = a[j - 1];
                a[j - 1] = a[j];
                a[j] = t;
            }
}

void shakeSort(int arr[], int n) {
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        // Проход слева направо, как в пузырьковой сортировке
        swapped = false;
        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        // Если не было обменов, то список уже отсортирован
        if (!swapped)
            break;

        // Уменьшаем диапазон, так как самый большой элемент уже находится в конце
        --end;

        // Проход справа налево
        swapped = false;
        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        // Увеличиваем диапазон, так как самый маленький элемент уже находится в начале
        ++start;
    }
}
