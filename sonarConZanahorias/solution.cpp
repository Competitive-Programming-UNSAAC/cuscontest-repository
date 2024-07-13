#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define db(a) cout << #a << " = " << a << endl;
#define db2(a, b) cout << #a << " = " << a << " " << #b << " = " << b << endl;
#define db3(a, b, c) cout << #a << " = " << a << " " << #b << " = " << b << " " << #c << " = " << c << endl;
#define list(a)                                                                         \
    cout << #a << endl;                                                                 \
    for (size_t i = 0; i < (a).size(); ++i) cout << "[" << i << "]:" << (a)[i] << endl; \
    cout << endl;

using namespace std;

int zanahoriasEntreZanahorias(int x1, int y1, int x2, int y2) {
    return __gcd(abs(x1 - x2), abs(y1 - y2)) - 1;
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
