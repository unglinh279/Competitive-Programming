#include<bits/stdc++.h>

//#pragma GCC target ("avx2")
//#pragma GCC optimize ("O3")
//#pragma GCC optimize ("unroll-loops")

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

const int N = (int)2e5 + 5;
int n, k;
vector<int> adj[N];
bool isLeaf[N], important[N];
int frDist[N], dist[N];
bool hasFr[N];

void init(){
    for(int i = 1; i <= n; i++) adj[i].clear();
    memset(frDist, 0x3f, sizeof frDist);
    memset(hasFr, 0, sizeof hasFr);
    memset(isLeaf, 0, sizeof isLeaf);
    memset(important, 0, sizeof important);

    cin >> n >> k;
    for(int i = 1; i <= k; i++){
        int u; cin >> u;
        hasFr[u] = true;
    }

    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
}

void dfs(int u, int p){
    if((int)adj[u].size() == 1) isLeaf[u] = true;

    dist[u] = dist[p] + 1;
    if(frDist[p] < INT_MAX) minimize(frDist[u], frDist[p] + 1);
    if(hasFr[u]) frDist[u] = 0;

    for(int v : adj[u]) if(v != p){
        dfs(v, u);
        minimize(frDist[u], frDist[v] + 1);
        if(isLeaf[v]) important[u] = true;
    }
}

bool solve(){
    if(hasFr[1]) return false;
    dist[0] = -1;
    dfs(1, 0);
    dfs(1, 0);

    if(important[1]){
        for(int v : adj[1])
            if(isLeaf[v] && !hasFr[v]) return true;
    }

    for(int u = 2; u <= n; u++) if(important[u])
        if(dist[u] < frDist[u]) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    freopen(NAME".inp", "r", stdin);
//    freopen(NAME".out", "w", stdout);

    int t; cin >> t;
    while(t--){
        init();
        if(solve()) cout << "yes";
        else cout << "no";
        cout << '\n';
    }
    return 0;
}
