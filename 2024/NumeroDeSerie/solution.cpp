#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>
typedef long long ll;
#include <limits>
#include <memory>
#define db(a) cout << #a << " = " << a << endl;
#define db2(a, b) cout << #a << " = " << a << " " << #b << " = " << b << endl;
#define db3(a, b, c) cout << #a << " = " << a << " " << #b << " = " << b << " " << #c << " = " << c << endl;
#define list(a)                                                                         \
    cout << #a << endl;                                                                 \
    for (size_t i = 0; i < (a).size(); ++i) cout << "[" << i << "]:" << (a)[i] << endl; \
    cout << endl;

using namespace std;

int sum_digits(string a) {
    int n = a.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (isdigit(a[i])) sum += a[i] - '0';
    }
    return sum;
}
bool cmp(string a, string b) {
    if (a.size() < b.size())
        return true;
    if (a.size() > b.size())
        return false;
    if (sum_digits(a) < sum_digits(b)) {
        return true;
    }
    if (sum_digits(a) > sum_digits(b))
        return false;
    return a < b;
}

vector<string> sortSerials(vector<string> serialNumbers) {
    sort(serialNumbers.begin(), serialNumbers.end(), cmp);
    return serialNumbers;
}

int main() {
    size_t test_cases;
    size_t list_length;
    cin >> test_cases;
    while (test_cases--) {
        while (cin >> list_length) {
            auto list = vector<string>(list_length);
            for (auto& item : list) {
                cin >> item;
            }
            auto ans = sortSerials(list);
            for (size_t i = 0; i < ans.size() - 1; i++) {
                cout << ans[i] << " ";
            }
            cout << ans[ans.size() - 1] << endl;
        }
    }

    return 0;
}
