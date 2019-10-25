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
/*You have a laser at (0, 0) pointing north. There are N mirrors in the plane, each one either / or \.
You want to add 1 mirror and direct the laser to point (x, y). How many different locations can this mirror be added?
It is guaranteed that the laser does not hit the barn without an additional mirror.
X and Y values don't exceed 10^9 in absolute value.
N <= 100000
*/













#define MAXN (1 << 17)
#define MAXVAL 1000000000

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

map<int, vector<pair<int, char> > > objx;
map<int, vector<pair<int, char> > > objy;

pair<pair<int, int>, char> getnext(int x, int y, int dir) {
	bool vmove = dir % 2 == 0;
	int a = vmove ? x : y;
	int b = vmove ? y : x;
	int db = vmove ? dy[dir] : dx[dir];
	vector<pair<int, char> >& objs = (vmove ? objx : objy)[a];

	int id = lower_bound(objs.begin(), objs.end(), make_pair(b, (char)0))
		- objs.begin();

	id += db;
	char ch = '?';
	if (id < 0) {
		b = -(MAXVAL + 1);
	}
	else if (id == objs.size()) {
		b = MAXVAL + 1;
	}
	else {
		b = objs[id].first;
		ch = objs[id].second;
	}
	return make_pair(vmove ? make_pair(a, b) : make_pair(b, a), ch);
}

vector<pair<int, int> > getpath(int x, int y, int dir) {
	pair<int, int> pos(x, y);
	vector<pair<int, int> > path(1, pos);
	for (;;) {
		pair<pair<int, int>, char> res = getnext(pos.first, pos.second,
			dir);
		pos = res.first;
		path.push_back(pos);

		if (res.second == '/') {
			dir = (dir + (dir % 2 != 0 ? 3 : 1)) % 4;
		}
		else if (res.second == '\\') {
			dir = (dir + (dir % 2 == 0 ? 3 : 1)) % 4;
		}
		else {
			break;
		}
	}
	return path;
}

vector<pair<int, pair<int, int> > >
getverts(vector<pair<int, int> >& path) {
	vector<pair<int, pair<int, int> > > ret;
	for (int i = 0; i + 1 < path.size(); i++) {
		if (path[i].first == path[i + 1].first) {
			ret.push_back(make_pair(path[i].first,
				make_pair(path[i].second, path[i + 1].second)));
			if (ret.back().second.second < ret.back().second.first) {
				swap(ret.back().second.first, ret.back().second.second);
			}
		}
	}
	return ret;
}

vector<pair<int, pair<int, int> > >
gethorz(vector<pair<int, int> >& path) {
	vector<pair<int, pair<int, int> > > ret;
	for (int i = 0; i + 1 < path.size(); i++) {
		if (path[i].second == path[i + 1].second) {
			ret.push_back(make_pair(path[i].second,
				make_pair(path[i].first, path[i + 1].first)));
			if (ret.back().second.second < ret.back().second.first) {
				swap(ret.back().second.first, ret.back().second.second);
			}
		}
	}
	return ret;
}

int BT[MAXN];

/* Logically executes array[x] += v. */
void bit_add(int x, int v) {
	for (int i = x | MAXN; i < (MAXN << 1); i += i & -i) {
		BT[i ^ MAXN] += v;
	}
}

/* Returns the sum of array[i] for 0 <= i < x */
int bit_get(int x) {
	int ret = 0;
	for (int i = x - 1; x != 0; i &= i - 1) {
		ret += BT[i];
		if (!i) break;
	}
	return ret;
}

int countints(vector<pair<int, pair<int, int> > > vs,
	vector<pair<int, pair<int, int> > > hs) {
	/* Start with a coordinate compression of y values. */
	vector<int> ys;
	for (int i = 0; i < vs.size(); i++) {
		ys.push_back(vs[i].second.first);
		ys.push_back(vs[i].second.second);
	}
	for (int i = 0; i < hs.size(); i++) {
		ys.push_back(hs[i].first);
	}
	sort(ys.begin(), ys.end());
	ys.resize(unique(ys.begin(), ys.end()) - ys.begin());
	for (int i = 0; i < vs.size(); i++) {
		vs[i].second.first = lower_bound(ys.begin(), ys.end(),
			vs[i].second.first) - ys.begin();
		vs[i].second.second = lower_bound(ys.begin(), ys.end(),
			vs[i].second.second) - ys.begin();
	}
	for (int i = 0; i < hs.size(); i++) {
		hs[i].first = lower_bound(ys.begin(), ys.end(), hs[i].first) - ys.begin();
	}

	/* Sort vertical intervals by x, create event list. */
	sort(vs.begin(), vs.end());
	vector<pair<pair<int, int>, int> > events;
	for (int i = 0; i < hs.size(); i++) {
		events.push_back(make_pair(make_pair(hs[i].second.first, hs[i].first), 1));
		events.push_back(make_pair(make_pair(hs[i].second.second,
			hs[i].first), -1));
	}
	sort(events.begin(), events.end());

	/* Finally, count the intersections using a Fenwick tree. */
	int result = 0;
	memset(BT, 0, sizeof(BT));
	for (int i = 0, j = 0; i < events.size(); i++) {
		int x = events[i].first.first;
		for (; j < vs.size() && vs[j].first < x; j++) {
			result += bit_get(vs[j].second.second) - bit_get(vs[j].second.first + 1);
		}
		bit_add(events[i].first.second, events[i].second);
	}
	return result;
}

int main() {
	freopen("optics.in", "r", stdin);
	freopen("optics.out", "w", stdout);

	int N, bx, by;
	cin >> N >> bx >> by;

	objx[0].push_back(make_pair(0, 'S'));
	objy[0].push_back(make_pair(0, 'S'));
	objx[bx].push_back(make_pair(by, 'B'));
	objy[by].push_back(make_pair(bx, 'B'));
	for (int i = 0; i < N; i++) {
		int x, y;
		string mr;
		cin >> x >> y >> mr;

		objx[x].push_back(make_pair(y, mr[0]));
		objy[y].push_back(make_pair(x, mr[0]));
	}
	for (map<int, vector<pair<int, char> > >::iterator it =
		objx.begin();
		it != objx.end(); ++it) {
		sort(it->second.begin(), it->second.end());
	}
	for (map<int, vector<pair<int, char> > >::iterator it =
		objy.begin();
		it != objy.end(); ++it) {
		sort(it->second.begin(), it->second.end());
	}

	int result = 0;
	vector<pair<int, int> > plaser = getpath(0, 0, 0);
	for (int i = 0; i < 4; i++) {
		vector<pair<int, int> > pbarn = getpath(bx, by, i);

		int res = countints(getverts(plaser), gethorz(pbarn)) +
			countints(getverts(pbarn), gethorz(plaser));
		if (pbarn[0] == pbarn.back()) {
			result += res;
		}
		else {
			result += 2 * res;
		}
	}
	cout << result / 2 << endl;

	return 0;
}