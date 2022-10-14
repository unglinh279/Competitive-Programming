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

const int N = 2222;
using namespace std;
int low[N], num[N], st[N], lab[N], in[N], out[N];
int n, m, cnt, scc, top;
bool was[N];
vector<int> a[N];

void DFS(int u) {
    low[u] = num[u] = ++cnt;
    st[++top] = u;
    int i, v;
    for(i=0; i<a[u].size(); i++) {
        v = a[u][i];
        if (was[v]) continue;
        if (num[v] != 0)
            low[u] = min(low[u], num[v]);
        else {
            DFS(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (num[u] == low[u]) {
        scc++;
        do {
            v = st[top--];
            lab[v] = scc;
            was[v] = true;
        } while (v != u);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    freopen(NAME".inp", "r", stdin);
//    freopen(NAME".out", "w", stdout);

    cin >> n >> m;
    int i, u, v, source = 0, sink = 0, s, t;
    for(i=1; i<=m; i++) {
        cin >> u >> v;
        a[u].push_back(v);
    }
    for(i=1; i<=n; i++)
    if (num[i] == 0)
        DFS(i);
    for(u=1; u<=n; u++)
    for(i=0; i<a[u].size(); i++) {
        v = a[u][i];
        if (lab[u] != lab[v]) {
            in[lab[v]]++;
            out[lab[u]]++;
        }
    }
    for(i=1; i<=scc; i++) {
        if (in[i] == 0) {
            source++; s = i;
        }
        if (out[i] == 0) {
            sink++; t = i;
        }
    }
    if (source != 1 || sink != 1) cout << "NO";
    else {
        cout << "YES\n";
        for(i=1; i<=n; i++) if (lab[i] == s) {s = i; break;}
        for(i=1; i<=n; i++) if (lab[i] == t) {t = i; break;}
        cout << t << ' ' << s;
    }
    return 0;
}
