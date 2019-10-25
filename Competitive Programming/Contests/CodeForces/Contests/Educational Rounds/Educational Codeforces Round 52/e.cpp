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
pair<ll, ll> euclid(ll a, ll b) {
	if (!b) return {1, 0};
	ll x, y;
	tie(x, y) = euclid(b, a % b);
	return {y, x - y * (a / b)};
}
// Returns 0 <= x < m such that a * x = 1 mod m
ll getModInverse(ll a, ll m) {
	assert(a > 0 && m > 0 && __gcd(a, m) == 1);
	auto v = euclid(a, m);
	if (v.first < 0) v.first += m;
	if (v.first >= m) v.first -= m;
	return v.first;
}
ll powmod(ll a, ll p, ll m) {
    ll ans = 1;
    while(p) {
        if(p % 2 == 1){
            ans *= a;
            ans %= m;
        }
        a *= a;
        a %= m;
        p /= 2;
    }
    return ans % m;
}
int b[200005];
ll overcountSum[200005];
int main(){
    int n, m, A;
    scanf("%d%d%d", &n, &m, &A);
    FOR(i, 1, m + 1){
        scanf("%d", &b[i]);
    }
    FOR(i, 1, m + 1){
        int d = b[i] - b[i - 1];
        ll p = powmod(A, b[m], M) * powmod(A, b[m] - d, M) % M;
        p -= overcountSum[i - 1];
        p = (p + M) % M;
        overcountSum[i] = overcountSum[i - 1];
        overcountSum[i] += p;
        overcountSum[i] %= M;
    }
    ll tot = overcountSum[m];
    tot = tot * powmod(A, n - 2 * b[m], M) % M;
    tot = tot * getModInverse(2, M) % M;
    ll total = powmod(A, n, M);
    ll ans = total - tot;
    ans = (ans + M) % M;
    cout << ans << endl;

}


