#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#define ll long long
#define pii pair<int,int>
#define ALL(x) x.begin(), x.end()
#define MASK(i) (1 << i)
#define BIT(x, i) ((x >> i) & 1)

using namespace std;
#define NAME "a"
const int N = (int)1e5 + 5;

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

int n, res = INT_MAX;
set<int> adj[N];
vector<int> X, Y;

struct Data{
    int cord, type, idx;
    bool operator < (const Data& rhs) const{
        return cord < rhs.cord || (cord == rhs.cord && type < rhs.type);
    }
};

vector<Data> saveX[2*N], saveY[2*N];

struct Rectangle{
    int x, y, u, v;
} rect[N];

void init(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int tlX, tlY, brX, brY;
        cin >> tlX >> brY >> brX >> tlY;
        assert(tlX < brX); assert(tlY < brY);

        X.emplace_back(tlX); X.emplace_back(brX);
        Y.emplace_back(tlY); Y.emplace_back(brY);

        rect[i] = {tlX, tlY, brX, brY};
    }

    //compress
    sort(ALL(X)); sort(ALL(Y));
    X.resize(unique(ALL(X)) - X.begin());
    Y.resize(unique(ALL(Y)) - Y.begin());

    for(int i = 1; i <= n; i++){
        rect[i].x = lower_bound(ALL(X), rect[i].x) - X.begin();
        rect[i].u = lower_bound(ALL(X), rect[i].u) - X.begin();
        rect[i].y = lower_bound(ALL(Y), rect[i].y) - Y.begin();
        rect[i].v = lower_bound(ALL(Y), rect[i].v) - Y.begin();

        saveY[rect[i].y].push_back({rect[i].x, -1, i});
        saveY[rect[i].y].push_back({rect[i].u, 1, i});
        saveY[rect[i].v].push_back({rect[i].x, -1, i});
        saveY[rect[i].v].push_back({rect[i].u, 1, i});

        saveX[rect[i].x].push_back({rect[i].y, -1, i});
        saveX[rect[i].x].push_back({rect[i].v, 1, i});
        saveX[rect[i].u].push_back({rect[i].y, -1, i});
        saveX[rect[i].u].push_back({rect[i].v, 1, i});
    }

    vector<pii> E;

    for(int i = 0; i < (int)X.size(); i++){
        set<int> mySet;
        sort(ALL(saveX[i]));
        for(auto &cur : saveX[i]){
            if(cur.type == 1) mySet.erase(cur.idx);
            else{
                for(int idx : mySet) E.emplace_back(min(idx, cur.idx), max(idx, cur.idx));
                mySet.insert(cur.idx);
            }
        }
    }

     for(int i = 0; i < (int)Y.size(); i++){
        set<int> mySet;
        sort(ALL(saveY[i]));
        for(auto &cur : saveY[i]){
            if(cur.type == 1) mySet.erase(cur.idx);
            else{
                for(int idx : mySet) E.emplace_back(min(idx, cur.idx), max(idx, cur.idx));
                mySet.insert(cur.idx);
            }
        }
    }

    sort(ALL(E));
    E.resize(unique(ALL(E)) - E.begin());
    for(auto x : E){
        int u = x.first, v = x.second;
        adj[u].insert(v); adj[v].insert(u);
    }
}

int num[N], low[N], Time, nChild[N];
vector<int> br;

void dfs(int u, int p = -1){
    num[u] = low[u] = ++Time;
    nChild[u] = 1;
    for(int v : adj[u]) if(v != p){
        if(num[v] == 0){
            dfs(v, u);
            nChild[u] += nChild[v];
            minimize(low[u], low[v]);

            if(num[u] < low[v]) br.push_back(v);
        }
        else minimize(low[u], num[v]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    freopen(NAME".inp", "r", stdin);
//    freopen(NAME".out", "w", stdout);

    init();
    int res = INT_MAX;
    for(int i = 1; i <= n; i++){
        if(num[i] == 0){
            br.clear();
            dfs(i);
            for(int v : br)
                minimize(res, abs(nChild[v] - (nChild[i] - nChild[v])));
        }
    }

    if(res > n) cout << -1;
    else cout << res;
}
