
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    
    ofstream outputFile("f1_2.txt");

   
    if (!outputFile.is_open())
    {
        cout << "Не удалось открыть файл для записи!" << endl;
        return 1;
    }

   
    cout << "Введите строку: ";
    string str;
    getline(cin, str);

    
    outputFile << str;

    
    outputFile.close();

    cout << "Строка успешно записана в файл text.txt" << endl;

    
    ifstream inputFile("f1_2.txt");

   
    if (!inputFile.is_open())
    {
        cout << "Не удалось открыть файл для чтения!" << endl;
        return 1;
    }

    
    string numStr;
    int num;
    for (char c : str)
    {
        if (c == ' ' || c=='\n' || c == '\r')
        {
           
            bool success = true;
            num = 0;
            for (char n : numStr)
            {
                if (n >= '0' && n <= '9')
                {
                    num = num * 10 + (n - '0');
                }
                else
                {
                    success = false;
                    break;
                }
            }
           
            if (success && num % 2 == 1)
            {
                cout << num << endl;
            }
            
            numStr = "";
        }
        else
        {
            numStr += c;
        }
    }

    
    inputFile.close();

    return 0;
}