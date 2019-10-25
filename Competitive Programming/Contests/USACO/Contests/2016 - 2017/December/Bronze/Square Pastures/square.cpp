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
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	freopen("square.in", "r", stdin);
	freopen("square.out", "w", stdout);
	int a, b, c, d;
	int a1, b1, c1, d1;
	cin >> a >> b >> c >> d >> a1 >> b1 >> c1 >> d1;
	int minX = min(a, min(c, min(a1, c1)));
	int maxX = max(a, max(c, max(a1, c1)));
	int minY = min(b, min(d, min(b1, d1)));
	int maxY = max(b, max(d, max(b1, d1)));
	cout << max(maxX - minX, maxY - minY) * max(maxX - minX, maxY - minY) << endl;
}