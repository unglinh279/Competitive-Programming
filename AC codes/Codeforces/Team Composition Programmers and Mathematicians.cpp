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

int solve(int a, int b){
    int res = 0;
    if(b - a >= 2){
        int x = min(a, (b - a) / 2);
        a -= x; b -= 3*x;
        res += x;
    }

    if(!a || !b) return res;

    int x = min(a / 2, b / 2);
    res += x;
    a -= 2*x; b -= 2*x;

    if(!a || !b) return res;

    if(a + b >= 4) res++;
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    freopen(NAME".inp", "r", stdin);
//    freopen(NAME".out", "w", stdout);

    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        if(a > b) swap(a, b);
        cout << solve(a, b) << '\n';
    }
    return 0;
}
