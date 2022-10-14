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

    int tc; cin >> tc;
    while(tc--){
        int n, k, cnt = 0;
        cin >> n >> k;
        if((n+1)/2 < k) cout << -1 << '\n';
        else{
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    if(i == j && i&1 && cnt < k){
                        cout << 'R';
                        cnt++;
                    }
                    else cout << '.';
                }
                cout << '\n';
            }
        }
    }
    return 0;
}
