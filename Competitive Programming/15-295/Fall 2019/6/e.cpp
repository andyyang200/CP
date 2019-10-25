#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b)  qfor(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define ri(x) scanf("%d", &x)
#define rll(x) scanf("%lld", &x)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------
int bitcnt[100];
ll a[100005];
vector<int> hasbit[100005];
vector<int> edges[100005];
int d[100005];
int n;
map<pii, bool> m;
void bfs(int source){
    fill(d, d + n, INF);
    d[source] = 0;
    queue<int> q;
    q.push(source);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : edges[u]){
            if (d[v] == INF){
                q.push(v);
                d[v] = d[u] + 1;
            }
        }
    }
}
int main(){
    ri(n);
    FOR(i, 0, n){
        rll(a[i]);
        FOR(j, 0, 64){
            if (a[i] & (1LL << j)){
                bitcnt[j]++;
                hasbit[j].push_back(i);
            }
        }
    }
    FOR(i, 0, 64){
        if (bitcnt[i] >= 3){
            cout << 3 << endl;
            return 0;
        }
        if (bitcnt[i] == 2){
            int a = hasbit[i][0];
            int b = hasbit[i][1];
            if (!m[{a, b}]){
                edges[a].push_back(b);
                m[{a, b}] = true;
            }
            if (!m[{b, a}]){
                edges[b].push_back(a);
                m[{b, a}] = true;
            }
        }
    }
    int mind = INF;
    FOR(u, 0, n){
        for(int j = 0; j < edges[u].size(); j++){
            int v = edges[u][j];
            edges[u].erase(edges[u].begin() + j);
            bfs(u);
            mind = min(mind, d[v]);
            edges[u].insert(edges[u].begin() + j, v);
        }
    }
    if (mind == INF){
        cout << -1 << endl;
    }
    else{
        cout << mind + 1 << endl;
    }
}
