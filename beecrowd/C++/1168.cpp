#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    int leds[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    for (int i = 0; i < N; i++) {
        string numero;
        cin >> numero;

        int total = 0;
        for (char digito : numero) {
            total += leds[digito - '0'];
        }

        cout << total << " leds" << endl;
    }

    return 0;
}
