#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct  Node
{
	int key;
	string value;
	int count;
	Node* left;
	Node* right;
};

struct Tree
{
	Node* node = nullptr;
	int counter;
	void AddNode(int k);
	void PrintTree(Node* temp, int l);
	void Delete(int k);
	bool Balance(Node* temp);
	void DirectBypass(Node* temp);
	void ReverseBypass(Node* temp);
	void MyTask(Node* temp, int l);
	void DownScan(Node* temp);
	int check_right(Node* temp);
	int countRightLeaves(Node* temp);
};