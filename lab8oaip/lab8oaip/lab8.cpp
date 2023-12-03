#include "Header.h"

int main() {
    setlocale(LC_ALL, "Russian");
    int maxSize;
    cout << "¬ведите максимальный размер очереди: ";
    cin >> maxSize;

    queue<int> q;
    int choice;

    do {
        cout << "Menu:" << endl;
        cout << "1. добавить элемент" << endl;
        cout << "2. удалить элемент" << endl;
        cout << "3. вывести очередь" << endl;
        cout << "4. найти элемент между min и max" << endl;
        cout << "5. выход" << endl;
        cout << "¬аш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addElement(q, maxSize);
            break;
        case 2:
            removeElement(q);
            break;
        case 3:
            printQueue(q);
            break;
        case 4:
            cout << "Ёлементов между максималным и минимальным: " << findElementsBetweenMinMax(q) << endl;
            break;
        case 5:
            break;
        default:
            cout << "ошибка" << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}
