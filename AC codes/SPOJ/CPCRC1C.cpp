#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define NAME "a"
 
ll a, b;
ll dp[20][200][2];
 
void toDigit(int n, vector<int> &vc){
    while(n > 0){
        vc.push_back(n%10);
        n /= 10;
    }
}
 
ll solve(vector<int> &num, int idx, int add, int tight){
    if(idx == -1)return add;
    if(dp[idx][add][tight] != -1)return dp[idx][add][tight];
 
    int upper = tight ? num[idx] : 9;
 
    ll res = 0;
    for(int i = 0; i <= upper; i++)
        res += solve(num, idx-1, add+i, tight && (i == num[idx]));
 
    return dp[idx][add][tight] = res;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    freopen(NAME".inp", "r", stdin);
//    freopen(NAME".out", "w", stdout);
 
    while(true){
        cin >> a >> b;
        if(a == -1 && b == -1)break;
        vector<int> A, B;
        toDigit(a-1, A); toDigit(b, B);
 
        memset(dp, -1, sizeof dp);
        ll res1 = solve(A, A.size()-1, 0, 1);
        memset(dp, -1, sizeof dp);
        ll res2 = solve(B, B.size()-1, 0, 1);
        cout << res2 - res1 << '\n';
    }
    return 0;
}