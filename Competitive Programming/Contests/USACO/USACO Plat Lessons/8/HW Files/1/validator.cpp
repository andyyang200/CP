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

int main(int argc, char* argv[])
{
    registerValidation(argc, argv);
    int n = inf.readInt(1, 100000, "n");
    inf.readSpace();
    int m = inf.readInt(0, min((ll)n * (n - 1) / 2, (ll)100000));
    inf.readEoln();
    set<pii> s;
    FOR(i, 0, m){
        int u = inf.readInt(1, n, "u");
        inf.readSpace();
        int v = inf.readInt(1, n, "v");
        inf.readEoln();
        ensuref(u != v, "simple graph");
        if (v < u) swap(u, v);
        s.insert({u, v});
    }
    inf.readEof();
    ensuref(s.size() == m, "no duplicate edges");
}
