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

int a, b, c;
bool check(){
    if(a + b == c || b + c == a ||  a + c == b) return true;
    if(a == b) return (c % 2 == 0);
    else if(b == c) return (a % 2 == 0);
    else if(a == c) return (b % 2 == 0);
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    freopen(NAME".inp", "r", stdin);
//    freopen(NAME".out", "w", stdout);

    int tc; cin >> tc;
    while(tc--){
        cin >> a >> b >> c;
        if(check()) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}
