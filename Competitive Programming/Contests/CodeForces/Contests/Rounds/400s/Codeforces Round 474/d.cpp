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


ll shift[100];
ll pow2[100];
int level(ll node) {
	int ans = 1;
	while (node != 1) {
		ans++;
		node /= 2;
	}
	return ans;
}
ll nodes(int level) { // also first node in row
	return pow2[level - 1];
}
ll value(ll index) {
	int l = level(index);
	ll n = nodes(l);
	ll ret = index - shift[l];
	if (ret < n) ret += n;
	if (ret >= 2 * n) ret -= n;
	return ret;
}
ll getindex(ll x) {
	int l = level(x);
	ll n = nodes(l);
	ll ret = x;
	ret += shift[l];
	if (ret < n) ret += n;
	if (ret >= 2 * n) ret -= n;
	return ret;
}
int main(void)
{
	pow2[0] = 1;
	FOR(i, 1, 61) {
		pow2[i] = 2 * pow2[i - 1];
	}
	int Q;
	scanf("%d", &Q);
	FOR(q, 0, Q) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			ll x, k;
			scanf("%lld%lld", &x, &k);
			int l = level(x);
			ll n = nodes(l);
			k %= n;
			shift[l] += k;
			if (shift[l] < 0) shift[l] += n;
			shift[l] %= n;
		}
		else if (t == 2) {
			ll x, k;
			scanf("%lld%lld", &x, &k);
			int l = level(x);
			ll n = nodes(l);
			k %= n;
			ll pow = 1;
			FOR(i, l, 61) {
				shift[i] += (pow % n) * (k % n) % n;
				shift[i] %= n;
				pow *= 2;
				n *= 2;
			}
		}
		else {
			ll x;
			scanf("%lld", &x);
			ll y = getindex(x);
			while (y != 0) {
				printf("%lld ", value(y));
				y = y / 2;
			}
			cout << endl;
		}
	}
}
