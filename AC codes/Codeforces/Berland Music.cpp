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
const int N = (int)2e5 + 5;

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

int n, numDis = 0;
int arr[N], res[N], idx[N];
vector<int> like, dislike;

void init(){
    like.clear();
    dislike.clear();

    numDis = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        idx[arr[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        char c; cin >> c;
        if(c == '1')
            like.emplace_back(arr[i]);
        else{
            numDis++;
            dislike.emplace_back(arr[i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    freopen(NAME".inp", "r", stdin);
//    freopen(NAME".out", "w", stdout);

    int tc; cin >> tc;
    set<int> tmp;
    while(tc--){
        init();

        tmp.clear();
        for(int i = numDis+1; i <= n; i++) tmp.insert(i);
        sort(ALL(like));
        for(int x : like){
            auto it = tmp.lower_bound(x);
            if(it == tmp.end()) it--;
            res[idx[x]] = *it;
            tmp.erase(tmp.find(*it));
        }

        tmp.clear();
        for(int i = 1; i <= numDis; i++) tmp.insert(i);
        sort(ALL(dislike));
        for(int x : dislike){
            auto it = tmp.lower_bound(x);
            if(it == tmp.end()) it--;
            res[idx[x]] = *it;
            tmp.erase(tmp.find(*it));
        }

        for(int i = 1; i <= n; i++) cout << res[i] << ' ';
        cout << '\n';
    }
    return 0;
}
