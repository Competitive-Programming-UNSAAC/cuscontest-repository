#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
typedef long long int ll;

int main(){
  int te; cin >> te;
  while (te--) {
    string x, y; cin >> x >> y;
    int n = x.size();
    for (int i = 0; i < n; ++i)
      if(x[i] < y[i]) swap(x[i], y[i]);
    ll xx = 0, yy = 0;
    for (int i = 0; i < n; ++i) {
      xx = (xx * 10 + x[i] - '0') % mod;
      yy = (yy * 10 + y[i] - '0') % mod;
    }
    cout << (xx * yy) % mod << "\n";
  }
  return 0;
}