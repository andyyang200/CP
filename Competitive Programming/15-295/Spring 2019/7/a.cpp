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
ll fact[1000005];
ll invfact[1000005];
int a, b, n;
ll c(int x, int y){ // x choose y
    return fact[x] * invfact[y] % M * invfact[x - y] % M;
}
bool isGood(int x){
    string s = to_string(x);
    FOR(i, 0, s.length()){
        if (s[i] != (a + '0') && s[i] != (b + '0')){
            return false;
        }
    }
    return true;
}
int main(){
    cin >> a >> b >> n;
    fact[0] = 1;
    FOR(i, 1, n + 1){
        fact[i] = fact[i - 1] * i % M;
    }
    FOR(i, 0, n + 1){
        invfact[i] = getModInverse(fact[i], M);
    }
    ll ans = 0;
    FOR(i, 0, n + 1){
        int sum = a * i + (n - i) * b;
        if (isGood(sum)){
            ans += c(n, i);
            ans %= M;
        }
    }
    cout << ans << endl;
}

