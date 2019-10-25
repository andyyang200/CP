#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b)  qfor(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define ri(x) scanf("%d", &x)
#define ri2(x, y) scanf("%d%d", &x, &y)
#define ri3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define rll(x) scanf("%lld", &x)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------
int n, S;
int a[100005];
ll cost[100005];
ll calc(int k){
    FOR(i, 0, n){
        cost[i] = a[i] + (ll)k * (i + 1);
    }
    sort(cost, cost + n);
    ll tot = 0;
    FOR(i, 0, k){
        tot += cost[i];
    }
    return tot;
}
int main(){
    ri2(n, S);
    FOR(i, 0, n){
        ri(a[i]);
    }
    int l = 0;
    int r = n;
    int ans = -1;
    ll cost = -1;
    while(l <= r){
        int m = (l + r) / 2;
        ll x = calc(m);
        if (x <= S){
            ans = m;
            cost = x;
            l = m + 1;
        }
        else{
            r = m - 1;
        }
    }
    cout << ans << " " << cost << endl;
}
