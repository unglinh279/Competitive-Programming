#include "bits/stdc++.h"
using namespace std;
 
const int N = 255;
 
vector<int> arr[N];
int parent[N], cap[N][N];
bool vs[N];
 
 
bool bfs(int s, int e){
	memset(vs, 0, sizeof(vs));
 
	queue<int> q;
	q.push(s);
	vs[s] = true;
	parent[s] = -1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
 
		for(int i = 0; i < arr[u].size(); i++){
			if(!vs[arr[u][i]] && cap[u][arr[u][i]] > 0){
				q.push(arr[u][i]);
				parent[arr[u][i]] = u;
				vs[arr[u][i]] = true;
			}
		}
	}
	return vs[e];
}
 
int mobivina(int s, int e){
	int max_flow = 0;
	while(bfs(s,e)){
		int path = INT_MAX;
 
		//min flow
		for(int v = e; v != s; v = parent[v]){
            int u = parent[v];
            path = min(path, cap[u][v]);
		}
 
		//update
		for(int v = e; v != s; v = parent[v]){
			int u = parent[v];
			cap[u][v] -= path;
			cap[v][u] += path;
		}
		max_flow += path;
	}
	return max_flow;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
//    freopen("a.inp", "r", stdin);
 
	int n; cin >> n;
 
	for(int i = 1; i <= n; i++){
		cin >> cap[1][i + 1];
		arr[1].push_back(i + 1);
	}
	for(int i = 1; i <= n; i++){
		cin >> cap[i + 1][n + 2];
		arr[i + 1].push_back(n + 2);
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> cap[i + 1][j + 1];
			arr[i + 1].push_back(j + 1);
		}
	}
 
	cout << mobivina(1, n + 2);
	return 0;
}