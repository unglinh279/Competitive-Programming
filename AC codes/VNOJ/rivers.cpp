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

bool minimize(ll &x, const ll &y){
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
const int N = 105;

int n, k;
int wNode[N], wEdge[N];
int sib[N], child[N];
ll dp[N][55][N];

void init(){
    memset(child, 0, sizeof child);
    memset(dp, -1, sizeof dp);
    memset(sib, 0, sizeof sib);

    cin >> n >> k;
    for(int u = 1; u <= n; u++){
        int wN, v, wE;
        cin >> wN >> v >> wE;
        sib[u] = child[v]; child[v] = u;
        wNode[u] = wN; wEdge[u] = wE;
    }
}

ll solve(int u, int l, int dist, int p){
    ll &res = dp[u][l][p];
    if(res != -1) return res;

    if(u == 0) return 0;

    res = INT_MAX;

    // choose u
    for(int i = 0; i < l; i++)
        minimize(res, solve(child[u], i, 0, u) + solve(sib[u], l-1-i, dist, p));

    // dont choose u
    for(int i = 0; i <= l; i++)
        minimize(res, solve(child[u], i, dist + wEdge[u], p) + solve(sib[u], l-i, dist, p) + (dist + wEdge[u])*wNode[u]);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    freopen(NAME".inp", "r", stdin);
//    freopen(NAME".out", "w", stdout);

    init();
    cout << solve(child[0], k, 0, 0);
    return 0;
}
