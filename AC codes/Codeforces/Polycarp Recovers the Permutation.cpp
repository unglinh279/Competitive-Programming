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
int n, arr[N];

vector<int> solve(int l, int r, int val){
    deque<int> x;
    x.push_back(val);

    while(l <= r){
        if(arr[l] < x.back())
            x.push_front(arr[l++]);
        else if(arr[r] < x.front())
            x.push_back(arr[r--]);
        else return vector<int>(0);
    }

    vector<int> res;
    while(!x.empty()){
        res.push_back(x.front());
        x.pop_front();
    }
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
        for(int i = 1; i <= n; i++) cin >> arr[i];

        vector<int> r1 = solve(1, n-1, arr[n]);
        vector<int> r2 = solve(2, n, arr[1]);

        if((int)r1.size() != 0)
            for(int i : r1) cout << i << ' ';
        else if((int)r2.size() != 0)
            for(int i : r2) cout << i << ' ';
        else cout << -1;

        cout << '\n';
    }
    return 0;
}
