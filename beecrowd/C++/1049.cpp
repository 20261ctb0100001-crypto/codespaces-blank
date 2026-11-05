#include <iostream>
#include <string>
using namespace std;

int main() {
    string tipo, grupo, alimentacao;
    cin >> tipo >> grupo >> alimentacao;

    if (tipo == "vertebrado") {
        if (grupo == "ave") {
            if (alimentacao == "carnivoro") cout << "aguia" << endl;
            else cout << "pomba" << endl;
        } else {
            if (alimentacao == "onivoro") cout << "homem" << endl;
            else cout << "vaca" << endl;
        }
    } else {
        if (grupo == "inseto") {
            if (alimentacao == "hematofago") cout << "pulga" << endl;
            else cout << "lagarta" << endl;
        } else {
            if (alimentacao == "hematofago") cout << "sanguessuga" << endl;
            else cout << "minhoca" << endl;
        }
    }

    return 0;
}
