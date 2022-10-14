#include<bits/stdc++.h>
 
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
 
#define ALL(v) (v).begin(), (v).end()
#define fi first
#define se second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define ll long long
 
using namespace std;
 
bool minimize(int &x, const int &y){
    if(x > y){
        x = y;
        return true;
    } else return false;
}
 
bool maximize(int &x, const int &y){
    if(x < y){
        x = y;
        return true;
    } else return false;
}
 
#define NAME "a"
const int N = (int)1e4 + 5;
 
vector<int> adj[N];
int n;
int dist[N];
 
void init(){
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
 
int bfs(int src, bool type){
    memset(dist, -1, sizeof dist);
 
    dist[src] = 0;
    queue<int> q;
    q.push(src);
 
    while(!q.empty()){
        int u = q.front();
        q.pop();
 
        for(int v : adj[u]) if(dist[v] == -1){
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
 
    int maxDist = -1, idx;
    for(int i = 1; i <= n; i++)
        if(maximize(maxDist, dist[i])) idx = i;
 
    if(type) return idx;
    else return maxDist;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
//    freopen(NAME".inp", "r", stdin);
//    freopen(NAME".out", "w", stdout);
 
    init();
 
    cout << bfs(bfs(1, 1), 0);
    return 0;
}