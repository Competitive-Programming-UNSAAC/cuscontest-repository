#include <bits/stdc++.h>
using namespace std;

int main(){
  int te; cin >> te;
  while (te--) {
    int na; cin >> na;
    vector<int> a(na);
    for(auto &e: a) cin >> e;
    int nb; cin >> nb;
    vector<int> b(nb);
    for(auto &e: b) cin >> e;
    int nc; cin >> nc;
    vector<int> c(nc);
    for(auto &e: c) cin >> e;
    na--; nb--; nc--;
    while(na + nb + nc > -3){
      if(na >= 0 && (nb < 0 || (nb >= 0 && a[na] < b[nb])) && (nc < 0 || (nc >= 0 && a[na] < c[nc]))){
        cout << a[na--];
      } else if (nb >= 0 && (na < 0 || (na >= 0 && b[nb] < a[na])) && (nc < 0 || (nc >= 0 && b[nb] < c[nc]))) {
        cout << b[nb--];
      } else{
        cout << c[nc--];
      }
    }
    cout << "\n";
  }
  return 0;
}