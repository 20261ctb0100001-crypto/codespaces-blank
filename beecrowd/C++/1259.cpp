#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    int valores[10000];
    int pares[10000], impares[10000];
    int qtdPares = 0, qtdImpares = 0;

    for (int i = 0; i < N; i++) {
        cin >> valores[i];

        if (valores[i] % 2 == 0)
            pares[qtdPares++] = valores[i];
        else
            impares[qtdImpares++] = valores[i];
    }

    sort(pares, pares + qtdPares);
    sort(impares, impares + qtdImpares, greater<int>());

    for (int i = 0; i < qtdPares; i++)
        cout << pares[i] << endl;

    for (int i = 0; i < qtdImpares; i++)
        cout << impares[i] << endl;

    return 0;
}
