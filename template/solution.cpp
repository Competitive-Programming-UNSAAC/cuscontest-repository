#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <set>
#define MAX 2048
#define MAX_LEV 12
using namespace std;

vector < vector < int > > G; // graph
pair < int,int > color[MAX];
int level[MAX];
bool visited[MAX]; // if vertex was visited
//
pair < int,int > tot_sum [MAX_LEV][MAX];
int ancestor[MAX_LEV][MAX];
pair < int ,int > tot_color[MAX_LEV][MAX];
// color to pair
pair < int,int > color_to_pair(char c){
	return ((c == 'R')? make_pair(1,0):make_pair(0,1));
}

// sum two pairs

pair < int, int > sum_pairs(pair < int, int > a, pair < int, int > b){
	return (make_pair(a.first + b.first,a.second + b.second));
}


// DFS
void make_DFS(int node,int pai = -1,int lev = 0){
	ancestor[0][node] = pai;
	visited[node] = true;
	level[node] = lev;
	for(int i = 0;i < G[node].size(); i++){
		if(G[node][i] == pai) continue;
		make_DFS(G[node][i],node,lev + 1);
	}
}

// build LCA

void build_LCA(int node){
	int i,j;
	int N = G.size();
	//we initialize every element in P with -1
   	for (i = 0; i < N; i++)
     		for (j = 0; (1 << j) < N; j++)
       			ancestor[j][i] = -1;
       			tot_color[j][i] = make_pair(0,0);
	//
	make_DFS(node);
	tot_color[0][node] = color[node];
	//
	for(int i = 0;i < G.size();i++){
		if(i == node) continue;
		tot_color[0][i] = sum_pairs(color[i],color[ancestor[0][i]]);
	}
	// now build the table of LCA and sums
	for (int j = 1; 1 << j < N; j++){
		for (int i = 0; i < N; i++){
			if (ancestor[j - 1][i] != -1){
		 		ancestor[j][i] = ancestor[j - 1][ancestor[j - 1][i]];
		 		//
		 		tot_color[j][i] = sum_pairs(tot_color[j - 1][i],tot_color[j - 1][ancestor[j - 1][i]]);
		 		tot_color[j][i].first -= color[ancestor[j - 1][i]].first;
		 		tot_color[j][i].second -= color[ancestor[j - 1][i]].second;
		 	}
		 }
	}
}

// get lca
int get_lca(int p, int q) {
  int N = G.size();
  int tmp, log, i;

  //if p is situated on a higher level than q then we swap them
  if (level[p] < level[q])
    tmp = p, p = q, q = tmp;

  //we compute the value of [log(level[p)]
  for (log = 1; 1 << log <= level[p]; log++);
  log--;

  //we find the ancestor of node p situated on the same level
  //with q using the values in P
  for (i = log; i >= 0; i--)
    if (level[p] - (1 << i) >= level[q])
      p = ancestor[i][p];

  if (p == q)
    return p;

  //we compute LCA(p, q) using the values in P
  for (i = log; i >= 0; i--)
    if (ancestor[i][p] != -1 && ancestor[i][p] != ancestor[i][q])
      p = ancestor[i][p], q = ancestor[i][p];

  return ancestor[0][p];
}

// get SUM

pair < int, int > get_sum(int node){
	int node_l = level[node];
	if(node_l == 0) return color[node];
	int bef = -1;
	pair < int, int > result = make_pair(0,0);
	while(node_l > 0){
		int r = __builtin_ctz(node_l);
		result = sum_pairs(result,tot_color[r][node]);
		node_l -= (1 << r);
		node_l--;
		if(ancestor[r][node] != -1){
			node = ancestor[0][ancestor[r][node]];
		}
	}
	return result;
}

// query
pair < int,int > query(int u,int v){
	if( u == v) return color[u];
	int lca = get_lca(u,v);
	pair < int, int> result = sum_pairs(get_sum(u),get_sum(v));
	pair < int,int > lca_sum = get_sum(lca);
	return (make_pair(result.first - 2*lca_sum.first + color[lca].first,result.second - 2*lca_sum.second + color[lca].second));
}
	

int main(){
	int n,q,u,v; string c;
	while(scanf("%d %d\n",&n,&q) != EOF){
		cin >> c;
		color[0] = color_to_pair(c[0]);
		for(int i = 1;i < n;i++){
			cin >> c;
			color[i] = color_to_pair(c[0]);
		}
		// read edges
		int num_edges = 0;
		G = vector < vector < int > > (n);
		for(int i = 0;i < n - 1;i++){
			scanf("%d %d\n",&u,&v);
			u--,v--;
			G[u].push_back(v);
			G[v].push_back(u);
			num_edges++;
		}
		// DFS and build lookup table
		build_LCA(0);
		// read and answer queries
		for(int i = 0;i < q;i++){
			scanf("%d %d\n",&u,&v);
			//printf("query: %d %d\n",u,v);
			u--,v--;
			pair < int, int > result = query(u,v);

			printf("%d %d\n",result.first,result.second);
		}
	}	
	return 0;
}
