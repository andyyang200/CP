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
#define FOR(index, start, end) for(int index = start; index < end; index++)
#define RFOR(index, start, end) for(int index = start; index > end; index--)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	int x1, y1, r1, x2, y2, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	double r = r1;
	double R = r2;
	double d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	if (d >= r + R)
	{
		cout << 0 << endl;
		return 0;
	}
	if (R < r)
	{
		r = r2;
		R = r1;
	}
	double part1 = r*r*acos((d*d + r*r - R*R) / (2 * d*r));
	double part2 = R*R*acos((d*d + R*R - r*r) / (2 * d*R));
	double part3 = 0.5*sqrt((-d + r + R)*(d + r - R)*(d - r + R)*(d + r + R));
	double intersectionArea = part1 + part2 - part3;
	printf("%.11f\n", intersectionArea);

}