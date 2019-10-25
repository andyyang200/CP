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
vector<int> edges[90001];
int n;
int f(int a, int i){
    return  a * n + i;
}
vector<int> toposort;
bool visited[90001];
int index[90001];
int cnt = 0;
void dfs(int u){
    if (visited[u]) return;
    visited[u] = true;
    for(int v : edges[u]) dfs(v);
    index[u] = cnt++;
}
int main(){
    ri(n);
    FOR(i, 0, n){
        int j = (i + 1) % n;
        int t = n * n / 2;
        FOR(a, 0, n){
            FOR(b, 0, n){
                if (t == 0){
                    edges[f(i, a)].push_back(f(j, b));
                    t--;
                }
                else{
                    edges[f(j, b)].push_back(f(i, a));
                }
            }
        }
    }
    FOR(i, 0, n * n) dfs(i);
    FOR(i, 0, n){
        FOR(j, 0, n){
            printf("%d ", index[f(i, j)] + 1);
        }
        printf("\n");
    }

}


