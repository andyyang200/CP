//Andrew Yang
#define _CRT_SECURE_NO_WARNINGS
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
int a[200001];
bool iss[200001];
int main(void)
{
	int n;
	cin >> n;
	int s = 0;
	int nots = 0;
	FOR(i, 0, n) {
		scanf("%d", &a[i]);
		int y = sqrt(a[i]);
		iss[i] = (y * y == a[i]);
		if (iss[i]) {
			s++;
		}
		else {
			nots++;
		}
	}
	if (s == nots) {
		cout << 0 << endl;
		return 0;
	}
	if (s > nots) {
		vector<int> v;
		FOR(i, 0, n) {
			if (iss[i]) {
				v.push_back(a[i]);
			}
		}
		sort(v.begin(), v.end());
		ll ans = 0;
		RFOR(i, v.size() - 1, -1) {
			if (v[i] == 0) {
				ans += 2;
			}
			else {
				ans++;
			}
			s--;
			nots++;
			if (s == nots) {
				break;
			}
		}
		cout << ans << endl;
		return 0;
	}
	if (nots > s) {
		vector<int> v;
		FOR(i, 0, n) {
			if (!iss[i]) {
				int y = sqrt(a[i]);
				int x = min(abs(a[i] - y * y), abs(a[i] - (y + 1) * (y + 1)));
				v.push_back(x);
			}
		}
		sort(v.begin(), v.end());
		ll ans = 0;
		FOR(i, 0, v.size()) {
			ans += v[i];
			nots--;
			s++;
			if (s == nots) {
				break;
			}
		}
		cout << ans << endl;
		return 0;
	}
}