#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    while (N--) {
        string palavra;
        cin >> palavra;

        if (palavra.size() == 5) {
            cout << 3 << endl;
        } else {
            string um = "one";
            int iguais = 0;

            for (int i = 0; i < 3; i++) {
                if (palavra[i] == um[i])
                    iguais++;
            }

            if (iguais >= 2)
                cout << 1 << endl;
            else
                cout << 2 << endl;
        }
    }

    return 0;
}
