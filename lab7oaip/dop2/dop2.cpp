#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
    stack<int> lengths; 
    ifstream input("file.txt"); 

    string line;
    int shortest_length = 0;
    int shortest_line_number = 0;
    int line_number = 0;

    while (getline(input, line)) {
        int length = line.length();
        lengths.push(length); 

        if (shortest_length == 0 || length < shortest_length) {
            shortest_length = length;
            shortest_line_number = line_number;
        }

        line_number++;
    }

    input.close(); 

    
    while (!lengths.empty()) {
        cout << lengths.top() << endl;
        lengths.pop();
    }

    cout << "Самая короткая строка под номером " << shortest_line_number + 1 << ", с длиной " << shortest_length << endl;

    return 0;
}
