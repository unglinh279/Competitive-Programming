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

int n;
int arr[55];

bool check(int maz){
    for(int i = 1; i <= n; i++)
        if(arr[i] != maz) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    freopen(NAME".inp", "r", stdin);
//    freopen(NAME".out", "w", stdout);

    int tc; cin >> tc;
    while(tc--){
        ll res = 0;
        cin >> n;
        int maz = 0;
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
            maximize(maz, arr[i]);
        }

        while(check(maz)){
            int change = 0;
            for(int i = 1; i <= n; i++)
                if(arr[i] != maz) maximize(change, arr[i]);

            res += (maz - change);
            for(int i = 1; i <= n; i++)
                if(arr[i] != maz) arr[i] += (maz - change);
        }
        cout << res << '\n';
    }
    return 0;
}
