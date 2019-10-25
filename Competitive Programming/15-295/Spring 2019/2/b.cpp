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


//---------------------------------------------------------------------------------------------------------------
int c[1005];
int dp[100006];
int main(){
    int v, m;
    cin >> v >> m;
    FOR(i, 0, m){
        cin >> c[i];
    }
    dp[0] = 0;
    FOR(i, 1, v + 1){
        dp[i] = INF;
        FOR(j, 0, m){
            if (i - c[j] >= 0){
                dp[i] = min(dp[i], dp[i - c[j]] + 1);
            }
        }
    }
    cout << dp[v] << endl;
}


