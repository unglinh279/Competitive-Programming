#include <bits/stdc++.h>
using namespace std;
string s;
int f[5001][5001];
int nkpalin(int l, int r){
    if(f[l][r])return f[l][r];
    if(l==r) return 0;
    if(l==r-1)
        if(s[l]==s[r])return 0;
        else return 1;
    int res;
    if(s[l]==s[r])res = nkpalin(l+1,r-1);
    else res = (min(nkpalin(l+1,r),nkpalin(l,r-1))+1);
 
    f[l][r]=res;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n>>s;
    cout<<nkpalin(0,n-1);
    return 0;
}