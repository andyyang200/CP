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
int x[1005];
double y[1005];
int main(void)
{
	int n, r;
	cin >> n >> r;
	FOR(i, 0, n) {
		cin >> x[i];
	}
	FOR(i, 0, n) {
		double y1 = r;
		FOR(j, 0, i) {
			if (abs(x[j] - x[i]) <= 2 * r) {
				double y2 = y[j] + sqrt(4 * r * r - abs(x[j] - x[i]) * abs(x[j] - x[i]));
				y1 = max(y1, y2);
			}
		}
		y[i] = y1;
	}
	FOR(i, 0, n) {
		printf("%.9f ", y[i]);
	}
	cout << endl;

}