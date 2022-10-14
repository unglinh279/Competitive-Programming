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

bool compare(pii& lhs, pii& rhs){
    if(lhs.first == rhs.first) return lhs.second > rhs.second;
    else return lhs.first < rhs.first;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    freopen(NAME".inp", "r", stdin);
//    freopen(NAME".out", "w", stdout);

    int tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        pii save[1005];
        for(int i = 1; i <= n; i++) cin >> save[i].first >> save[i].second;
        sort(save + 1, save + n + 1, compare);
        for(int i = 1; i <= n; i++){
            int l = save[i].first, r = save[i].second;
            int num = save[i].first;
            for(int j = i+1; j <= n; j++){
                if(save[j].first == l){
                    num = save[j].second+1;
                    break;
                }
            }
            cout << l << ' ' << r << ' ' << num << '\n';
        }
        cout << '\n';
    }
    return 0;
}
