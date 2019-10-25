#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", z = " << z << endl
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

class UnionFind {
private:
  vector<int> p, rank, setSize;
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) { numSets--;
    int x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int closest[2000000];
int d[2000000];

int main(void)
{
    int m, n;
    scanf("%d%d", &m, &n);
    fill(closest, closest + (1 << m), -1);
    queue<int> q;
    FOR(i, 0, n){
        string s;
        cin >> s;
        int v = 0;
        FOR(j, 0, m){
            if (s[j] == '1'){
                v += (1 << j);
            }
        }
        q.push(v);
        closest[v] = v;
    }
    vector<pair<int, pii>> edges;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        FOR(i, 0, m){
            int v = u ^ (1 << i);
            if (closest[v] == -1){
                closest[v] = closest[u];
                d[v] = d[u] + 1;
                q.push(v);
            }
            else if (closest[v] != closest[u]){
				edges.push_back({ 1 + d[u] + d[v],{ closest[u], closest[v] } });
            }
        }
    }
    sort(edges.begin(), edges.end());
    UnionFind uf(1 << m);
    int cnt = 0;
    int ans = 0;
    for(auto e : edges){
        int u = e.second.first;
        int v = e.second.second;
        if (!uf.isSameSet(u, v)){
            uf.unionSet(u, v);
            cnt++;
            ans += e.first;
        }
    }
    cout << m * (n - 1) - ans << endl;
}


