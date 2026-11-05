#include <iostream>
using namespace std;

int main() {
    unsigned long long fib[61];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= 60; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        cout << "Fib(" << N << ") = " << fib[N] << endl;
    }

    return 0;
}
