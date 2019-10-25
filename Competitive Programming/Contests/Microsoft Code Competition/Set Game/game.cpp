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
int a[1005];
int main(void)
{
	freopen("pipeline.in", "r", stdin);
	freopen("pipeline.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	if (m == 1) {
		cout << 1 << endl;
		return 0;
	}
	vector<int> v;
	FOR(i, 0, n) {
		int x;
		scanf("%d", &x);
		v.push_back(x);
	}
	/*while (true) {
	bool change = false;
	FOR(i, 0, (int)v.size() - 2) {
	if (v[i] + v[i + 1] <= v[i + 2]) {
	v[i] += v[i + 1];
	v.erase(v.begin() + i + 1);
	change = true;
	break;
	}
	}
	FOR(i, 1, (int)v.size() - 1) {
	if (v[i] + v[i + 1] <= v[i - 1]) {
	v[i] += v[i + 1];
	v.erase(v.begin() + i + 1);
	change = true;
	break;
	}
	}
	if (!change) break;
	}*/
	RFOR(d - 1, n - 1, -1) {
		int j = d - 1;
		int sum = 0;
		FOR(i, 0, j + 1) sum += v[i];
		FOR(i, 0, n) {

		}
	}
	cout << v.size() << endl;

}