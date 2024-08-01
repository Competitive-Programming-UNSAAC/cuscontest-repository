#include <cmath>
#include <iostream>
#include <numeric>

using namespace std;

int zanahoriasEntreZanahorias(int x1, int y1, int x2, int y2) {
    return std::gcd(abs(x1 - x2), abs(y1 - y2)) - 1;
}

int main() {
    int times, x1, y1, x2, y2;
    cin >> times;
    for (int i = 0; i < times; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << zanahoriasEntreZanahorias(x1, y1, x2, y2) << endl;
    }
    return 0;
}
