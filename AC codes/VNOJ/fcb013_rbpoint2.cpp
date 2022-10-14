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
const int N = (int)1e5 + 5;

int a[N], b[N];
int n;

bool check(int dif){
    int i = 0, j = 0;
    while(i < n && j < n){
        if(abs(a[i] - b[j]) <= dif) return true;
        if(a[i] > b[j]) j++;
        else i++;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    freopen(NAME".inp", "r", stdin);
//    freopen(NAME".out", "w", stdout);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    sort(a, a + n); sort(b, b + n);

    int l = 0, r = max(abs(a[0] - b[n-1]), abs(b[0] - a[n-1]));
    int res = r;
    while(l <= r){
        int m = (l + r) / 2;
        if(check(m)){
            r = m-1;
            res = m;
        }
        else l = m+1;
    }
    cout << res;
    return 0;
}
