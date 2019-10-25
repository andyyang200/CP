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
#define ri2(x, y) scanf("%d%d", &x, &y)
#define ri3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define rll(x) scanf("%lld", &x)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------
vector<int> edges[200005];
int p[200005];
set<int> children[200005];
void dfs(int u){
    for(int v : edges[u]){
        if (v == p[u]){
            continue;
        }
        children[u].insert(v);
        p[v] = u;
        dfs(v);
    }
}
int n;
int a[200005];
bool match(set<int>& s1, set<int> &s2){
    if (s1.size() != s2.size()) return false;
    for(int x : s1){
        if (s2.find(x) == s2.end()){
            return false;
        }
    }
    return true;
}
int main(){
    ri(n);
    FOR(i, 0, n - 1){
        int u, v;
        ri2(u, v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    p[1] = -1;
    dfs(1);
    FOR(i, 0, n){
        ri(a[i]);
    }
    if (a[0] != 1){
        cout << "No" << endl;
        return 0;
    }
    int j = 1;
    FOR(i, 0, n){
        int u = a[i];
        int nc = children[u].size();
        set<int> s;
        FOR(x, 0, nc){
            s.insert(a[j++]);
        }
        if (!match(children[u], s)){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

}
