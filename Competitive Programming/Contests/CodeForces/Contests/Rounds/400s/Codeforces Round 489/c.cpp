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
ll powmod(ll a, ll p, ll m) {
    ll ans = 1;
    while(p) {
        if(p % 2 == 1){
            ans *= a;
            ans %= m;
            p--;
        }
        a *= a;
        a %= m;
        p /= 2;
    }
    return ans % m;
}
int main(void)
{
    ll x, k;
    cin >> x >> k;
    if (x == 0){
        cout << 0 << endl;
        return 0;
    }
    x %= M;
    cout << (powmod(2, k + 1, M) * x % M - (powmod(2, k, M) - 1) + M) % M;
}


