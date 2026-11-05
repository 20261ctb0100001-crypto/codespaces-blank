#include <iostream>
using namespace std;

int main() {
    int pares[5], impares[5];
    int qtdPares = 0, qtdImpares = 0;

    for (int i = 0; i < 15; i++) {
        int valor;
        cin >> valor;

        if (valor % 2 == 0) {
            pares[qtdPares++] = valor;
            if (qtdPares == 5) {
                for (int j = 0; j < 5; j++)
                    cout << "par[" << j << "] = " << pares[j] << endl;
                qtdPares = 0;
            }
        } else {
            impares[qtdImpares++] = valor;
            if (qtdImpares == 5) {
                for (int j = 0; j < 5; j++)
                    cout << "impar[" << j << "] = " << impares[j] << endl;
                qtdImpares = 0;
            }
        }
    }

    for (int i = 0; i < qtdImpares; i++)
        cout << "impar[" << i << "] = " << impares[i] << endl;

    for (int i = 0; i < qtdPares; i++)
        cout << "par[" << i << "] = " << pares[i] << endl;

    return 0;
}
