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
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------

int n, M;
pii a[100005];

bool check(int x){ // can i do it in x days?
    ll tot = 0;
    FOR(i, 0 , n){
        ll v = (ll)x * a[i].second - a[i].first;
        if (v > 0){
            tot += v;
            if (tot >= M) return true;
        }
    }
    return tot >= M;
}

int main(){
    ri2(n, M);
    FOR(i, 0, n){
        ri2(a[i].second, a[i].first);
    }
    ll profit = 0;
    ll dailyprofit = 0;
    ll days = 1000000000;
    FOR(i, 0, n){
        profit += days * a[i].second - a[i].first;
        dailyprofit += a[i].second;
    }
    if (profit <= M){
        M -= profit;
        days += ((ll)M + dailyprofit - 1) / (dailyprofit);
        cout << days << endl;
        return 0;
    }
    ll l = 1;
    ll r = 1000000000;
    ll ans = -1;
    while(l <= r){
        ll m = (l + r) / 2;
        if (check(m)){
            ans = m;
            r = m - 1;
        }
        else{
            l = m + 1;
        }
    }
    cout << ans << endl;

}
