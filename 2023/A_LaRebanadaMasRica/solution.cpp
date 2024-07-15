#include <bits/stdc++.h>
using namespace std;

int main(){
  int te;
  cin >> te;
  while (te--) {
    int n;
    cin >> n;
    int sum = n * (n + 1) / 2;
    for (int i = 0; i < n - 1; i++) {
      int x; cin >> x;
      sum -= x;
    }
    cout << sum << "\n";
  }
  return 0;
}