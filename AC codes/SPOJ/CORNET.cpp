#include <bits/stdc++.h>
using namespace std;
 
const int N = 20005;
const int MOD = 1000;
 
int cha[N], len[N];
 
void root(int u)
{
    if(u != cha[u]){
        root(cha[u]);
        len[u] += len[cha[u]];
        cha[u] = cha[cha[u]];
    }
}
 
int main()
{
//    freopen("inp.txt", "r", stdin);
 
    int T, n;
    char c;
    cin >> T;
 
    while(T--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cha[i] = i;
            len[i] = 0;
        }
        while(cin >> c){
            if(c == 'E'){
                int i; cin >> i;
                root(i);
                cout << len[i] << '\n';
            }
            else if(c == 'I'){
                int i, j;
                cin >> i >> j;
                cha[i] = cha[j];
                len[i] = len[j] + abs(i-j) % MOD;
            }
            else break;
        }
    }
    return 0;
}