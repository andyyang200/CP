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
int a[200005];
int b[200005];
int dp[200005];
int main(void)
{
    int n;
    cin >> n;
    FOR(i, 0, n){
        scanf("%d", &a[i]);
    }
    FOR(i, 0, n){
        scanf("%d", &b[i]);
    }
    int ans = 0;
    FOR(i, 0, n){
        dp[i] = 1;
        FOR(j, 0, i){
            if (a[j] < a[i] && b[j] < b[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}


