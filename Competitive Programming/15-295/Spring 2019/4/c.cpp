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
int s[500];
bool d[500][500];
int main(){
    int n, m;
    while(cin >> n){
        scanf("%d", &m);
        FOR(i, 0, n) {
            scanf("%d", &s[i]);
        }
        FOR(i, 0, n){
            FOR(j, 0, n){
                d[i][j] = 0;
            }
        }
        vector<pii> edges;
        int ans = 0;
        FOR(i, 0, m){
            int u, v;
            scanf("%d%d", &u, &v);
            u--;
            v--;
            d[u][v] = 1;
            d[v][u] = 1;
            edges.push_back({u, v});
            ans = max(ans, s[u] + s[v]);
        }
        FOR(i, 0, m){
            FOR(j, i + 1, m){
                pii a = edges[i];
                pii b = edges[j];
                int u1 = a.first;
                int v1 = a.second;
                int u2 = b.first;
                int v2 = b.second;
                if (u1 == u2 || u1 == v2 || v1 == u2 || v1 == v2){
                    continue;
                }
                if (d[u1][u2] && d[u1][v2] && d[v1][u2] && d[v1][v2]){
                    ans = max(ans, s[u1] + s[v1] + s[u2] + s[v2]);
                }
            }
        }
        FOR(i, 0, m){
            int a = edges[i].first;
            int b = edges[i].second;
            FOR(c, 0, n){
                if (a == c || b == c){
                    continue;
                }
                if (d[a][c] && d[b][c]){
                    ans = max(ans, s[a] + s[b] + s[c]);
                }
            }
        }
        printf("%d\n", ans);
    }
}
/*
4 6
100
5000
1000
2000
1 2
1 3
1 4
2 3
2 4
3 4
6 8
1500
1000
100
2000
500
300
1 2
1 3
1 4
2 4
3 5
4 5
4 6
5 6
*/

