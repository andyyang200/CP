#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------

int par[MAXN][20];
void computeSparse() { // calculate par[i][0] first
   // dfs(0, 0, 0);
    FOR(j, 1, 19)
        FOR(i, 1, n){
            if (par[i][j - 1] == -1){
                par[i][j] = -1;
            }
            else{
                par[i][j] = par[par[i][j - 1]][j - 1];
            }
        }
}

int getLCA(int a, int b) {
    if (depth[a] > depth[b]){
        swap(a, b);
    }
    int lift = depth[b] - depth[a];
    for(int j = 19; j >= 0; j--){
        if (lift & (1 << j)){
            b = par[b][j];
        }
    }
    if (a == b){
        return a;
    }

    for(int j = 19; j >= 0; j--){
        if (par[a][j] != par[b][j]) {
            a = par[a][j];
            b = par[b][j];
        }
    }
    return par[a][0];
}
int main(){


}

