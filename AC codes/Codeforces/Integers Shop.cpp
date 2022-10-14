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
    if(x >= y){
        x = y;
        return true;
    } else return false;
}
bool maximize(int &x, const int &y){
    if(x <= y){
        x = y;
        return true;
    } else return false;
}

#define NAME "a"
const int INF = (int)2e9 + 5;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    freopen(NAME".inp", "r", stdin);
//    freopen(NAME".out", "w", stdout);

    int tc; cin >> tc;
    while(tc--){
        int n; cin >> n;

        int left = INF, right = 0;
        int priceLeft, priceRight;

        map<pii, int> save;
        for(int i = 1; i <= n; i++){
            int l, r, c;
            cin >> l >> r >> c;
            if(save[{l, r}] == 0) save[{l, r}] = c;
            else minimize(save[{l, r}], c);

            if(l < left){
                left = l;
                priceLeft = c;
            }
            if(l == left) minimize(priceLeft, c);
            if(r > right){
                right = r;
                priceRight = c;
            }
            if(r == right) minimize(priceRight, c);

            int res = priceLeft + priceRight;
            if(save[{left, right}] != 0)
                minimize(res, save[{left, right}]);

            cout << res << '\n';
        }
    }
    return 0;
}
