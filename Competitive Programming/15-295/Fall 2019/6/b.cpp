#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b)  qfor(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define ri(x) scanf("%d", &x)
#define rll(x) scanf("%lld", &x)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------
int n, m;
int adj[105][105];
int p[1000005];
int main(){
    ri(n);
    FOR(i, 0, n){
        FOR(j, 0, n){
            char c;
            cin >> c;
            adj[i][j] = c - '0';
        }
    }
    FOR(i, 0, n){
        FOR(j, 0, n){
            if (!adj[i][j]) adj[i][j] = INF;
            if (i == j){
                adj[i][j] = 0;
            }
        }
    }
    FOR(k, 0, n){
        FOR(i, 0, n){
            FOR(j, 0, n){
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    ri(m);
    FOR(i, 0, m){
        ri(p[i]);
        p[i]--;
    }
    vector<int> ans;
    FOR(i, 0, m){
        ans.push_back(p[i]);
        if (i == m - 1){
            break;
        }
        int bestj = -1;
        for(int j = i + 1; j < min(m, i + 101); j++){
            if (adj[p[i]][p[j]] == j - i){
                bestj = max(bestj, j);
            }
        }
        i = bestj - 1;
    }
    cout << ans.size() << endl;
    for(int x : ans){
        printf("%d ", x + 1);
    }
    printf("\n");
}
