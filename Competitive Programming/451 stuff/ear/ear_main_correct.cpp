//Andy Yang
#include <bits/stdc++.h>
using namespace std;

vector<int> edges[1000001];
vector<pair<int, int>> b[1000001];
bool visited[1000001];
bool used[1000001];
int depth[1000001];
int p[1000001];
vector<int> ans[1000001];

/*
Finds and orders all back edges.
Also calculates the depth and parent of each node in the DFS tree.
*/
void dfs(int u, int d) {
    visited[u] = true;
    depth[u] = d;
    for (int v : edges[u]) {
        if (v == p[u]) continue;
        if (visited[v] && depth[v] < depth[u])
            b[depth[v]].push_back({ v, u });
        else if (!visited[v]) {
            p[v] = u;
            dfs(v, d + 1);
        }
    }
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    p[0] = -1;
    dfs(0, 0);
    for (int d = 0; d < n; d++) {
        for (pair<int, int> e : b[d]) {
            vector<int> ear;
            int v = e.first;
            int u = e.second;
            ear.push_back(v);
            ear.push_back(u);
            while (u != v && !used[u]) {
                used[u] = true;
                u = p[u];
                ear.push_back(u);
            }
        }
    }
    int earcnt = m - n + 1;
    printf("%d\n", earcnt);
    for(int i = 0; i < earcnt; i++){
        printf("%d ", ans[i].size() - 1);
        for (int j = 0; j < ans[i].size() - 1; j++) {
            printf("%d %d ", ans[i][j], ans[i][j + 1]);
        }
        printf("\n");
    }
}

