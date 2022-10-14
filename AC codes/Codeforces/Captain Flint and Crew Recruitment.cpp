#include <iostream>
 
using namespace std;
 
int main()
{
    int n, t;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> t;
        if(t <= 30) cout << "NO" << '\n';
        else{
            cout << "YES"<< '\n';
            if(t == 36) cout << 6 << ' ' << 10 << ' ' << 15 << ' ' << t - 31 << '\n';
            else if(t == 40) cout << 6 << ' ' << 10 << ' ' << 15 << ' ' << t - 31 << '\n';
            else if(t == 44) cout << 6 << ' ' << 10 << ' ' << 15 << ' ' << t - 31 << '\n';
            else cout << 6 << ' ' << 10 << ' ' << 14 << ' ' << t - 30 << '\n';
        }
    }
    return 0;
}