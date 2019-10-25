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

int p[105];

int main(void)
{
	double s;
	int q, k;
	cin >> s >> q >> k;
	FOR(i, 0, q) {
		cin >> p[i];
	}
	sort(p, p + q);
	FOR(i, 0, q) {
		if (s + k > s * (1.0 + (double)p[i] / 100)) {
			s += k;
		}
		else {
			s *= (1.0 + (double)p[i] / 100);
		}
	}
	printf("%.9f\n", s);


}