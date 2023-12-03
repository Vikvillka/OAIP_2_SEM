#include <iostream>
using namespace std;

int F(int m, int n) {
    if ((n + m) % 2 == 0) {
        return max(n, m);
    }
    else {
        int k = (n + m + 1) / 2;
        return F(k, n + 1) + F(m, k);
    }
}


int numsq(int a, int b) {
    if (b == 0) {
        return 0;
    }
    int squares = a / b;
    squares += numsq(b, a % b);
    return squares;
}


int main() { 
    setlocale(LC_CTYPE, "Rus");
    int m, n;
    cout << "������� �������� m � n: ";
    cin >> m;
    cin >> n;
    int result = F(m, n);
    cout << "�������� ������� F(" << m << ", " << n << ") ����� " << result << endl;
   
    int a, b;
    cout << "������� ����� ������ a � b: ";
    cin >> a;
    cin >> b;
    int resultt = numsq(a, b);
    cout << "���������� ���������: " << resultt << endl;
    return 0;
}