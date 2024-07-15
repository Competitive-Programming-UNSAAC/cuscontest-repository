#include <bits/stdc++.h>
using namespace std;

int main(){
  int te;
  cin >> te;
  while (te--) {
    int n;
    cin >> n;
    int gg = 0;
    while (n--) {
      int ci, di;
      cin >> ci >> di;
      gg += di / ci;
    }
    cout << gg << "\n";
  }
  return 0;
}