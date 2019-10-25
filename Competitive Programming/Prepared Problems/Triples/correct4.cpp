#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <ctime>
#include <memory.h>
#include <tuple>
#include <unordered_map>
#include <bitset>
#include <map>
#include <cassert>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define pb(x) push_back(x)
#define fst first
#define snd second
#define mp(x, y) make_pair(x, y)

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
#define eprintf(args...) ;
#endif

#define FILE_NAME "a"

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

const int MAXN = 1e5 + 10;

int n;
vi g[MAXN];

bool read() {
    if  (scanf("%d", &n) < 1) {
        return 0;
    }
    forn(i, n) {
        g[i].clear();
    }
    forn(i, n - 1) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a;
        --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    return 1;
}

ll ans;
bool used[MAXN];
int sz[MAXN];
int deep[MAXN];

void dfs_sz(int v, int p) {
    sz[v] = 1;
    deep[v] = 0;
    for (int to : g[v]) {
        if  (to == p || used[to]) {
            continue;
        }
        dfs_sz(to, v);
        sz[v] += sz[to];
        deep[v] = max(deep[v], deep[to] + 1);
    }
}

int get_root(int v) {
    dfs_sz(v, -1);
    int p = -1;
    int S = sz[v];
    while (1) {
        int mx_to = -1;
        for (int to : g[v]) {
            if  (to == p || used[to]) {
                continue;
            }
            if  (mx_to == -1 || sz[to] > sz[mx_to]) {
                mx_to = to;
            }
        }
        if  (mx_to == -1 || sz[mx_to] * 2 <= S) {
            return v;
        }
        p = v;
        v = mx_to;
    }
    assert(0);
    return -1;
}

struct Arr {
    vi a;
    vi when;
    int timer;

    Arr(int n = 0) {
        a.assign(n, 0);
        when.assign(n, -1);
        timer = -1;
    }

    int get(int pos) {
        if  (pos < 0 || pos >= sz(a)) {
            return 0;
        }
        return when[pos] == timer ? a[pos] : 0;
    }

    void set(int pos, int val) {
        when[pos] = timer;
        a[pos] = val;
    }

    void add(int pos, int aux) {
        set(pos, get(pos) + aux);
    }

    void clear() {
        ++timer;
    }
};

void dfs_cnt(int v, int p, int de, int coef, Arr& cnt) {
    cnt.add(de, coef);
    for (int to : g[v]) {
        if  (to == p || used[to]) {
            continue;
        }
        dfs_cnt(to, v, de + 1, coef, cnt);
    }
}

vi* dfs_ans(int v, int p, int de, Arr& cnt) {
    vector<vi*> sons;
    for (int to : g[v]) {
        if  (to == p || used[to]) {
            continue;
        }
        auto* cur = dfs_ans(to, v, de + 1, cnt);
        sons.pb(cur);
    }

    if  (sons.empty()) {
        vi* res = new vi();
        res->pb(1);
        return res;
    }

    using T = vi*;
    int pos_max = max_element(all(sons), [&](const T& a, const T& b) { return sz(*a) < sz(*b); }) - sons.begin();
    swap(sons.back(), sons[pos_max]);

    if  (sz(sons) >= 2) {
        int mx_d = 0;
        forn(i, sz(sons) - 1) {
            mx_d = max(mx_d, sz(*sons[i]));
        }

        forn(d, mx_d) {
            int was = 0;
            for (const auto& son : sons) {
                if  (d >= sz(*son)) {
                    continue;
                }

                const int pos = sz(*son) - 1 - d;

                const ll coef = was * 1ll * (*son)[pos] * cnt.get(d + 1 - de);

                ans += coef;

                was += (*son)[pos];
            }
        }
    }

    forn(i, sz(sons) - 1) {
        forn(j, sz(*sons[i])) {
            int offset = sz(*sons.back()) - sz(*sons[i]);
            (*sons.back())[j + offset] += (*sons[i])[j];
        }
    }

    vi* res = sons.back();
    res->pb(1);
    return res;
}

void dfs_ans2(int v, int p, int de, Arr& cnt_pref, Arr& cnt_suff) {
    ll cur = cnt_pref.get(de) * 1ll * cnt_suff.get(de);
    ans += cur;

    for (int to : g[v]) {
        if  (to == p || used[to]) {
            continue;
        }

        dfs_ans2(to, v, de + 1, cnt_pref, cnt_suff);
    }
}

void go(int root) {
    root = get_root(root);
    dfs_sz(root, -1);

    vi sons;
    for (int to : g[root]) {
        if  (!used[to]) {
            sons.pb(to);
        }
    }

    Arr cnt(deep[root] + 1);
    cnt.add(0, +1);

    for (int to : sons) {
        dfs_cnt(to, root, 1, +1, cnt);
    }

    for (int to : sons) {
        dfs_cnt(to, root, 1, -1, cnt);
        dfs_ans(to, root, 1, cnt);
        dfs_cnt(to, root, 1, +1, cnt);
    }

    Arr cnt_pref(deep[root] + 1);
    Arr cnt_suff = cnt;
    for (int to : sons) {
        dfs_cnt(to, root, 1, -1, cnt_suff);
        dfs_ans2(to, root, 1, cnt_pref, cnt_suff);
        dfs_cnt(to, root, 1, +1, cnt_pref);
    }

    used[root] = 1;
    for (int to : sons) {
        go(to);
    }
}

ll solve() {
    ans = 0;
    forn(i, n) {
        used[i] = 0;
    }
    go(0);
    return ans;
}

int main() {
#ifdef LOCAL
    freopen(FILE_NAME ".in", "r", stdin);
    //freopen(FILE_NAME ".out", "w", stdout);
#endif

    assert(read());
    printf("%lld\n", solve());


#ifdef LOCAL
    eprintf("Time: %.10f\n", clock() * 1.0 / CLOCKS_PER_SEC);
#endif
    return 0;
}
