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

const int N = 5005;
int n, m;
int dist[N]; ll way[N];
vector<pii> adj[N];

void dijsktra(){
    memset(dist, 0x3f, sizeof dist);
    memset(way, 0, sizeof way);

    dist[1] = 0; way[1] = 1;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.emplace(dist[1], 1);

    while(!pq.empty()){
        int u = pq.top().se;
        int du = pq.top().fi;
        pq.pop();
        if(du > dist[u]) continue;

        for(auto x : adj[u]){
            int v = x.fi, w = x.se;
            if(dist[v] == dist[u] + w) way[v] += way[u];
            else if(minimize(dist[v], dist[u] + w)){
                pq.emplace(dist[v], v);
                way[v] = way[u];
            }
        }
    }
}

void init(){
    cin >> n >> m;
    while(m--){
        int k, u, v, w;
        cin >> k >> u >> v >> w;
        adj[u].emplace_back(v, w);
        if(k == 2) adj[v].emplace_back(u, w);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    freopen(NAME".inp", "r", stdin);
//    freopen(NAME".out", "w", stdout);

    init();
    dijsktra();
    cout << dist[n] << ' ' << way[n];
    return 0;
}
