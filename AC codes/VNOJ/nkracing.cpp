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

struct DisjointSet{
    vector<int> cha, rnk;
    DisjointSet(int n): cha(n + 1), rnk(n + 1, 0){
        for (int i=1; i<=n; i++) cha[i] = i;
    }
    int look(int u){
        if (cha[u] != u) cha[u] = look(cha[u]);
        return cha[u];
    }
    bool join(int u, int v){
        u = look(u), v = look(v);
        if (u == v) return false;
        if (rnk[u] == rnk[v]) rnk[u]++;
        if (rnk[u] > rnk[v]) cha[v] = u;
        else cha[u] = v;
        return true;
    }
};

struct edge{
    int u, v, c;
};

bool operator > (edge a, edge b){
    return a.c > b.c;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    vector<edge> e(m);
    for (edge &e: e) cin >> e.u >> e.v >> e.c;

    DisjointSet f(n);
    int res = 0;
    sort(e.begin(), e.end(), greater<edge>());
    for(edge &e: e) if (!f.join(e.u, e.v)) res += e.c;
    cout << res;
    return 0;
}
