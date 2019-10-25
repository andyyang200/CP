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
vector<int> children[1005];
int leaves[1005];
int main(void)
{
	int n;
	cin >> n;
	FOR(i, 2, n + 1) {
		int p;
		cin >> p;
		children[p].push_back(i);
	}
	FOR(i, 1, n + 1) {
		for (int x : children[i]) {
			if (children[x].size() == 0) {
				leaves[i]++;
			}
		}
	}
	FOR(i, 1, n + 1) {
		int x = children[i].size();
		if (x > 0 && leaves[i] < 3) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}