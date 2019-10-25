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
#include <cassert>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
struct update {
	ll time, enemy, health;
	bool operator<(const update o) const {
		return time < o.time;
	}
};
ll maxHealth[100005];
ll startHealth[100005];
ll regen[100005];
update u[100005];
ll change[100005];
ll changeindex[100005];
bool in[100005];
ll n, m;
ll bounty, damage, increase;

int main(void)
{
	scanf("%lld%lld", &n, &m);
	scanf("%lld%lld%lld", &bounty, &increase, &damage);
	FOR(i, 0, n) {
		scanf("%lld%lld%lld", &maxHealth[i], &startHealth[i], &regen[i]);
		if (maxHealth[i] <= damage) {
			cout << -1 << endl;
			return 0;
		}
	}
	FOR(i, 0, m) {
		scanf("%lld%lld%lld", &u[i].time, &u[i].enemy, &u[i].health);
		u[i].enemy--;
	}
	sort(u, u + m);
	ll cnt = 0;
	multiset<pair<ll, ll>> st;
	FOR(i, 0, n) {
		if (startHealth[i] <= damage) {
			cnt++;
			in[i] = true;
			if (maxHealth[i] > damage && regen[i] > 0) {
				ll t = ((ll)damage - startHealth[i]) / regen[i];
				st.insert({ t , i});
			}
		}
	}
	ll ans = bounty * cnt;
	FOR(i, 0, m) {
		while (!st.empty() && st.begin()->first <= u[i].time) {
			if (in[st.begin()->second]) {
				ans = max(ans, (ll)cnt * (bounty + (ll)increase * (st.begin()->first)));
				cnt--;
				in[st.begin()->second] = false;
			}
			st.erase(st.begin());
		}
		FOR(j, i, m) {
			if (u[j].time != u[i].time) {
				i = j - 1;
				break;
			}
			if (!in[u[j].enemy] && u[j].health <= damage) {
				cnt++;
				in[u[j].enemy] = true;
				if (maxHealth[u[j].enemy] > damage && regen[u[j].enemy] > 0) {
					ll t = u[j].time + (ll)(damage - u[j].health) / regen[u[j].enemy];
					st.insert({ t , u[j].enemy });
				}
			}
			if (in[u[j].enemy] && u[j].health > damage) {
				ans = max(ans, (ll)cnt * (bounty + (ll)increase * (u[j].time - 1)));
				cnt--;
				in[u[j].enemy] = false;
			}
		}	
	}
	while (!st.empty()) {
		if (in[st.begin()->second]) {
			ans = max(ans, (ll)cnt * (bounty + (ll)increase * (st.begin()->first)));
			cnt--;
			in[st.begin()->second] = false;
		}
		st.erase(st.begin());
	}
	cout << ans << endl;
}