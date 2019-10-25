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
	int n, m, k;
	cin >> n >> k >> m;
	vector<int> below;
	vector<int> above;
	if (k == ( 1 << n ) && n != m){
		cout << -1 << endl;
		return 0;
	}
	FOR(i, 1, (1 << n) + 1) {
		if (i < k) {
			below.push_back(i);
		}
		if (i > k) {
			above.push_back(i);
		}
	}
	sort(above.begin(), above.end());
	int needed = 1 << m;
	if (needed - 1 > below.size()) {
		cout << -1 << endl;
		return 0;
	}
	cout << k << " ";
	FOR(i, 0, needed - 1) {
		cout << below.back() << " ";
		below.pop_back();
	}
	while (above.size()) {
		cout << above.back() << " ";
		above.pop_back();
	}
	while (below.size()) {
		cout << below.back() << " ";
		below.pop_back();
	}
	cout << endl;
}