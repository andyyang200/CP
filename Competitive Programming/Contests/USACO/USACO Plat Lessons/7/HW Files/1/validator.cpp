#include <bits/stdc++.h>
#include "testlib.h"

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
vector<int> edges[200005];
bool visited[200005];
void check(int u, int p) {
    visited[u] = true;
    for(int v : edges[u]) {
        if (v == p) continue;
        ensuref(!visited[v], "no cycle");
        check(v, u);
    }
}
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 200000, "n");
    inf.readEoln();
    FOR(i, 0, n - 1) {
        int u = inf.readInt(1, n, "u");
        inf.readSpace();
        int v = inf.readInt(1, n, "v");
        inf.readSpace();
        inf.readInt(1, 1000000000, "l");
        inf.readEoln();
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    check(1, -1);
    FOR(i, 1, n + 1) {
        ensuref(visited[i], "must be connected");
    }
    int h = inf.readInt(1, n, "h");
    set<int> s;
    FOR(i, 0, h) {
        inf.readSpace();
        int a = inf.readInt(1, n, "a");
        s.insert(a);
    }
    inf.readEoln();

    int k = inf.readInt(1, n, "k");
    FOR(i, 0, k) {
        inf.readSpace();
        int a = inf.readInt(1, n, "a");
        s.insert(a);
    }
    inf.readEoln();
    inf.readEof();
    ensuref(h + k <= n, "oops");
    ensuref(s.size() == h + k, "oops");
}
