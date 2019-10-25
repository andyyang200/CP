#include<bits/stdc++.h>

using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;

// returns a^p mod m
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

ll gcd(ll a, ll b) {
	while (b) {
		a = a % b;
		swap(a, b);
	}
	return a;
}

// For a, b >= 0, a + b > 0
// Returns x, y such that ax + by = gcd(a, b)
// Furthermore if (a, 0) -> (1, 0); (0, b) -> (0, 1); (a, b) -> |x| <= b, |y| <= a
pair<ll, ll> euclid(ll a, ll b) {
	if (!b) return {1, 0};
	ll x, y;
	tie(x, y) = euclid(b, a % b);
	return {y, x - y * (a / b)};
}
// Returns 0 <= x < m such that a * x = 1 mod m
ll getModInverse(ll a, ll m) {
	//assert(a > 0 && m > 0 && __gcd(a, m) == 1);
	auto v = euclid(a, m);
	if (v.first < 0) v.first += m;
	if (v.first >= m) v.first -= m;
	return v.first;
}
#define MAX 200005
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




mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getrand(int n) { // [0, n)
    return uniform_int_distribution<int>(0, n - 1)(rng);
}
int getrand(int a, int b){ // [a, b]
    return uniform_int_distribution<int>(a, b)(rng);
}

int main(void)
{
    cout << uniform_int_distribution<int>(0, 200000)(rng) << endl;
}
