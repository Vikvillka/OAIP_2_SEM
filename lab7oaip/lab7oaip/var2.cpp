#include "stack.h"

int main() {
    setlocale(LC_CTYPE, "Russian");
    Node* top = NULL;
    int choice, value;
    string filename;
    do {
        cout << "\n�������� ��������\n"
            << "==================\n"
            << "1. ��������\n"
            << "2. �������\n"
            << "3. ������� \n"
            << "4. ������� ������ ������������� \n"
            << "5. �������� ����\n"
            << "6. ��������� � ����\n"
            << "7. �������� �� �����\n"
            << "8. �����\n";
        cout << "���� ��������: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "������� �������: ";
            cin >> value;
            push(&top, value);
            break;
        case 2:
            value = pop(&top);
            if (value == -1) {
                cout << "������\n";
            }
            else {
                cout << "��������� ������� " << value << endl;
            }
            break;
        case 3:
            cout << "�����: ";
            display(top);
            break;
        case 4:
            deleteFirstNegative(&top);
            break;
        case 5:
            clearStack(&top);
            break;
        case 6:
            cout << "�������� �����: ";
            cin >> filename;
            saveToFile(top, filename);
            break;
        case 7:
            cout << "�������� �����: ";
            cin >> filename;
            readFromFile(top, filename, value);
            break;
        case 8:
            cout << "�������� ���������\n";
            break;
        default:
            cout << "������\n";
            break;
        }
    } while (choice != 8);
    return 0;
}

        
