#include <bits/stdc++.h>
using namespace std;

int main(){
  int te; cin >> te;
  while (te--) {
    cin >> n;
    vector<int> a(n);
    for(auto &e: a) cin >> e;
    int gg = 0;
    for (int i = 0; i < n; ++i)
      int mini = a[i];
      for (int j = i; j < n; j++) {
        mini = min(mini, a[j]);
        gg = max(gg, mini * (j - i + 1));
      }
    cout << gg << "\n";
  }
  return 0;
}