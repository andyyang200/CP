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
int c[501];
int dp[501][501];
int main(){
    int n;
    cin >> n;
    FOR(i, 0, n) {
        scanf("%d", &c[i]);
    }
    FOR(i, 0, n) dp[i][i] = 1;
    FOR(i, 0, n - 1) {
        if (c[i] == c[i + 1]){
            dp[i][i + 1] = 1;
        }
        else{
            dp[i][i + 1] = 2;
        }
    }
    FOR(d, 2, n) {
        FOR(i, 0, n) {
            int j = i + d;
            if (j >= n) break;
            dp[i][j] = INF;
            if (c[i] == c[j]) {
                dp[i][j] = dp[i + 1][j - 1];
            }
            FOR(k, i, j) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
        }
    }
    cout << dp[0][n - 1] << endl;
}

