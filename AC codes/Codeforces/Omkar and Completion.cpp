#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b, t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n % 2 == 0) cout << n/2 <<" "<< n/2 << endl;
        else
        {
            long long ans = n;
            for(long long i = 2; i*i <= n; i++)
            {
                if(n % i == 0)
                {
                    ans = i;
                    break;
                }
            }
            cout << n/ans << " " << n - (n/ans) << endl;
        }
    }
    return 0;
}