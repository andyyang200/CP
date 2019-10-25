#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b)  qfor(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------


vector<vector<int>> leaves;
set<pii> s;
vector<int> edges[100005];
int n, r;
void dfs(int u, int p, int i){
    if (edges[u].size() == 1){
        leaves[i].push_back(u);
    }
    else{
        for(int v : edges[u]){
            if (v == p) continue;
            dfs(v, u, i);
        }
    }
}
int main(){
    cin >> n >> r;
    FOR(i, 0, n - 1){
        int u, v;
        scanf("%d%d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    int i = 0;
    for(int c : edges[r]){
        leaves.push_back(vector<int>());
        dfs(c, r, i++);
    }
    vector<pii> ans;
    FOR(i, 0, leaves.size()){
        s.insert({leaves[i].size(), i});
    }
    while(s.size() > 1){
        auto a = (--s.end());
        auto b = a;
        b--;
        int i = (*a).second;
        int j = (*b).second;
        s.erase(a);
        s.erase(b);
        while(leaves[i].size() > 0 && leaves[j].size() > 0){
            ans.push_back({leaves[i].back(), leaves[j].back()});
            leaves[i].pop_back();
            leaves[j].pop_back();
        }
        if (!leaves[i].empty()){
            s.insert({leaves[i].size(), i});
        }
        if (!leaves[j].empty()){
            s.insert({leaves[j].size(), j});
        }
    }
    if (s.size() > 0){
        for(int x : leaves[(*s.begin()).second]){
            ans.push_back({r, x});
        }

    }

    cout << ans.size() << endl;
    for(pii p : ans){
        printf("%d %d\n", p.first, p.second);
    }
}

/*
4 0
0 1
0 2
0 3

6 0
0 1
0 2
0 3
1 4
1 5


*/
