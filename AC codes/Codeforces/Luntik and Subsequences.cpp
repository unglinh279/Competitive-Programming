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

ll comb[61][61];

void init(){
    for(int i = 0; i < 61; i++){
        comb[0][i] = 1;
        comb[i][0] = 0;
    }
    comb[0][0] = 1;

    for(int i = 1; i < 61; i++) for(int j = 1; j < 61; j++){
        if(i > j) comb[i][j] = 0;
        if(i == j) comb[i][j] = 1;
        if(i < j)
            comb[i][j] = comb[i][j-1] + comb[i-1][j-1];
    }

}

int one = 0, zero = 0, other = 0, sum = 0;
ll numChoose = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    freopen(NAME".inp", "r", stdin);
//    freopen(NAME".out", "w", stdout);

    init();

    int t; cin >> t;
    while(t--){
        int k;
        one = 0; zero = 0; other = 0; sum = 0;
        cin >> k;
        for(int i = 0; i < k; i++){
            int x; cin >> x;
            sum += x;
            if(x == 1) one++;
            else if(x == 0) zero++;
            else other++;
        }

        numChoose = 0;
        if(one + other > 1) numChoose += comb[0][zero];
        for(int i = 1; i <= zero; i++)
            numChoose += comb[i][zero];

        if(sum == 1) numChoose++;
        numChoose *= one;

        if(sum == 0) cout << 0;
        else if(zero == 0) cout << one;
        else cout << numChoose;

        cout << '\n';
    }
    return 0;
}
