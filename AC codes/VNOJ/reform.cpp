#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#define ll long long
#define pii pair<int,int>
#define ALL(x) x.begin(), x.end()
#define MASK(i) (1 << i)
#define BIT(x, i) ((x >> i) & 1)

using namespace std;
#define NAME "a"
const int N = (int)2e5 + 5;

bool maximize(int &x, int y){
    if(x < y){
        x = y; return true;
    } return false;
}
bool minimize(int &x, int y){
    if(x > y){
        x = y; return true;
    } return false;
}

int n, m;
vector<int> adj[N];
int numSCC = 0;
int low[N], disc[N], Time = 0;
int treeNode[N];

int cntNode = 0, cntEdge = 0, cntBridge = 0;
void dfs(int u, int p){
    treeNode[u] = 1;
    cntNode++; cntEdge += adj[u].size();
    low[u] = disc[u] = ++Time;

    for(int v : adj[u]) if(v != p){
        if(disc[v] == 0){
            dfs(v, u);
            treeNode[u] += treeNode[v];
            if(disc[u] < low[v]) cntBridge++;
            minimize(low[u], low[v]);
        }
        else minimize(low[u], disc[v]);
    }
}

void init(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    for(int i = 1; i <= n; i++) if(disc[i] == 0){
        numSCC++;
        dfs(i, -1);
    }
    memset(low, 0, sizeof low);
    memset(disc, 0, sizeof disc);
}

ll res2 = 0;
void dfs2(int u, int p){
    cntNode++; cntEdge += adj[u].size();
    low[u] = disc[u] = ++Time;

    for(int v : adj[u]) if(v != p){
        if(disc[v] == 0){
            dfs2(v, u);
            if(disc[u] < low[v]) res2 += 1LL*treeNode[v]*(n - treeNode[v]) - 1;
            minimize(low[u], low[v]);
        }
        else minimize(low[u], disc[v]);
    }
}

ll solve(){
    ll res = 0;
    if(numSCC == 1){
        dfs2(1, -1);
        res = res2 + 1LL*(m - cntBridge)*(1LL*n*(n-1)/2 - m);
    }
    else if(numSCC == 2){
        int node1 = 0, node2 = 0, br = 0, edge = 0;
        for(int i = 1; i <= n; i++) if(disc[i] == 0){
            cntNode = 0; cntBridge = 0; cntEdge = 0;
            cntEdge /= 2;

            dfs(i, -1);

            cntEdge /= 2;
            br += cntBridge;
            edge += cntEdge;
            node2 = cntNode;
        }
        node1 = n - node2;
        res = 1LL*node1*node2*(m  - br);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    freopen(NAME".inp", "r", stdin);
//    freopen(NAME".out", "w", stdout);

    init();
    cout << solve();
}
