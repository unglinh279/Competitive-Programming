#include<bits/stdc++.h>
#define ALL(v) (v).begin(), (v).end()
#define fi first
#define se second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
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

#define NAME

int getMax(int a, int b, int c){
    int maxx = max(b, c);
    if(a > maxx) return 0;
    return max(b, c) + 1 - a;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    freopen(NAME".inp", "r", stdin);
//    freopen(NAME".out", "w", stdout);

    int t; cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        cout << getMax(a, b, c) << ' ' << getMax(b, a, c) << ' ' << getMax(c, a, b) << '\n';

    }
    return 0;
}
