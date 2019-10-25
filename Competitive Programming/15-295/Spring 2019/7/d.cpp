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
#define MAX 1000005
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
ll fact[2000005];
ll invfact[2000005];
ll c(int x, int y){ // x choose y
    return fact[x] * invfact[y] % M * invfact[x - y] % M;
}
int sieve[MAX];
void buildsieve(){
    FOR(i, 1, MAX){
        sieve[i] = i;
    }
    FOR(i, 2, MAX){
        if (sieve[i] != i){ // composite
            continue;
        }
        for(int j = 2 * i; j < MAX; j += i){ // prime
            sieve[j] = i;
        }
    }
}
buildfact(){
    fact[0] = 1;
    FOR(i, 1, MAX + 100){
        fact[i] = fact[i - 1] * i % M;
    }
    FOR(i, 0, MAX + 100){
        invfact[i] = getModInverse(fact[i], M);
    }
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
int main(){
    buildsieve();
    buildfact();
    int q;
    scanf("%d", &q);
    FOR(i, 0, q){
        int x, y;
        scanf("%d%d", &x, &y);
        ll ans = 1;
        while(x != 1){
            int p = sieve[x];
            int cntp = 0;
            while(x % p == 0){
                cntp++;
                x /= p;
            }
            ans = ans * c(y + cntp - 1, cntp) % M;
        }
        ans = ans * powmod(2, y - 1, M) % M;
        printf("%Ld\n", ans);
    }

}

