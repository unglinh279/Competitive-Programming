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
const int N = (int)1e3 + 5;

int n;
int arr[N], dp[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    freopen(NAME".inp", "r", stdin);
//    freopen(NAME".out", "w", stdout);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            int w = arr[i] - arr[j];
            if((dp[i] < dp[j] + 1 && binary_search(arr, arr + j, w))
               || binary_search(arr+j+1, arr + n, w))
                dp[i] = dp[j] + 1;
        }
    }


    cout << *max_element(dp, dp + n) + 1;
    return 0;
}
