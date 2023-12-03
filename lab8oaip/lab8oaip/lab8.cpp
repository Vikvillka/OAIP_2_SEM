#include "Header.h"

int main() {
    setlocale(LC_ALL, "Russian");
    int maxSize;
    cout << "������� ������������ ������ �������: ";
    cin >> maxSize;

    queue<int> q;
    int choice;

    do {
        cout << "Menu:" << endl;
        cout << "1. �������� �������" << endl;
        cout << "2. ������� �������" << endl;
        cout << "3. ������� �������" << endl;
        cout << "4. ����� ������� ����� min � max" << endl;
        cout << "5. �����" << endl;
        cout << "��� �����: ";
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
            cout << "��������� ����� ����������� � �����������: " << findElementsBetweenMinMax(q) << endl;
            break;
        case 5:
            break;
        default:
            cout << "������" << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}
