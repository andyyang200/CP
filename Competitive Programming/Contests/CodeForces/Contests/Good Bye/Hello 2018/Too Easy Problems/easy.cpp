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
struct problem {
	int a, t, i;
};
bool f1(problem a, problem b) {
	return a.a < b.a;
}
bool f2(problem a, problem b) {
	return a.t < b.t;
}
problem bya[200005];
problem byt[200005];
int t[200005];
int tindex[200005];
int main(void)
{
	int n;
	int T;
	scanf("%d%d", &n, &T);
	FOR(i, 0, n) {
		scanf("%d%d", &bya[i].a, &bya[i].t);
		bya[i].i = i;
		byt[i] = bya[i];
		t[i] = bya[i].t;
	}
	sort(bya, bya + n, f1);
	sort(byt, byt + n, f2);
	FOR(i, 0, n) {
		tindex[byt[i].i] = i;
	}
	int cnt = 0;
	int r = -1;
	int sum = 0;
	int ans = 0;
	FOR(i, 0, n) {
		int solve = bya[i].a;
		while (r < n - 1 && (byt[r + 1].t == 0 || (cnt < solve && sum + byt[r + 1].t <= T))) {
			r++;
			if (byt[r].t != 0) {
				cnt++;
				sum += byt[r].t;
			}
		}
		ans = max(ans, cnt);
		FOR(j, i, n + 1) {
			if (j == n || bya[j].a != bya[i].a) {
				i = j - 1;
				break;
			}
			int ind = tindex[bya[j].i];
			if (ind <= r) {	
				cnt--;
				sum -= byt[ind].t;
			}
			byt[ind].t = 0;
		}
	}
	FOR(i, 0, n) {
		byt[i].t = t[byt[i].i];
	}	
	cnt = 0;
	r = -1;
	sum = 0;
	int ans2 = 0;
	FOR(i, 0, n) {
		int solve = bya[i].a;
		while (r < n - 1 && (byt[r + 1].t == 0 || (cnt < solve && sum + byt[r + 1].t <= T))) {
			r++;
			if (byt[r].t != 0) {
				cnt++;
				sum += byt[r].t;
			}
		}
		ans2 = max(ans2, cnt);
		if (ans2 == ans) {
			cout << ans2 << endl;
			vector<int> v;
			FOR(i, 0, r + 1) {
				if (byt[i].t != 0) {
					v.push_back(byt[i].i);
				}
			}
			sort(v.begin(), v.end());
			cout << v.size() << endl;
			for (int x : v) {
				cout << x + 1 << " ";
			}
			cout << endl;
			return 0;
		}
		FOR(j, i, n + 1) {
			if (j == n || bya[j].a != bya[i].a) {
				i = j - 1;
				break;
			}
			int ind = tindex[bya[j].i];
			if (ind <= r) {
				cnt--;
				sum -= byt[ind].t;
			}
			byt[ind].t = 0;
		}
	}
}