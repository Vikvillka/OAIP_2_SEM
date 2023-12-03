#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void push(Node** top, int value);

int pop(Node** top);

void display(Node* top);

void deleteFirstNegative(Node** top);

void clearStack(Node** top);

void saveToFile(Node* top, string filename);

void readFromFile(Node* top, string filename, int value);