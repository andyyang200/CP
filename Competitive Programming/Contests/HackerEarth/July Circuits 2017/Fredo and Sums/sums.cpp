//Andrew Yang
//Accepted
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
	int t;
	scanf("%d", &t);
	FOR(asd, 0, t) {
		int n;
		scanf("%d", &n);
		vector<int> v(n);
		FOR(i, 0, n) {
			scanf("%d", &v[i]);
		}
		sort(v.begin(), v.end());
		ll min = 0;
		ll m = 0;
		for (int i = 0; i < v.size(); i += 2) {
			min += v[i + 1] - v[i];
		}
		for (int i = 0; i < v.size() / 2; i++) {
			m += v[v.size() - 1 - i] - v[i];
		}
		cout << min << " " << m << endl;
	}
}
/*
1
8
0 -50 234 81 -914 8 1302 11
*/