#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adyacentes(int x, int y){
  vector<pair<int, int>> gg;
  int cx = round(x / 3.0), cy = round(y / 3.0);
  int ax = cx + 1, ay = cy;
  if(x == 3 * cx - 1) ax = cx - 1;
  int bx = cx, by = cy + 1;
  if(y == 3 * cy - 1) by = cy - 1;
  // Mover el centro hacia la otra ubic.
  int mx = ax != cx ? ax:bx, my = ay != cy ? ay:by;
  gg.push_back({mx + ax + bx, my + ay + by});
  // Mover a hacia la ubic. 1/3
  mx = ax == cx - 1 ? (cx + 1):(cx - 1);
  my = ay;
  gg.push_back({mx + cx + bx, my + cy + by});
  // Mover a hacia la ubic. 2/3
  my = by;
  gg.push_back({mx + cx + bx, my + cy + by});
  // Mover a hacia la ubic. 3/3
  mx = ax;
  gg.push_back({mx + cx + bx, my + cy + by});
  // Mover b hacia la ubic. 1/3
  mx = bx;
  my = by == cy - 1 ? (cy + 1):(cy - 1);
  gg.push_back({mx + ax + cx, my + ay + cy});
  // Mover b hacia la ubic. 2/3
  mx = ax;
  gg.push_back({mx + ax + cx, my + ay + cy});
  // Mover b hacia la ubic. 3/3
  my = by;
  gg.push_back({mx + ax + cx, my + ay + cy});
  return gg;
}

int main(){
  int te; cin >> te;
  while (te--) {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int x = x1 + x2 + x3, y = y = y1 + y2 + y3;

    // BFS
    queue<pair<int, int>> q;
    q.push({1, 1});
    map<pair<int, int>, int> d;
    d[{1, 1}] = 0;
    while (q.size() > 0) {
      pair<int, int> p = q.front(); q.pop();
      int vx = p.first, vy = p.second;
      int dist = d[p];
      for (auto [ux, uy]: adyacentes(vx, vy)) {
        if(d.find({ux, uy}) == d.end() || dist + 1 < d[{ux, uy}]){
          d[{ux, uy}] = dist + 1;
          q.push({ux, uy});
        }
        // Objetivo localizado
        if(ux == x && uy == y){
          queue<pair<int, int>> empty;
          swap(q, empty);
          break;
        }
      }
    }
    cout << d[{x, y}] << "\n";
  }
  return 0;
}