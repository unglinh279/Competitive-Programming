#include <bits/stdc++.h>
using namespace std;

vector<int> arr, ans(0);
int matchR[205], n;
bool graph[205][205], visited[205];
int avail[205];

bool dfs(int u)
{
    for(int v = 0; v < n; v++)
    {
        if(graph[u][v] && !visited[v] && !avail[v]){
            visited[v] = true;
            if(matchR[v] < 0 || dfs(matchR[v])){
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}

int maxBPM()
{
    memset(matchR, -1, sizeof matchR);

    int res = 0;
    for(int u = 0; u < n; u++)
    {
        if(avail[u]) continue;
        memset(visited, 0, sizeof visited);

        if(dfs(u)) res++;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    while(n--){
        int x; cin >> x;
        if(!binary_search(arr.begin(), arr.end(), x))arr.push_back(x);
    }

    n = arr.size();
    sort(arr.begin(), arr.end());

    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            if(arr[j] % arr[i] == 0)
                graph[i][j] = 1;

    int res = n - maxBPM();

    int cnt = 0;
    int out = 0;

    for(int i = 0; i < n && cnt < res; i++){
        if(avail[i]) continue;

        for(int j = 0; j < n; j++){
            if(graph[i][j]){
                if(!avail[j]) out++;
                avail[j]++;
            }
        }
        int res_tmp = n - out - maxBPM();
        if(res == res_tmp)ans.push_back(arr[i]);
        else{
            for(int j = 0; j < n; j++){
                if(graph[i][j]){
                    avail[j]--;
                    if(!avail[j]) out--;
                }
            }
        }
    }

    cout << res << '\n';
    for(int i : ans)cout << i << ' ';

    return 0;
}
