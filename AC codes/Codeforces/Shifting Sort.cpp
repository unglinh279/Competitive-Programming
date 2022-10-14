#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>

#define NAME "a"

int n;
vector<int> arr;
bool done = false;

struct group{
    int l, r, d;
};

void shift(int l, int r){
    int x = arr[r];
    for(int i = r; i > l; i--)
        arr[i] = arr[i-1];
    arr[l] = x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    freopen(NAME".inp", "r", stdin);
//    freopen(NAME".out", "w", stdout);

    int t; cin >> t;
    while(t--){
        cin >> n;
        arr.resize(n);
        for(int i = 0; i < n; i++) cin >> arr[i];

        vector<group> res;
        for(int i = 0; i < n; i++){
            pii save = {arr[i], i};
            for(int k = i+1; k < n; k++)
                if(arr[k] < save.fi) save = {arr[k], k};

            if(save.se != i){
                res.push_back({i+1, save.se+1, save.se-i});
                shift(i, save.se);
            }
        }

        cout << res.size() << '\n';
        for(auto x : res)
            cout << x.l << ' ' << x.r << ' ' << x.d << '\n';
    }
    return 0;
}
