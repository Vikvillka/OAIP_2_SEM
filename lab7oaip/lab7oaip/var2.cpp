#include "stack.h"

int main() {
    setlocale(LC_CTYPE, "Russian");
    Node* top = NULL;
    int choice, value;
    string filename;
    do {
        cout << "\nВыберете действеи\n"
            << "==================\n"
            << "1. добавить\n"
            << "2. удалить\n"
            << "3. вывести \n"
            << "4. удалить первый отрицательный \n"
            << "5. очистить стек\n"
            << "6. сохранить в файл\n"
            << "7. прочесть из файла\n"
            << "8. выход\n";
        cout << "ваше действие: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "введите элемент: ";
            cin >> value;
            push(&top, value);
            break;
        case 2:
            value = pop(&top);
            if (value == -1) {
                cout << "ошибка\n";
            }
            else {
                cout << "удаленный элемент " << value << endl;
            }
            break;
        case 3:
            cout << "вывод: ";
            display(top);
            break;
        case 4:
            deleteFirstNegative(&top);
            break;
        case 5:
            clearStack(&top);
            break;
        case 6:
            cout << "название файла: ";
            cin >> filename;
            saveToFile(top, filename);
            break;
        case 7:
            cout << "название файла: ";
            cin >> filename;
            readFromFile(top, filename, value);
            break;
        case 8:
            cout << "закрытие программы\n";
            break;
        default:
            cout << "ошибка\n";
            break;
        }
    } while (choice != 8);
    return 0;
}

        
