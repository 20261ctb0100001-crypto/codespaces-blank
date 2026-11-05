#include <iostream>
using namespace std;

int main() {
    int p, j1, j2, r, a;
    cin >> p >> j1 >> j2 >> r >> a;

    int vencedor;

    if (r == 1 && a == 1) {
        vencedor = 2;
    } else if (r == 1 || a == 1) {
        vencedor = 1;
    } else {
        int soma = j1 + j2;
        if ((soma % 2 == 0 && p == 1) || (soma % 2 != 0 && p == 0))
            vencedor = 1;
        else
            vencedor = 2;
    }

    cout << "Jogador " << vencedor << " ganha." << endl;

    return 0;
}
