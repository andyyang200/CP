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

ll dp[100005];
int pmax[100005];
int a[100005];
int main() {
    int n;
    scanf("%d", &n);
    FOR(i, 0, n)
        scanf("%d", &a[i]);
    pmax[0] = a[0];
    FOR(i, 1, n){
        pmax[i] = max(pmax[i - 1], a[i]);
    }
    FOR(i, 0, n){
        dp[i] = 1;
        int curmax = a[i];
        RFOR(j, i - 1, -1){
            if (curmax >= pmax[j]){
                dp[i] += dp[j];
                dp[i] %= M;
            }
            curmax = max(curmax, a[j]);
        }
    }
    cout << dp[n - 1] << endl;
}
