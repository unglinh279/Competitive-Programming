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
const int N = 10005;

struct data{
    int x, y, id;
    data(int _x = 0, int _y = 0, int _id = 0){
        x = _x; y = _y; id = _id;
    }

    bool operator <(const data& rhs) const{
        return min(x, rhs.y) < min(y, rhs.x);
    }
};

data arr[N];
int n;
int startA, startB, finishA, finishB;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    freopen(NAME".inp", "r", stdin);
//    freopen(NAME".out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i].x;
    for(int i = 1; i <= n; i++) cin >> arr[i].y;
    for(int i = 1; i <= n; i++) arr[i].id = i;

    sort(arr+1, arr + n+1);
    for(int i = 1; i <= n; i++){
        startA = finishA;
        finishA = startA + arr[i].x;
        startB = max(finishA, finishB);
        finishB = startB + arr[i].y;
    }

    cout << finishB << '\n';
    for(int i = 1; i <= n; i++) cout << arr[i].id << ' ';
    return 0;
}
