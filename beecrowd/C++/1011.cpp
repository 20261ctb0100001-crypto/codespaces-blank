#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double R;
    cin >> R;

    double volume = (4.0 / 3.0) * 3.14159 * R * R * R;

    cout << fixed << setprecision(3);
    cout << "VOLUME = " << volume << endl;

    return 0;
}
