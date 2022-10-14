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
#define pii pair<int,int>
 
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
const int N = (int)1e5 + 5;
 
int root[N];
bool cut[N];
int numNode, numEdge;
vector<int> adj[N], tree[N];
 
int Time;
int low[N], timeIn[N], timeOut[N], depth[N];
 
void init(){
    cin >> numNode >> numEdge;
    for(int i = 0; i < numEdge; i++){
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
}
 
void dfs(int u, int p){
    int children = 0;
    low[u] = timeIn[u] = ++Time;
    for(int v : adj[u]) if(v != p){
        if(timeIn[v] == 0){
            tree[u].emplace_back(v);
            children++;
            depth[v] = depth[u] + 1;
            dfs(v, u);
            minimize(low[u], low[v]);
 
            if(u != 1 && low[v] >= timeIn[u]) cut[u] = true;
            if(u == 1 && children > 1) cut[u] = true;
        }
        else minimize(low[u], timeIn[v]);
    }
 
    timeOut[u] = Time;
}
 
bool isDesc(int u, int v){
    return timeIn[u] >= timeIn[v] && timeOut[u] <= timeOut[v];
}
 
bool compare(int i, int j){
    return timeIn[i] < timeIn[j];
}
 
int comp(int a, int u){
    if(isDesc(a, u)){
        int tmp = *(upper_bound(tree[u].begin(), tree[u].end(), a, compare)-1);
        if(low[tmp] >= timeIn[u]) return tmp;
    }
    return -1;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
//    freopen(NAME".inp", "r", stdin);
//    freopen(NAME".out", "w", stdout);
 
    init();
    dfs(1, -1);
    int q; cin >> q;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int a, b, u, v;
            cin >> a >> b >> u >> v;
            if(timeIn[u] < timeIn[v]) swap(u, v);
 
            if(low[u] <= timeIn[v] || (isDesc(a, u) == isDesc(b, u))) cout << "da";
            else cout << "ne";
        }
        else{
            int a, b, u;
            cin >> a >> b >> u;
            if(!cut[u]) cout << "da";
            else if(comp(a, u) == comp(b, u)) cout << "da";
            else cout << "ne";
        }
        cout << '\n';
    }
    return 0;
}