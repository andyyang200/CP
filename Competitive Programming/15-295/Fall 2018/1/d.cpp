#include <bits/stdc++.h>
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

//---------------------------------------------------------------------------------------------------------------
vector<pair<int, ld>> edges[801];
ld dp[801][801];
int main(){
    auto start = clock();
    int n, m;
    cin >> n >> m;
    FOR(i, 0, m) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        ld c;
        cin >> c;
        edges[a].push_back({b, log(c)});
    }
    ld limit = log(1.1);
    RFOR(i, n - 1, -1) {
        FOR(x, 0, n) {
            FOR(y, 0, n){
                dp[x][y] = -INF;
            }
        }
        dp[i][0] = 0;
        FOR(k, 0, n) {
            FOR(j, 0, n) {
                for(auto p: edges[j]) {
                    dp[p.first][k + 1] = max(dp[p.first][k + 1], dp[j][k] + p.second);
                }
            }
            if (dp[i][k + 1] >= limit) {
                cout << "inadmissible" << endl;
                return 0;
            }
        }
        ld duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
        if (duration >= 7.9){
            cout << "admissible" << endl;
            return 0;
        }
    }
    cout << "admissible" << endl;
}
/*
2 2
1 2 0.5
2 1 2.3


2 2
1 2 0.5
2 1 0.7

*/
