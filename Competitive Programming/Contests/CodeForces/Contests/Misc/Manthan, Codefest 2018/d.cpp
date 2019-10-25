#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

//---------------------------------------------------------------------------------------------------------------


multiset<int> levels[200005];
vector<int> edges[200005];

void dfs(int u, int d, int p){
    levels[d].insert(u);
    for(int v : edges[u]) {
        if (v == p) continue;
        dfs(v, d + 1, u);
    }
}
int a[200005];
int main(){
    int n;
    cin >> n;
    FOR(i, 0, n - 1) {
        int u, v;
        scanf("%d%d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1, 0, -1);
    FOR(i, 0, n) {
        scanf("%d", &a[i]);
    }
    int d = 0;
    FOR(i, 0, n) {
        auto itr = levels[d].find(a[i]);
        if (itr == levels[d].end()){
            cout << "No" << endl;
            return 0;
        }
        levels[d].erase(itr);
        if (levels[d].size() == 0){
            d++;
        }
    }
    cout << "Yes" << endl;
}

