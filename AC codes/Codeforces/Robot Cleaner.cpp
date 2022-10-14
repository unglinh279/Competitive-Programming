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
#define piii pair<pii, int>

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

int n, m, sx, sy, tx, ty;
int dx = 1, dy = 1;

int bfs(){
    queue<piii> q;
    q.push({{sx, sy}, 0});

    while(!q.empty()){
        pii u = q.front().first;
        int d = q.front().second;

        if(u.first == tx || u.second == ty)
            return d;

        q.pop();
        int xx = u.first + dx;
        int yy = u.second + dy;

        if(xx > n) dx = -dx;
        if(yy > m) dy = -dy;

        xx = u.first + dx;
        yy = u.second + dy;

        q.push({{xx, yy}, d+1});
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    freopen(NAME".inp", "r", stdin);
//    freopen(NAME".out", "w", stdout);

    int tc; cin >> tc;
    while(tc--){
         cin >> n >> m >> sx >> sy >> tx >> ty;
         dx = 1; dy = 1;
         cout << bfs() << '\n';
    }
    return 0;
}
