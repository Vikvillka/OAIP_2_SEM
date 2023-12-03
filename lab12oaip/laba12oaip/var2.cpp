#include "Tree.h"
#include <fstream>
void main()
{
	int countChet = 0;
	setlocale(LC_ALL, "Russian");
	Tree* mainRoot = new Tree;
	int choice;


	while (1)
	{
		int numRight = 0;
		cout << "\n";
		cout << "1 - �������� �������;\n";
		cout << "2 - ������� ������;\n";
		cout << "3 - ������� �������;\n";
		cout << "4 - ������ ����� � �������;\n";
		cout << "5 - �������� ����� � �������;\n";
		cout << "6 - C�������� ����� � �������;\n";
		cout << "7 - ������������ ������;\n";
		cout << "8 - ���������� ������ �������;\n";
		cout << "0 - ����� �� ���������.\n";
		cout << "��������, ��� �������:\n";
		cin >> choice;
		cout << "\n";

		switch (choice)
		{
		case 1:
		{
			cout << "\n��� ��������� ������� ������������� �����." << endl;
			cout << "������� �������: "; cin >> choice;
			while (choice > 0)
			{
				mainRoot->AddNode(choice);
				cout << "������� �������: "; cin >> choice;
				if (choice % 2 == 0)
				{
					countChet++;
				}
			}
			break;
		}

		case 2:
		{
			if (!mainRoot->node) cout << "� ������ ������ ���.\n";
			else mainRoot->PrintTree(mainRoot->node, 0);
			break;
		}

		case 3:
		{
			int key;
			cout << "������� ���� ��������, ������� ������ �������: "; cin >> key;
			mainRoot->Delete(key);
			break;
		}

		case 4:
		{
			if (!mainRoot->node) cout << "� ������ ������ ���.\n";
			else mainRoot->DirectBypass(mainRoot->node);
			break;
		}

		case 5:
		{
			if (!mainRoot->node) cout << "� ������ ������ ���.\n";
			else mainRoot->DownScan(mainRoot->node);
			break;
		}

		case 6:
		{
			if (!mainRoot->node) cout << "� ������ ������ ���.\n";
			else mainRoot->ReverseBypass(mainRoot->node);
			break;
		}

		case 7:
		{
			mainRoot->counter = 0;
			if (!mainRoot->node) cout << "� ������ ������ ���.\n";
			else
				if (mainRoot->Balance(mainRoot->node))
					cout << "������ ��������������." << endl;
				else
					cout << "������ �� ��������������." << endl;
			break;
		}

		case 8:
		{
			cout << "\n���������� ������ �������: " << mainRoot->countRightLeaves(mainRoot->node) << endl;
			break;
		}

		case 0:
		{
			exit(0);
			break;
		}

		default:
		{
			cout << "������ ������ ���. �������� �����.\n";
			break;
		}

		}
	}
}