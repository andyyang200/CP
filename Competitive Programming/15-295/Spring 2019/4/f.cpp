#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b)  qfor(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------
int d[2005][2005];
int treed[2005][2005];
int added[2005];
int mind[2005];
int pre[2005];
bool used[2005][2005];
struct edge{
    int u, v, w;
    edge(){

    }
    edge(int x, int y, int z){
        u = x;
        v = y;
        w = z;
    }
};
vector<edge> ans;
vector<edge> edges[2005];
bool visited[2005];
void dfs(int start, int cur, int dis){
    if (visited[cur])
        return;
    visited[cur] = true;
    treed[start][cur] = dis;
    for(edge e : edges[cur]){
        dfs(start, e.v, dis + e.w);
    }
}
int main(){
    int n;
    while(cin >> n){
        FOR(i, 0, n){
            edges[i].clear();
        }
        ans.clear();
        fill(added, added + n, 0);
        fill(pre, pre + n, 0);
        FOR(i, 0, n){
            FOR(j, 0, n){
                scanf("%d", &d[i][j]);
                used[i][j] = false;
            }
        }
        added[0] = 1;
        FOR(i, 0, n){
            mind[i] = d[0][i];
        }
        FOR(i, 0, n - 1){
            edge minedge;
            int x = INF;
            FOR(j, 0, n){
                if (added[j]){
                    continue;
                }
                if (mind[j] < x){
                    x = mind[j];
                    minedge = edge(pre[j], j, mind[j]);
                }
            }
            ans.push_back(minedge);
            edges[minedge.u].push_back(minedge);
            edges[minedge.v].push_back(edge(minedge.v, minedge.u, minedge.w));
            used[minedge.u][minedge.v] = true;
            used[minedge.v][minedge.u] = true;
            added[minedge.v] = 1;
            FOR(j, 0, n){
                if (added[j]){
                    continue;
                }
                if (d[j][minedge.v] < mind[j]){
                    mind[j] = d[j][minedge.v];
                    pre[j] = minedge.v;
                }
            }
        }
        FOR(i, 0, n){
            fill(visited, visited + n, false);
            dfs(i, i, 0);
        }
        edge minedge(0, 0, INF);
        FOR(i, 0, n){
            FOR(j, 0, n){
                if (i == j) continue;
                if (treed[i][j] != d[i][j]){
                    if (d[i][j] < minedge.w){
                        minedge = edge(i, j, d[i][j]);
                    }
                }
            }
        }
        if (minedge.w == INF){
            FOR(i, 0, n){
                FOR(j, 0, n){
                    if (i == j) continue;
                    if (!used[i][j]){
                        minedge = edge(i, j, 1000000);
                        break;
                    }
                }
                if (minedge.w != INF){
                    break;
                }
            }
        }

        ans.push_back(minedge);
        for(edge e : ans){
            printf("%d %d %d\n", e.u + 1, e.v + 1, e.w);
        }
        printf("\n");
    }
}
/*
4
0 1 2 1
1 0 2 1
2 2 0 1
1 1 1 0
4
0 1 1 1
1 0 2 2
1 2 0 2
1 2 2 0
3
0 4 1
4 0 3
1 3 0
*/


