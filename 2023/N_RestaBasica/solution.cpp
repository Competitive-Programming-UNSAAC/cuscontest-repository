#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll oo = 1ll<<60ll;

int main(){
  #ifdef WozMit
  clock_t _start = clock();
  #endif
  int te; cin >> te;
  while (te--) {
    int n; cin >> n;
    vector<string> a(n);
    vector<int> c(n);
    for(auto &e: c) cin >> e;
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    int nn = 0;

    // Identificar todos los vtxs y los terminales
    map<pair<string, string>, int> track;
    vector<int> terminals;
    track[{"", ""}] = nn++;
    for (auto &p: a){
      for (int i = 0; i <= (int)p.size(); ++i){
        if(i > 0){
          string t = p.substr(0, i);
          track[{"", t}] = nn++;
          bool is_pal = true;
          for (int j = 0; is_pal && 2*j < (int)t.size(); j++)
            if(t[j] != t[t.size() - 1 - j]) is_pal = false;
          if(is_pal) terminals.push_back(nn - 1);
        }
        if(i < (int)p.size()){
          string t = p.substr(i);
          track[{t, ""}] = nn++;
          bool is_pal = true;
          for (int j = 0; is_pal && 2*j < (int)t.size(); j++)
            if(t[j] != t[t.size() - 1 - j]) is_pal = false;
          if(is_pal) terminals.push_back(nn - 1);
        }
      }
    }
  
    // Construir el grafo (aristas)
    vector<vector<pair<int, int>>> G(nn);
    for(auto [e, x]: track){
      string t = e.first, s = e.second;
      for (int i = 0; i < n; ++i) {
        bool poss_left = true;
        // Verificar si es posible poner a[i] a la izquierda
        int mini = min(a[i].size(), s.size());
        for (int j = 0; poss_left && j < mini; j++)
          if(a[i][j] != s[s.size() - 1 - j]) poss_left = false;
        if(t != "") poss_left = false;

        bool poss_right = true;
        // Verificar si es posible poner a[i] a la derecha
        mini = min(a[i].size(), t.size());
        for(int j = 0; poss_right && j < mini; j++)
          if(t[j] != a[i][a[i].size() - 1 - j]) poss_right = false;
        if(s != "") poss_right = false;

        if(poss_left){
          if(a[i].size() >= s.size()){
            // Sobra a la izquierda
            pair<string, string> w = {a[i].substr(s.size()), ""};
            int a = x, b = track[w];
            G[a].push_back({b, c[i]});
          } else{
            // Sobra a la derecha
            pair<string, string> w = {"", s.substr(0, s.size() - a[i].size())};
            int a = x, b = track[w];
            G[a].push_back({b, c[i]});
          }
        }
        if(poss_right){
          if(a[i].size() >= t.size()){
            // Sobra a la derecha
            pair<string, string> w = {"", a[i].substr(0, a[i].size() - t.size())};
            int a = x, b = track[w];
            G[a].push_back({b, c[i]});
          } else {
            // Sobra a la izquierda
            pair<string, string> w = {t.substr(a[i].size()), ""};
            int a = x, b = track[w];
            G[a].push_back({b, c[i]});
	  }
	}
      }
    }

    // Ejecutar el algoritmo de Dijkstra's desde 0
    vector<ll> d(nn, oo);
    d[0] = 0;
    priority_queue<pair<ll, int>> q;
    q.push({0, 0});
    while ((int)q.size() > 0) {
      int v = q.top().second;
      ll dv = -q.top().first;
      q.pop();
      // Evitar repetir estados innecesarios
      if(dv != d[v]) continue;
      for(auto edge: G[v]){
        int u = edge.first, w = edge.second;
        if(d[v] + (ll)w < d[u]){
          d[u] = d[v] + (ll)w;
          q.push({-d[u], u});
        }
      }
      // Ya salimos de 0, ya podemos ponerlo en su lugar
      if(v == 0 && d[0] == 0) d[0] = oo;
    }

    ll gg = d[0];
    for (auto e: terminals)
      if(d[e] < gg)
        gg = d[e];
    if(gg == oo) cout << "Imposible\n";
    else cout << gg << "\n";
  }
  return 0;
}