#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int N;

    while (cin >> N) {
        vector<string> codigos(N);

        for (int i = 0; i < N; i++) {
            cin >> codigos[i];
        }

        sort(codigos.begin(), codigos.end());

        for (const string &codigo : codigos) {
            cout << codigo << endl;
        }
    }

    return 0;
}
