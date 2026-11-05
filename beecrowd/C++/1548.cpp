#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int M;
        cin >> M;

        int original[1000], ordenado[1000];

        for (int i = 0; i < M; i++) {
            cin >> original[i];
            ordenado[i] = original[i];
        }

        sort(ordenado, ordenado + M, greater<int>());

        int permaneceram = 0;
        for (int i = 0; i < M; i++) {
            if (original[i] == ordenado[i])
                permaneceram++;
        }

        cout << permaneceram << endl;
    }

    return 0;
}
