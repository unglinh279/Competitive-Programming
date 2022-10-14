#include<bits/stdc++.h>
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
const int N = 1005;
int n, m, s, t;

int graph[N][N];
int flow[N][N];

bool vs[N];
int par[N];

bool bfs(int s, int t){
    memset(vs, 0, sizeof vs);

    queue<int> q;
    q.emplace(s);
    vs[s] = true;
    par[s] = -1;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v = 1; v <= n; v++) if(!vs[v] && graph[u][v] > 0){
            if(v == t){
                par[v] = u;
                return true;
            }

            q.emplace(v);
            vs[v] = true;
            par[v] = u;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    freopen(NAME".inp", "r", stdin);
//    freopen(NAME".out", "w", stdout);

    cin >> n >> m >> s >> t;
    for(int i = 1; i <= m; i++){
        int u, v, c; cin >> u >> v >> c;
        graph[u][v] = c;
    }

    int maxFlow = 0;
    while(bfs(s, t)){
        int pathFlow = INT_MAX;

        int u, v;
        for(v = t; v != s; v = par[v]){
            u = par[v];
            minimize(pathFlow, graph[u][v]);
        }

        for(int v = t; v != s; v = par[v]){
            u = par[v];
            graph[u][v] -= pathFlow;
            graph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    cout << maxFlow;

    return 0;
}
