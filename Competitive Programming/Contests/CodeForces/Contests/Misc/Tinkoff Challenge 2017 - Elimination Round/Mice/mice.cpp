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
typedef pair<long double, long double> pdd;
const double eps = 1e-11;
int n;
int x1, x2, y1, y2;
double L = 0, R = 1e100;

void up(int a, int b, int v){
	if (v == 0)	{
		if (a < 0 && b > 0) {
			return;
		}
		R = -1;
	}
	double p, q;
	p = (double)a / v, q = (double)b / v;
	if (p > q)swap(p, q);
	L = max(L, p);
	R = min(R, q);
}

int main()
{
	scanf("%d", &n);
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	FOR(i, 0, n){
		int rx, ry, vx, vy;
		scanf("%d%d%d%d", &rx, &ry, &vx, &vy);
		up(x1 - rx, x2 - rx, vx);
		up(y1 - ry, y2 - ry, vy);
	}
	if (L + eps > R) {
		cout << -1 << endl;
	}
	else {
		printf("%.10lf\n", L);
	}
}