#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string frase;

    while (getline(cin, frase)) {
        bool maiuscula = true;

        for (char &letra : frase) {
            if (letra != ' ') {
                if (maiuscula)
                    letra = toupper(static_cast<unsigned char>(letra));
                else
                    letra = tolower(static_cast<unsigned char>(letra));

                maiuscula = !maiuscula;
            }
        }

        cout << frase << endl;
    }

    return 0;
}
