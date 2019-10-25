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
int a[100005];
int x[100005];
string s[100005];
int main(void)
{
	freopen("bureau.in", "r", stdin);
	freopen("bureau.out", "w", stdout);
	int n;
	cin >> n;
	FOR(i, 0, n) {
		a[i] = 1;
	}
	FOR(i, 0, n) {
		cin >> s[i];
		if (s[i] == "cancel") {
			cin >> x[i];
			x[i]--;
		}
	}
	RFOR(i, n - 1, -1) {
		if (a[i]) {
			if (s[i] == "cancel") {
				a[x[i]] = 0;
			}
		}
	}
	vector<int> ans;
	FOR(i, 0, n) {
		if (a[i]) {
			ans.push_back(i + 1);
		}
	}
	cout << ans.size() << endl;
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;
}
/*
5
declare
cancel 1
declare
cancel 2
cancel 3

*/