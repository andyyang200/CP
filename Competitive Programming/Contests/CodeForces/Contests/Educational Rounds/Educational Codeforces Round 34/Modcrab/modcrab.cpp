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
	int h1, a1, c1, h2, a2;
	cin >> h1 >> a1 >> c1 >> h2 >> a2;
	vector<string> v;
	while (h2 > 0) {
		if (h1 <= a2 && a1 < h2) {
			v.push_back("HEAL");
			h1 += c1;
		}
		else {
			v.push_back("STRIKE");
			h2 -= a1;
			if (h2 <= 0) break;
		}
		h1 -= a2;
	}
	cout << v.size() << endl;
	for (string x : v) {
		cout << x << endl;
	}
}