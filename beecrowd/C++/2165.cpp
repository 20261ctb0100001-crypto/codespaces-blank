#include <iostream>
#include <string>
using namespace std;

int main() {
    string mensagem;
    getline(cin, mensagem);

    if (mensagem.size() <= 140)
        cout << "TWEET" << endl;
    else
        cout << "MUTE" << endl;

    return 0;
}
