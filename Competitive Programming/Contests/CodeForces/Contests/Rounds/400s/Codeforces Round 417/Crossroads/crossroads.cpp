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
int l[4];
int s[4];
int r[4];
int p[4];
int main(void)
{
	FOR(i, 0, 4) {
		scanf("%d%d%d%d", &l[i], &s[i], &r[i], &p[i]);
	}
	FOR(i, 0, 4) {
		if (p[i]) {
			if (s[i] || l[i] || r[i]) {
				cout << "YES" << endl;
				return 0;
			}

		}
	}
	FOR(i, 0, 4) {
		if (p[i] && l[(i + 1) % 4]) {
			cout << "YES" << endl;
			return 0;
		}
	}
	FOR(i, 0, 4) {
		if (p[i] && r[(i - 1 + 4) % 4]) {
			cout << "YES" << endl;
			return 0;
		}
	}
	FOR(i, 0, 4) {
		if (p[i] && s[(i + 2) % 4]) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}