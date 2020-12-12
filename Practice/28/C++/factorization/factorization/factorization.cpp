#include <iostream>
using namespace std;
void print_factorization(unsigned int n) {
    int divisor = 2;
    while (divisor * divisor <= n)
    {
        if (n % divisor == 0)
        {
            cout << divisor;
            n = n / divisor;
            cout << '*';
        }
        else if (divisor == 2) divisor = 3;
        else divisor = divisor + 2;
    }
    cout << n;
}
int main() {
    int n;
    cin >> n;
    print_factorization(n);
    return 0;
}