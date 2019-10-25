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
/*
You have an array A of N integers. Print a set of elements with a sum in the range [L, R], or print -1
if such a set does not exist.
It is guaranteed that the difference between the largest and smallest element in A does not exceed (R - L).
N <= 200000
Ai <= 10^9
*/





ll p[200001];
ll getSum(int l, int r) {
	ll ans = p[r];
	if (l > 0) {
		ans -= p[l - 1];
	}
	return ans;
}
vector<int> find_subset(int l, int u, vector<int> w) {
	int n = w.size();
	vector<pii> v(n);
	FOR(i, 0, n) {
		v[i] = { w[i], i };
	}
	sort(v.begin(), v.end());
	p[0] = v[0].first;
	FOR(i, 1, n) {
		p[i] = (ll)v[i].first + p[i - 1];
	}
	FOR(k, 1, n + 1) {
		if (getSum(0, k - 1) <= u && getSum(n - k, n - 1) >= l) {
			FOR(i, 0, n) {
				int j = i + k - 1;
				if (j >= n) {
					break;
				}
				ll s = getSum(i, j);
				if (s >= l && s <= u) {
					vector<int> ans;
					FOR(x, i, j + 1) {
						ans.push_back(v[x].second);
					}
					return ans;
				}
			}
		}
	}
	return vector<int>();
}
//int main(void)
//{
//	vector<int> ans = find_subset(14, 15, {5, 5, 6, 6});
//
//	for (int x : ans) {
//		cout << x << endl;
//	}
//}