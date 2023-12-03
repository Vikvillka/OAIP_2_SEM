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
    cout << "Введите значения m и n: ";
    cin >> m;
    cin >> n;
    int result = F(m, n);
    cout << "Значение функции F(" << m << ", " << n << ") равно " << result << endl;
   
    int a, b;
    cout << "Введите длину сторон a и b: ";
    cin >> a;
    cin >> b;
    int resultt = numsq(a, b);
    cout << "Количество квадратов: " << resultt << endl;
    return 0;
}