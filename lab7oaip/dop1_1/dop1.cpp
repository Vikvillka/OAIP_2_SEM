#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string a, b;
    cin >> a;

    int n = a.size();
    b.resize(n);

    stack<char> s;

    
    for (int i = 0; i < n / 2; i++) {
        s.push(a[i]);
    }


    for (int i = 0; i < n / 2; i++) {
        b[i] = s.top();
        s.pop();
    }

   
    for (int i = n / 2; i < n; i++) {
        s.push(a[i]);
    }

    
    for (int i = n / 2; i < n; i++) {
        b[i] = s.top();
        s.pop();
    }

    cout << b << endl;
    return 0;
}
