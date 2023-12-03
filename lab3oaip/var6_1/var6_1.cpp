/*1. Скопировать из файла FILE1 в файл FILE2 строки, начиная с N до K.
Подсчитать количество согласных букв в файле FILE2.*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char consBig[20] = { 'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Z' };
char consLil[20] = { 'b','c', 'd', 'f', 'g', 'h', 'j', 'k', 'l','m','n','p','q','r','s','t','v','w', 'x', 'z' };

int get_cons(char* ch, int size)
{
    int count = 0, countLet = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (ch[i] == consBig[j] || ch[i] == consLil[j])
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    setlocale(LC_ALL, "ru");
    ofstream fout;
    ifstream fin;
    string file1 = "file1.txt", file2 = "file2.txt";

    fin.open(file1);
    if (!fin.is_open())
    {
        cout << "Unable to open the file for reading ..";
    }

    int N, K;
    cout << "введите n и k ";
    cin >> N >> K;

    string str[20];
    int i = 1;
    while (!fin.eof())
    {
        getline(fin, str[i]);
        i++;
    }
    fin.close();

    fout.open(file2);
    if (!fout.is_open())
    {
        cout << "Unable to open the file for writing ..";
    }

    for (int i = N; i <= K; i++)
    {
        fout << str[i] << endl;
    }
    fout.close();

    fin.open(file2);
    int j = 0;
    char ch[150];
    while (fin.get(ch[j]))
    {
        j++;
    }

    /*for (int i = 0; i < j; i++)
    {
      cout << ch[i];
    }*/

    fin.close();

    cout << "\nколичество букв:  " << get_cons(ch, j) << endl;
}