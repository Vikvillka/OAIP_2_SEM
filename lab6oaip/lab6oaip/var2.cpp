#include <iostream>
#include <fstream>

using namespace std;
struct Node {
    double data;
    Node* next;
};

Node* head = nullptr;

void addNode(double data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void deleteNode(double data) {
    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "������� �� ������" << endl;
    }
    else if (prev == nullptr) {
        head = temp->next;
        delete temp;
    }
    else {
        prev->next = temp->next;
        delete temp;
    }
}

void searchNode(double data) {
    Node* temp = head;
    bool found = false;

    while (temp != nullptr)
    {
        if (temp->data == data) {
            cout << "������� ������" << endl;
            found = true;
            cout << data<<endl;
            break;
        }

        temp = temp->next;
    }

    if (!found) {
        cout << "������� �� ������" << endl;
    }
}

void displayList() {
    if (head == nullptr) {
        cout << "������ ����" << endl;
    }
    else {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
}

void saveListToFile(string fileName) {
    ofstream outFile;
    outFile.open(fileName);

    if (outFile.is_open()) {
        Node* temp = head;

        while (temp != nullptr) {
            outFile << temp->data << " ";
            temp = temp->next;
        }

        outFile.close();
    }
    else {
        cout << "�� ������� ������� ����" << endl;
    }
}

void loadListFromFile(string fileName) {
    ifstream inFile;
    inFile.open(fileName);

    if (inFile.is_open()) {
        double data;

        while (inFile >> data) {
            addNode(data);
            cout << data << ' ';
        }
        cout << endl;
        inFile.close();
    }
    else {
        cout << "�� ������� ������� ����" << endl;
    }
}

double getAverageOfPositiveNodes() {
    double sum = 0.0;
    int count = 0;

    Node* temp = head;

    while (temp != nullptr) {
        if (temp->data > 0) {
            sum += temp->data;
            count++;
        }

        temp = temp->next;
    }

    if (count > 0) {
        return sum / count;
    }
    else {
        return 0;
    }
}

int main() {
    setlocale(LC_CTYPE, "Russian");
    while (true) {
        cout << "�������� ��������:" << endl;
        cout << "1. �������� �������" << endl;
        cout << "2. ������� �������" << endl;
        cout << "3. ����� �������" << endl;
        cout << "4. ������� ������" << endl;
        cout << "5. �������� ������ � ����" << endl;
        cout << "6. ������� ������ �� �����" << endl;
        cout << "7. ����� ������� �������� ������������� ���������" << endl;
        cout << "8. �����" << endl;
        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "������� ��������: ";
            double data;
            cin >> data;

            addNode(data);
            break;
        }
        case 2: {
            cout << "������� ��������: ";
            double data;
            cin >> data;

            deleteNode(data);
            break;
        }
        case 3: {
            cout << "������� ��������: ";
            double data;
            cin >> data;

            searchNode(data);
            break;
        }
        case 4: {
            displayList();
            break;
        }
        case 5: {
            cout << "������� ��� �����: ";
            string fileName;
            cin >> fileName;

            saveListToFile(fileName);
            break;
        }
        case 6: {
            cout << "������� ��� �����: ";
            string fileName;
            cin >> fileName;

            loadListFromFile(fileName);
            break;
        }
        case 7: {
            double average = getAverageOfPositiveNodes();
            cout << "������� �������� ������������� ���������: " << average << endl;
            break;
        }
        case 8: {
            return 0;
        }
        default: {
            cout << "������������ �����" << endl;
            break;
        }
        }
    }
}