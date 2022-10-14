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
const int N = (int)2e5 + 5;
int n, arr[N], rev[N];

bool check(int i, int j, int dif, bool t){
    while(i <= n - t && j <= n - !t){
        if(arr[i] == rev[j]){
            i++; j++;
        }
        else{
            if(arr[i] != dif && rev[j] != dif) return false;
            if(arr[i] == dif && (arr[i+1] == rev[j] || arr[i+1] == dif)) i++;
            else if(rev[j] == dif && (rev[j+1] == arr[i] || rev[j+1] == dif)) j++;
            else return false;
        }
    }
    return true;
}

bool solve(){
    bool k = true;
    int x = 1;
    while(arr[x] == rev[x] && x <= n) x++;
    if(x >= n) return true;
    bool res = check(x+1, x, arr[x], 0) | check(x, x+1, rev[x], 1);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    freopen(NAME".inp", "r", stdin);
//    freopen(NAME".out", "w", stdout);

    int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
            rev[n-i+1] = arr[i];
        }

        if(solve()) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
    return 0;
}
