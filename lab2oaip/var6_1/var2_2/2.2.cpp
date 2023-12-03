//#include <stdio.h>
//#include <iostream>
//using namespace std;
//
//int main()
//{
//    int t, i;
//    errno_t err1, err2;
//    FILE* ff;
//    FILE* fout;
//    err1 = fopen_s(&ff,"file.txt", "w");
//    err2 = fopen_s(&fout,"file2.txt", "w");
//    while (!feof(ff))
//    {
//        for (i = 1; i <= 5; i++)
//        {
//            fscanf_s(ff, "%d", &t);
//            fprintf(fout, "%d\n", t);
//        }
//        for (i = 1; i <= 5; i++)
//        {
//            fscanf_s(ff, "%d", &t);
//        }
//        for (i = 1; i <= 5; i++)
//        {
//            fscanf_s(ff, "%d", &t);
//            fprintf(fout, "%d\n", t);
//        }
//        for (i = 1; i <= 5; i++)
//        {
//            fscanf_s(ff, "%d", &t);
//        }
//    }
//}
//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <stdio.h>
//using namespace std;
//
//int main()
//{
//
//	FILE* fileA, * fileB, * f, * g;
//
//	fileA = fopen("fileA.txt", "r");
//	fileB = fopen("fileB.txt", "w");
//	f = fopen("f.txt", "r");
//	g = fopen("g.txt", "w");
//	// Открытие файлов
//	char str[255];
//	//Задача #1
//	do
//	{
//		//Чтение данных из файла и конвертация из строки в число
//		fgets(str, 255, fileA);
//		int temp = atoi(str);
//
//		if (temp > 0) //Проверка условия задачи
//		{
//			char tempStr[255];
//			_itoa(temp, tempStr, 10); //Обратная конвертация в строку
//			fputs(tempStr, fileB); //Запись во второй файл
//		}
//	} while (str[0] != 'q');  //Проверка на ограничительный символ
//}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* file = fopen("in.txt", "r");
    if (file == NULL)
        fprintf(stderr, "Cannot open file");
    int size, i;
    fscanf(file, "%d", &size); //1-й элемент файла - количество элементов в массиве
    int* arr = (int*)malloc(size * sizeof(int));
    for (i = 0; i < size; ++i)
    {
        fscanf(file, "%d", &arr[i]);
    }
    fflush(file);
    fclose(file);

    file = fopen("in.txt", "w");
    if (file == NULL)
        fprintf(stderr, "Cannot write file");
    fprintf(file, "%d ", size);
    for (i = 0; i < size; ++i)
    {
        if (arr[i] > 0)
           // fprintf(file, "%d ", arr[i]);
            for (i = 1; i < size - 1; i = i + 2) {
                arr[i] = arr[i + 1];
                fprintf(file, "%d ", arr[i]);
            }
    }
    fclose(file);
    free(arr);
    return 0;
}//30 10 20 32 34 32 45 23 23 24 -13 -12 -54 -34 -34 -53 -43 -65 -43 -67 29 38 11 39 32 92 29 38 49 29