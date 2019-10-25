#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

vector< vi > g;

int mc, vc;
vi mark;
vi visited;
vi matched;

bool dfs(int v) {
    if (visited[v] == vc) return false;
    visited[v] = vc;
    
    if (mark[v] == mc) {
        for (int i = 0; i < g[v].size(); ++i) {
            int u = g[v][i];
            if (mark[u] != mc && dfs(u)) {
                matched[v] = u;
                matched[u] = v;
                return true;
            }
        }
    } else {
        if (matched[v] == -1) {
            return true;
        } else {
            return dfs(matched[v]);
        }
    }
    return false;
}

bool match(int n, int s) {
    ++mc;
    matched.assign(n + 1, -1);
    mark[s] = mc;
    for (int i = 0; i < g[s].size(); ++i) mark[g[s][i]] = mc;
    int paired = 0;
    for (int v = 1; v <= n; ++v) if (mark[v] == mc) {
        ++vc;
        if (dfs(v)) {
            ++paired;
        }
    }
    return paired + g[s].size() + 1 == n;
}

void solve() {
    int n, m; cin >> n >> m;
    
    g.resize(n + 1);
    mark.resize(n + 1);
    visited.resize(n + 1);
    matched.resize(n + 1);
    
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    for (int s = 1; s <= n; ++s) if (g[s].size() >= n / 2) {
        if (match(n, s) == true) {
            cout << "Yes" << endl;
            cout << s << ' ' << g[s].size() << endl;
            for (int i = 0; i < g[s].size(); ++i)
                cout << g[s][i] << ' ' << matched[g[s][i]] << endl;
            return;
        }
    }
    cout << "No" << endl;
}

int main() {
    solve();
    return 0;
}
