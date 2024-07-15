#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n; cin >> n;
    stack<int> S[n];
    for (int i = 0; i < n; i++){
      int ss; cin >> ss;
      for (int j = 0; i < ss; j++){
        int a; cin >> a;
        S[i].push(a);
      }
    }
    priority_queue<pair<int,int>> Q;
    for (int i = 0; i < n; i++)
      Q.push({-S[i].top(), i});
    while (!Q.empty()) {
      pair<int, int> curr = Q.top();
      Q.pop();
      cout << -curr.first;
      S[curr.second].pop();
      if(!S[curr.second].empty())
        Q.push({-S[curr.second].top(), curr.second});
    }
    cout << "\n";
  }
  return 0;
}