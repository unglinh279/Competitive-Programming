#include <bits/stdc++.h>
#define ALL(a) a.begin(), a.end()
#define pii pair<int,int>
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)

using namespace std;

const int N = 2005;

const int INF = (int)1e9 + 7;
const int badMask = MASK(1) | MASK(8) | MASK(9);

bool minimize(int &x, const int &y){
    if(x > y){
        x = y;
        return true;
    } else return false;
}

int n, m;
int dp[N][MASK(10) + 5];

vector<pii> arr;
map<int, int> cnt;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;;
        cnt[x]++;
    }

    arr = vector<pii>(ALL(cnt));
    n = arr.size();

    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = arr[0].second;
    dp[0][MASK(0)] = 0;

    for(int i = 0; i < n-1; i++) for(int j = 0; j < MASK(10); j++) if(dp[i][j] < INF){
        int prev = arr[i].first;
        int cur = arr[i + 1].first;
        int newMask = cur - prev >= 10 ? 0 : ((1LL * j) << (cur - prev)) & (MASK(10) - 1);

        minimize(dp[i + 1][newMask], dp[i][j] + arr[i + 1].second);
        if((newMask & badMask) == 0) minimize(dp[i + 1][newMask | MASK(0)], dp[i][j]);
    }

    int res = INF;
    for(int j = 0; j < MASK(10); j++) minimize(res, dp[n - 1][j]);
    cout << res;

    return 0;
}
