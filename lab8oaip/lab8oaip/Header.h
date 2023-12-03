 #pragma once
#include <iostream>
#include <queue>

using namespace std;
void addElement(queue<int>& q, int maxSize);
void removeElement(queue<int>& q);
void printQueue(queue<int> q);
int findElementsBetweenMinMax(queue<int> q);