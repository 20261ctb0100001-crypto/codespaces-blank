#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();

    while (N--) {
        string frase;
        getline(cin, frase);

        bool letras[26] = {false};
        int quantidade = 0;

        for (char c : frase) {
            if (isalpha(static_cast<unsigned char>(c))) {
                int indice = tolower(static_cast<unsigned char>(c)) - 'a';
                if (!letras[indice]) {
                    letras[indice] = true;
                    quantidade++;
                }
            }
        }

        if (quantidade == 26)
            cout << "frase completa" << endl;
        else if (quantidade >= 13)
            cout << "frase quase completa" << endl;
        else
            cout << "frase mal elaborada" << endl;
    }

    return 0;
}
