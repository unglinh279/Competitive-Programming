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

const int N = 50005;

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

int n, m;
pii arr[N];

void init(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++) cin >> arr[i].second >> arr[i].first;
}

bool check(int k){
    vector<pii> tmp;
    for(int i = 1; i <= k; i++) tmp.emplace_back(arr[i]);
    sort(ALL(tmp));

    set<int> save;
    for(int i = 1; i <= n; i++) save.insert(i);

    for(auto x : tmp){
        auto it = save.lower_bound(x.second);

        if(it != save.end() && *it <= x.first)
            save.erase(it);
        else return false;
    }
    return true;
}

int solve(){
    int l = 1, r = m, res = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid)){
            l = mid+1;
            res = mid;
        }
        else r = mid-1;
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    freopen(NAME".inp", "r", stdin);
//    freopen(NAME".out", "w", stdout);

    int tc; cin >> tc;
    while(tc--){
        init();
        cout << solve() << '\n';
    }
    return 0;
}
