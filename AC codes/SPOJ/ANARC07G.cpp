#include <bits/stdc++.h>
using namespace std;
 
const int N = 100005;
 
int sp, fp;
map<string, int> id;
pair<int, int> f[N][2];
int cha[N];
vector<int> tree[N];
 
void add(pair<int, int> &to, pair<int,int> from){
    to.first += from.first;
    to.second += from.second;
}
 
int price(pair<int, int> tk){
    return tk.first*sp + tk.second*fp;
}
 
bool empt(pair<int,int> p){
    return (!p.first && !p.second);
}
 
int amount(pair<int, int> p){
    return p.first + p.second;
}
 
int get_id(string name)
{
    auto it = id.find(name);
    if(it == id.end()){
        id.insert({name, id.size()});
        return id.size()-1;
    }
    else return it->second;
}
 
pair<int, int> best(int u, bool done){
    if(tree[u].empty()){
        if(done) return {0, 0};
        else{
            if(sp < fp) return {1, 0};
            else return {0, 1};
        }
    }
 
    if(empt(f[u][done])){
        pair<int, int> ft = {0, 1};
 
        // try family ticket
        for(int v : tree[u])
            add(ft, best(v, 1));
 
        // give single ticket
        pair<int, int> st = {1 - done, 0};
        for(int v : tree[u])
            add(st, best(v, 0));
 
        //pick the best
        if(price(ft) == price(st))
            f[u][done] = amount(ft) < amount(st) ? ft : st;
        else
            f[u][done] = price(ft) < price(st) ? ft : st;
 
    }
    return f[u][done];
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
 
//    freopen("inp.txt", "r", stdin);
 
    int test = 0;
    while(cin >> sp >> fp){
        if(sp == 0 && fp == 0)break;
 
        id.clear();
        memset(tree, 0, sizeof tree);
        memset(cha, -1, sizeof cha);
        memset(f, 0, sizeof f);
 
        cin >> ws;
        string _line;
        while(getline(cin, _line)){
            string parent, child;
            istringstream in(_line);
 
            in >> parent;
            int u = get_id(parent);
            while(in >> child){
                int v = get_id(child);
                cha[v] = u;
                tree[u].push_back(v);
            }
 
            cin >> ws;
            if(isdigit(cin.peek()))break;
        }
        pair<int, int> res = {0, 0};
 
        for(int i = 0; i < id.size(); i++)
            if(cha[i] == -1) add(res, best(i, 0));
 
        cout << ++test << ". " << res.first << ' ' << res.second << ' ' << price(res) << '\n';
    }
 
    return 0;
}