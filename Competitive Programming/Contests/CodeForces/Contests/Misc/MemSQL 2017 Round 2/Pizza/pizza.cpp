//Andrew Yang
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <fstream>
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
struct person {
	ll s, a, b;
	ll x;
	bool operator<(const person& other) const {
		if (b - a == other.b - other.a) return s < other.s;
		return b - a < other.b - other.a;
	}
};
person a[100005];
int main(void)
{
	ll N, S;
	cin >> N >> S;
	ll totalSlices = 0;
	FOR(i, 0, N) {
		person p;
		scanf("%lld%lld%lld", &p.s, &p.a, &p.b);
		a[i] = p;
		totalSlices += p.s;
	}
	sort(a, a + N);
	ll ans = 0;
	ll ret = 0;
	FOR(i, 0, N) {
		ans += (ll)a[i].s * a[i].a; 
		a[i].x = a[i].s;
		ret = max(ret, ans);
	}
	bool first = true;
	for (ll i = N - 1; i >= 0;) {
		if (a[i].a >= a[i].b) {
			break;
		}
		ll slices;
		if (first) {
			slices = totalSlices % S;
			first = false;
		}
		else {
			slices = max(S, (a[i].x / S) * S);
		}
		ll j = i;
		while (slices > 0) {
			ll d = min(slices, a[j].x);
			ans += (ll)d * (a[j].b - a[j].a);
			slices -= d;
			a[j].x -= d;
			if (a[j].x == 0) {
				j--;
			}
		}
		i = j;
		ret = max(ans, ret);
	}

	reverse(a, a + N);
	ans = 0;
	FOR(i, 0, N) {
		ans += (ll)a[i].s * a[i].b;
		a[i].x = a[i].s;
		ret = max(ret, ans);
	}
	first = true;
	for (ll i = N - 1; i >= 0;) {
		if (a[i].b >= a[i].a) {
			break;
		}
		ll slices;
		if (first) {
			slices = totalSlices % S;
			first = false;
		}
		else {
			slices = max(S, (a[i].x / S) * S);
		}
		ll j = i;
		while (slices > 0) {
			int d = min(slices, a[j].x);
			ans += (ll)d * (a[j].a - a[j].b);
			slices -= d;
			a[j].x -= d;
			if (a[j].x == 0) {
				j--;
			}
		}
		i = j;
		ret = max(ans, ret);
	}
	cout << ret << endl;
}