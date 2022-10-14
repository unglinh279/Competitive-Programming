#include <bits/stdc++.h>
using namespace std;
int arr[50005], spt[50005][21];
 
int query(int l, int r)
{
    int j = (int)log2(r - l + 1);
    return max(spt[l][j], spt[r - (1 << j) + 1][j]);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    //freopen("a.inp","r",stdin);
    cin >> n >> q;
    int k = (int)log2(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
 
    for(int i = 0; i < n; i++) spt[i][0] = arr[i];
    for(int j = 1; (1 << j) <= n; j++){
        for(int i = 0; i + (1 << j) <= n; i++)
            spt[i][j] = max(spt[i][j - 1], spt[i + (1 << (j - 1))][j - 1]);
    }
 
    int res = 0;
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        l--; r--;
        if(query(l, r-1) <= arr[l])res++;
    }
    cout << res;
    return 0;
}