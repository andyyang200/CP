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
ll dp[100005][2];
int a[100005];
int b[100005];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &b[i]);
    }
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    for(int i = 1; i < n; i++){
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + a[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + b[i]);
    }
    ll ans = max(dp[n - 1][0], dp[n - 1][1]);
    cout << ans << endl;
}
