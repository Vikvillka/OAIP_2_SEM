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
        cout << "Элемент не найден" << endl;
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
            cout << "Элемент найден" << endl;
            found = true;
            cout << data<<endl;
            break;
        }

        temp = temp->next;
    }

    if (!found) {
        cout << "Элемент не найден" << endl;
    }
}

void displayList() {
    if (head == nullptr) {
        cout << "Список пуст" << endl;
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
        cout << "Не удалось открыть файл" << endl;
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
        cout << "Не удалось открыть файл" << endl;
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
        cout << "Выберите действие:" << endl;
        cout << "1. Добавить элемент" << endl;
        cout << "2. Удалить элемент" << endl;
        cout << "3. Найти элемент" << endl;
        cout << "4. Вывести список" << endl;
        cout << "5. Записать список в файл" << endl;
        cout << "6. Считать список из файла" << endl;
        cout << "7. Найти среднее значение положительных элементов" << endl;
        cout << "8. Выход" << endl;
        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Введите значение: ";
            double data;
            cin >> data;

            addNode(data);
            break;
        }
        case 2: {
            cout << "Введите значение: ";
            double data;
            cin >> data;

            deleteNode(data);
            break;
        }
        case 3: {
            cout << "Введите значение: ";
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
            cout << "Введите имя файла: ";
            string fileName;
            cin >> fileName;

            saveListToFile(fileName);
            break;
        }
        case 6: {
            cout << "Введите имя файла: ";
            string fileName;
            cin >> fileName;

            loadListFromFile(fileName);
            break;
        }
        case 7: {
            double average = getAverageOfPositiveNodes();
            cout << "Среднее значение положительных элементов: " << average << endl;
            break;
        }
        case 8: {
            return 0;
        }
        default: {
            cout << "Некорректный выбор" << endl;
            break;
        }
        }
    }
}