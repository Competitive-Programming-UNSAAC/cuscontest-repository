#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stdio.h>
#define MAX 505

using namespace std;

struct Edge{
	int u;
	int v;
	double w;
};

int parent[MAX];

void init(){
	for(int i = 0; i < MAX; i++) parent[i] = i;
}

int find(int x){
	if(x == parent[x]) return x;
	else return parent[x] = find(parent[x]);
}

void join(int x, int y){
	int X = find(x);
	int Y = find(y);
	parent[Y] = X;
}

bool isSame(int x, int y){
	if(find(x) == find(y)) return 1;
	else return 0;
}

bool order(Edge e1, Edge e2){
	return e1.A < e2.A;
}

double dist(double x1, double y1, double x2, double y2){
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

int main(){
	int T;
	cin>>T;

	while(T--){
		int C, A;
		cin>>C>>A;

		double X[A], Y[A];
		for(int i = 0; i < A; i++) cin>>X[i]>>Y[i];

		vector<Edge> graph;
		for(int i = 0; i < A; i++){
			for(int j = i + 1; j < A; j++){
				graph.push_back((Edge){i, j, dist(X[i], Y[i], X[j], Y[j])});
			}
		}

		sort(graph.begin(), graph.end(), order);

		init();

		int components = A;
		double ans = 0;
		
		for(int i = 0; i < graph.size(); i++){
			if(components == C + 1) break;
			else{
				if(!isSame(graph[i].u, graph[i].v)){
					join(graph[i].u, graph[i].v);
					ans = max(ans, graph[i].w);
					components--;
				}
			}
		}

		printf("%.2f\n", ans);
	}

	return 0;
}
