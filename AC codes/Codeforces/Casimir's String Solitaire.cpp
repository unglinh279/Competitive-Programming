#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define pii pair<int,int>
 
#define NAME "a"
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    freopen(NAME".inp", "r", stdin);
//    freopen(NAME".out", "w", stdout);
 
    int m; cin >> m;
    while(m--){
        string str; cin >> str;
        int res = 0;
        for(auto x : str){
            if(x == 'B') res++;
            else res--;
        }
 
        if(res == 0)cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}