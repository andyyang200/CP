#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", z = " << z << endl
#define INF 3000000000000000000LL
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int r, b, c;
int m[1005], s[1005], p[1005];

bool check(ll mid){ // is there solution with at most mid seconds
    vector<ll> bits;
    FOR(i, 0, c){
        ll x = (mid - p[i]) / s[i];
        x = max(x, 0LL);
        x = min(x, (ll)m[i]);
        bits.push_back(x);
    }
    sort(bits.begin(), bits.end());
    reverse(bits.begin(), bits.end());
    ll x = 0;
    FOR(i, 0, r){
        x += bits[i];
    }
    return x >= b;
}

int main(void)
{
    int tests;
    scanf("%d", &tests);
    FOR(test, 1, tests + 1){
        scanf("%d%d%d", &r, &b, &c);
        FOR(i, 0, c){
            scanf("%d%d%d", &m[i], &s[i], &p[i]);
        }
        ll l = 0;
        ll r = INF;
        ll ans = -1;
        while(l <= r){
            ll mid = (l + r) / 2;
            if (check(mid)){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        printf("Case #%d: ", test);
        cout << ans << endl;
    }
}


