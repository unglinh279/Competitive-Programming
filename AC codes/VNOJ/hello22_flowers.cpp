#include<bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

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
const int N = (int)1e6 + 5;

bool isPrime[N+N];
int n, m;
ll res = 0;

void getPrime(){
    int nn = n + m;
    memset(isPrime, 1, sizeof isPrime);

    for(int i = 2; i <= nn; i++) if(isPrime[i]){
        for(int j = 2*i; j <= nn; j += i){
            isPrime[j] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    if(n < m) swap(n, m);
    getPrime();

    for(int i = 1; i <= n + m; i++){
        if(isPrime[i+1]){
            if(i <= n) res += min(i, m);
            else res += m - max(0, i - n);
        }
    }

    cout << res;
    return 0;
}
