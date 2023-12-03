#include "stack.h"

void push(Node** top, int value) {
    Node* new_node = new Node;
    new_node->data = value;
    new_node->next = *top;
    *top = new_node;
}

int pop(Node** top) {
    int value = -1;
    if (*top != NULL) {
        Node* temp = *top;
        *top = (*top)->next;
        value = temp->data;
        delete temp;
    }
    return value;
}

void display(Node* top) {
    Node* temp = top;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteFirstNegative(Node** top) {
    Node* temp = *top;
    Node* prev = NULL;
    while (temp != NULL && temp->data >= 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "нет отрицательных\n";
    }
    else if (prev == NULL) {
        *top = temp->next;
        delete temp;
    }
    else {
        prev->next = temp->next;
        delete temp;
    }
}

void clearStack(Node** top) {
    Node* temp;
    while (*top != NULL) {
        temp = *top;
        *top = (*top)->next;
        delete temp;
    }
    cout << "стек чист\n";
}

void saveToFile(Node* top, string filename) {
    ofstream file;
    file.open(filename);
    Node* temp = top;
    while (temp != NULL) {
        file << temp->data << " ";
        temp = temp->next;
    }
    file.close();
    cout << "стек записан в файл " << filename << endl;
}

void readFromFile(Node* top, string filename, int value) {
    ifstream file;
    file.open(filename);
    if (!file) {
        cout << "File not found\n";
        return;
    }

    if (file.is_open()) {
        int data;

        while (file >> data) {
            push(&top, value);
            cout << data << ' ';
        }
        cout << endl;
        file.close();
    }
    else {
        cout << "Не удалось открыть файл" << endl;
    }
    file.close();
    
}