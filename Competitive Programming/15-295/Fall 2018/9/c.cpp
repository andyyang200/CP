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

vector<int> edges[400005];
bool visited[400005];
void dfs(int u){
    if (visited[u]) return;
    visited[u] = true;
    for(int v : edges[u]) dfs(v);
}

int main(){

    int n, m;
    cin >> n >> m;
    int q;
    cin >> q;
    FOR(i, 0, q){
        int r, c;
        scanf("%d%d", &r, &c);
        r--;
        c--;
        edges[r].push_back(n + c);
        edges[n + c].push_back(r);
    }
    int ans = -1;
    FOR(i, 0, n + m){
        if(!visited[i]){
            dfs(i);
            ans++;
        }
    }
    cout << ans << endl;
}


