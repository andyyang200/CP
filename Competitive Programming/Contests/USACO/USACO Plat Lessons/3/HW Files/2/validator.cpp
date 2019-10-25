#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
vector<int> edges[100005];
bool visited[100005];
bool good = true;
void dfs(int u, int p){
    if (visited[u]){
        good = false;
        return;
    }
    visited[u] = true;
    for(int v : edges[u]){
        if (v == p) continue;
        dfs(v, u);
    }
}
int main(int argc, char* argv[])
{
    registerValidation(argc, argv);

    int n = inf.readInt(3, 100000, "n");
    inf.readEoln();
    for(int i = 0; i < n - 1; i++){
        int a = inf.readInt(1, n, "a");
        inf.readSpace();
        int b = inf.readInt(1, n, "b");
        ensuref(a != b, "no loops");
        edges[a].push_back(b);
        edges[b].push_back(a);
        inf.readEoln();
    }
    inf.readEof();
    good = true;
    dfs(1, -1);
    for(int i = 1; i <= n; i++){
        if (!visited[i])
            good = false;
    }
    ensuref(good, "graph must be a tree");
    return 0;
}
