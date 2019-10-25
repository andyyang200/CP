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

vector<pii> edges[100005];
int problem[100005];
bool contains[100005];
int ans;
void dfs(int u, int p){
    contains[u] = 0;
    for(pii c : edges[u]){
        int v = c.first;
        int t = c.second;
        if (v == p) continue;
        problem[v] = t;
        if (problem[v]){
            contains[u] = 1;
        }
        dfs(v, u);
        contains[u] = max(contains[u], contains[v]);
    }
}
int main(){
    int n;
    cin >> n;
    FOR(i, 0, n - 1){
        int u, v, t;
        scanf("%d%d%d", &u, &v, &t);
        u--;
        v--;
        t--;
        edges[u].push_back({v, t});
        edges[v].push_back({u, t});
    }
    ans = 0;
    dfs(0, -1);
    vector<int> v;
    FOR(i, 0, n){
        if (problem[i] && !contains[i]){
            ans++;
            v.push_back(i + 1);
        }
    }
    cout << ans << endl;
    for(int x : v){
        printf("%d ", x);
    }
    cout << endl;


}

