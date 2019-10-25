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

int main(void)
{
	string s;
	cin >> s;
	int n = s.length();
	vector<pii> ans;
	FOR(i, 0, n - 1) {
		int min = INF;
		int in = -1;
		FOR(j, i, n) {
			if ((int)s[j] < min) {
				min = (int)s[j];
				in = j;
			}
		}
		swap(s[i], s[in]);
		ans.push_back({ i + 1, in + 1 });
	}
	reverse(ans.begin(), ans.end());
	for (pii p : ans) {
		if (p.first == p.second) continue;
		cout << max(p.first, p.second) << " " << min(p.first, p.second) << endl;
	}
}