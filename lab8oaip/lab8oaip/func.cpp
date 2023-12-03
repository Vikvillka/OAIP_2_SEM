#include "Header.h"

void addElement(queue<int>& q, int maxSize) {
    if (q.size() == maxSize) {
        cout << "Очередь полная" << endl;
    }
    else {
        int value;
        cout << "Введите элемент: ";
        cin >> value;
        q.push(value);
    }
}

void removeElement(queue<int>& q) {
    if (q.empty()) {
        cout << "Очередь пуста" << endl;
    }
    else {
        cout << "Удален элемент: " << q.front() << endl;
        q.pop();
    }
}

void printQueue(queue<int> q) {
    if (q.empty()) {
        cout << "Очередь пуста" << endl;
    }
    else {
        cout << "Очередь: ";
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
    }
}

int findElementsBetweenMinMax(queue<int> q) {
    if (q.empty()) {
        return 0;
    }

    int min = q.front();
    int max = q.front();
    queue<int> temp(q);
    int size = q.size();

    for (int i = 0; i < size; i++) {
        int value = temp.front();
        if (value < min) {
            min = value;
        }
        if (value > max) {
            max = value;
        }
        temp.pop();
    }

    temp = q;
    int count = 0;
    bool foundMin = false;
    bool foundMax = false;

    while (!temp.empty()) {
        int value = temp.front();
        temp.pop();
        if (value == min) {
            foundMin = true;
        }
        if (value == max) {
            foundMax = true;
        }
        if (foundMin && !foundMax) {
            count++;
        }
        if (foundMax && !foundMin) {
            count++;
        }
        if (foundMin && foundMax) {
            break;
        }
    }

    return count - 1;
}