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
#define M 998244353
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------
ll dp[100001][105];
ll dpsum[100001];
int n, k, len;
int a[100001];
int bad[100005][101];
int main(){
    scanf("%d%d%d", &n, &k, &len);
    FOR(i, 0, n){
        scanf("%d", &a[i]);
    }
    if (len == 1){
        cout << 0 << endl;
        return 0;
    }
    map<int, int> cnt;
    FOR(i, 0, len){
        cnt[a[i]]++;
    }
    FOR(i, len - 1, n){
        FOR(j, 1, k + 1){
            if (cnt[-1] + cnt[j] == len){
                bad[i][j] = 1;
            }
        }
        if (i + 1 < n)
            cnt[a[i + 1]]++;
        cnt[a[i - len + 1]]--;
    }
    FOR(j, 1, k + 1){
        if (a[0] == -1 || a[0] == j){
            dp[0][j] = 1;
        }
        else{
            dp[0][j] = 0;
        }
        dpsum[0] += dp[0][j];
    }
    FOR(i, 1, n){
        FOR(j, 1, k + 1){
            if (a[i] != -1 && a[i] != j){
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = dpsum[i - 1];
            if (bad[i][j]){
                dp[i][j] -= (i - len >= 0 ? dpsum[i - len] - dp[i - len][j] : 1);
                while(dp[i][j] < 0)
                    dp[i][j] += M;
                dp[i][j] %= M;
            }
            dpsum[i] += dp[i][j];
            dpsum[i] %= M;
        }
    }
    cout << dpsum[n - 1] << endl;
}


