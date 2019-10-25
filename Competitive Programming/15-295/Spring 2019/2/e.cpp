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
map<int, int> dp;
int n;
int a[200005];
int main(){
    cin >> n;
    FOR(i, 0, n){
        scanf("%d", &a[i]);
    }
    int ans = 0;
    int last = -1;
    FOR(i, 0, n){
        int x = dp[a[i]];
        dp[a[i]] = max(x, dp[a[i] - 1] + 1);
        if (dp[a[i]] > ans){
            ans = dp[a[i]];
            last = a[i];
        }
    }
    int x = last - ans + 1;
    cout << ans << endl;
    FOR(i, 0, n){
        if (a[i] == x){
            printf("%d ", i + 1);
            x++;
        }
    }
    cout << endl;

}

