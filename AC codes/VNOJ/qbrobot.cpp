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

const int N = 505;
const int INF = (int)1e9;

struct e{
    int v, d, w;
    e(int _v = 0, int _d = 0, int _w = 0){
        v = _v; d = _d; w = _w;
    }
};

int n, m;
vector<e> adj[N];
int dist[N], dp[N];
int c[N][N];
bool isStation[N];
vector<int> save[N];
vector<int> topo;

void init(){
    memset(dp, 0x3f, sizeof dp);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> isStation[i];
    cin >> m;
    while(m--){
        int u, v, d, w;
        cin >> u >> v >> d >> w;
        c[u][v] = c[v][u] = w;
        adj[u].push_back(e(v, d, w));
        adj[v].push_back(e(u, d, w));
    }
}

void getTopo(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.emplace(dist[1], 1);

    while(!pq.empty()){
        int u = pq.top().se;
        int du = pq.top().fi;
        pq.pop();

        topo.emplace_back(u);

        for(auto x : adj[u]){
            if(dist[x.v] == du + x.d) save[x.v].push_back(u);
            else if(minimize(dist[x.v], dist[u] + x.d)){
                pq.emplace(dist[x.v], x.v);
                save[x.v] = vector<int>(1, u);
            }
        }
    }
}

bool check(int w){
    queue<pii> q;
    q.emplace(n, w);

    while(!q.empty()){
        int u = q.front().first;
        int e = q.front().second;
        q.pop();

        if(u == 1) return true;
        for(int v : save[u]){
            if(c[u][v] <= e)
                q.emplace(v, isStation[v] ? w : e - c[u][v]);
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    freopen(NAME".inp", "r", stdin);
//    freopen(NAME".out", "w", stdout);

    init();
    getTopo();

//    dp[1] = 0;

//    for(int u : topo)
//    for(auto x : adj[u]){
//        if(dist[x.v] == dist[u] + x.d){
//            if(isStation[u]) minimize(dp[x.v], max(dp[u], x.w));
//            else minimize(dp[x.v], dp[u] + x.w);
//        }
//
//    }

    int l = 0, r = INF;
    while(l < r){
        int m = (l+r)/2;
        if(check(m)) r = m;
        else l = m + 1;
    }

    cout << l;
    return 0;
}
