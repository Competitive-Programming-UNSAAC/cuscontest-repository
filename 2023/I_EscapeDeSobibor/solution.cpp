#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
  int te;
  cin >> te;
  while (te--) {
    ll n, x, y;
    cin >> n >> x >> y;
    n--;
    ll gg = n / x + n / y - n / (x * y);
    cout << gg << "\n";
  }
  return 0;
}