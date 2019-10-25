#include <string>
#include <string.h>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>	
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <climits>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;

ll f[100005], invf[100005];
ll ipow(ll x, ll p) {
	ll ans = 1, r = x % M;
	while (p) {
		if (p & 1) ans *= r;
		r *= r;
		ans %= M;
		r %= M;
		p >>= 1;
	}
	return ans % M;
}
ll c(int x, int y) {
	if (x < y) {
		return 0;
	}
	return f[x] * (invf[y] * invf[x - y] % M) % M;
}
int main(void)
{
	f[0] = invf[0] = 1;
	FOR(i, 1, 100005) {
		f[i] = f[i - 1] * i % M;
		invf[i] = ipow(f[i], M - 2);
	}
}