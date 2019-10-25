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
	int n;
	double h;
	cin >> n >> h;
	double area = 1.0 * h / 2 / n;
	double last = 0;
	vector<double> v;
	FOR(i, 0, n - 1) {
		double base = ((double)h - last) / h;
		double l = 0;
		double r = h - last;
		double m = -1;
		FOR(j, 0, 100) {
			m = (l + r) / 2;
			double base2 = (h - last - m) * (base) / (h - last);
			double x = (base + base2) / 2 * m;
			if (x < area) {
				l = m;
			}
			else {
				r = m;
			}
		}
		v.push_back(h - m - last);
		last += m;
	}
	reverse(v.begin(), v.end());
	for (double x : v) {
		printf("%.15f ", x);
	}
	cout << endl;
}