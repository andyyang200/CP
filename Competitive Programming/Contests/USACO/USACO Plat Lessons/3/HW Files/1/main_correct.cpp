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

int a[100005];
ll dp[100005];

int main() {
    int n, h;
    scanf("%d%d", &n, &h);
    FOR(i, 0, n) {
        scanf("%d", &a[i]);
    }
    dp[n - 1] = 1;
    RFOR(i, n - 2, -1) {
        for(int j = i + a[i]; j < n; j += a[i]) {
            dp[i] += dp[j];
            dp[i] %= M;
            if (a[j] == a[i]) break;
        }
        if (i == 0 && a[0] != h) {
            for(int j = i + h; j < n; j += h) {
                dp[i] += dp[j];
                dp[i] %= M;
                if (a[j] == h) break;
            }
        }
    }
    cout << dp[0] << endl;
}



