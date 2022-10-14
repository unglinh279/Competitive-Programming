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


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    freopen(NAME".inp", "r", stdin);
//    freopen(NAME".out", "w", stdout);

    int t; cin >> t;
    while(t--){
        string s; cin >> s;

        if((s[s.size()-1] - '0') % 2 == 0) cout << 0;
        else if((s[0] - '0') % 2 == 0) cout << 1;
        else{
            bool k = false;
            for(char x : s)
                if((x - '0') % 2 == 0) k = true;
            if(k)cout << 2;
            else cout << -1;
        }

        cout << '\n';
    }
    return 0;
}
