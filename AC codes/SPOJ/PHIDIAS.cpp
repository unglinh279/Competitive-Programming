#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define pii pair<int,int>
 
#define NAME "phidias"
 
int n;
int H[250], W[250];
int dp[650][650];
 
int solve(int w, int h){
    int &res = dp[w][h];
    if(res!= -1) return res;
    res = w*h;
 
    for(int i = 0; i < n; i++){
        if(w - W[i] >= 0 && h - H[i] >= 0){
            res = min(res, solve(w - W[i], h) + solve(W[i], h - H[i]));
            res = min(res, solve(w, h - H[i]) + solve(w - W[i], H[i]));
        }
    }
    return res;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    freopen(NAME".inp", "r", stdin);
//    freopen(NAME".out", "w", stdout);
 
    int t; cin >> t;
    while(t--){
        int w, h;
        cin >> w >> h >> n;
        for(int i = 0; i < n; i++)
            cin >> W[i] >> H[i];
        memset(dp, -1, sizeof dp);
        cout << solve(w, h) << '\n';
    }
    return 0;
}