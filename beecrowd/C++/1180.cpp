#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int X[1000];
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }

    int menor = X[0];
    int posicao = 0;

    for (int i = 1; i < N; i++) {
        if (X[i] < menor) {
            menor = X[i];
            posicao = i;
        }
    }

    cout << "Menor valor: " << menor << endl;
    cout << "Posicao: " << posicao << endl;

    return 0;
}
