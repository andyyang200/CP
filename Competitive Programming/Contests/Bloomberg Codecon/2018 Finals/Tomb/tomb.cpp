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
int s[101];
int main(void)
{
	int n;
	cin >> n;
	int x;
	cin >> x;
	FOR(i, 0, x) {
		cin >> s[i];
		s[i]--;
	}
	int ret = INF;
	do {
		set<int> ss;
		ss.insert(-1);
		ss.insert(n);
		int ans = 0;
		FOR(i, 0, x) {
			auto itr2 = ss.lower_bound(s[i]);
			auto itr1 = itr2;
			itr1--;
			ans += *itr2 - *itr1 - 2;
			ss.insert(s[i]);
		}
		ret = min(ret, ans);

	} while (next_permutation(s, s + x));
	cout << ret << endl;
}