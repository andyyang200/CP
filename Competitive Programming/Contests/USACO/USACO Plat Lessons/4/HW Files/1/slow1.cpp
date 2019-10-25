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

bool dp[5001][5001];

int main(){

    string s;
    cin >> s;
    int n = s.length();
    FOR(i, 0, n){
        dp[i][i] = true;
    }
    FOR(i, 0, n - 1){
        if (s[i] == s[i + 1]){
            dp[i][i + 1] = true;
        }
    }
    FOR(d, 2, n + 1){
        FOR(i, 0, n){
            int j = i + d;
            if (j >= n) break;
            if (s[i] == s[j]){
                dp[i][j] = dp[i + 1][j - 1];
            }
        }
    }
    int ans = 0;
    FOR(i, 0, n){
        FOR(j, i, n){
            if (dp[i][j]){
                ans = max(ans, j - i + 1);
            }
        }
    }
    cout << ans << endl;
}
