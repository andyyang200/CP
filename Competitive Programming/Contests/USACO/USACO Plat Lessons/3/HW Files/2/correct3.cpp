#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

i64 total = 0;

struct TData {
    int h;

    deque<i64> p, p2;

    void merge(TData &d) {
        for (auto it1 = p.begin(), it2 = d.p2.begin(); it1 != p.end() && it2 != d.p2.end(); ++it1, ++it2) total += *it1 * *it2;
        for (auto it1 = p2.begin(), it2 = d.p.begin(); it1 != p2.end() && it2 != d.p.end(); ++it1, ++it2) total += *it1 * *it2;
        if (p2.size() < max(p.size(), d.p.size())) p2.resize(max(p.size(), d.p.size()));
        for (auto it1 = p2.begin(), it2 = p.begin(), it3 = d.p.begin(); it2 != p.end() && it3 != d.p.end(); ++it1, ++it2, ++it3) *it1 += *it2 * *it3;
        if (p2.size() < d.p2.size()) p2.resize(d.p2.size());
        for (auto it1 = p2.begin(), it2 = d.p2.begin(); it1 != p2.end() && it2 != d.p2.end(); ++it1, ++it2) *it1 += *it2;
        if (p.size() < d.p.size()) p.resize(d.p.size());
        for (auto it1 = p.begin(), it2 = d.p.begin(); it1 != p.end() && it2 != d.p.end(); ++it1, ++it2) *it1 += *it2;
    }

    void up() {
        ++h;
        ++*p.begin();
        p.push_front(0);
        if (!p2.empty()) p2.pop_front();
    }

    void swap(TData &d) {
        ::swap(h, d.h);
        p.swap(d.p);
        p2.swap(d.p2);
    }

    void clear() {
        h = 0;
        p = {0};
        p2 = {0};
    }

    void print() {
        cerr << "---\n";
        cerr << h << '\n';
        for (auto w: p) cerr << w << ' ';
        cerr << '\n';
        for (auto w: p2) cerr << w << ' ';
        cerr << '\n';
        cerr << "---\n";
    }
};

const int maxn = 110000;
TData d[maxn];
vi e[maxn];

void dfs(int v, int p) {
//    cerr << v << '\n';
    for (int u: e[v]) {
        if (u == p) continue;
        dfs(u, v);
        d[u].up();
        if (!d[u].p2.empty()) total += *d[u].p2.begin();
        if (d[u].h > d[v].h) d[v].swap(d[u]);
        d[v].merge(d[u]);
//        cerr << v << ' ' << u << ' ' << total << '\n';
//        d[v].print();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    forn(i, n) d[i].clear(), e[i].clear();
    forn(i, n - 1) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        e[x].pb(y);
        e[y].pb(x);
    }
    total = 0;
    dfs(0, -1);
    cout << total << '\n';
    return 0;
}
