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

int main(void)
{
	
	int n;
	cin >> n;
	ll sum = (ll)n * (n + 1) / 2;
	ll target = sum / 2;
	vector<int> ans;
	RFOR(i, n, -1) {
		if (i <= target) {
			target -= i;
			ans.push_back(i);
		}
		if (target == 0) break;
	}
	cout << abs((sum - sum / 2) - sum / 2) << endl;
	cout << ans.size() << " ";
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;
}