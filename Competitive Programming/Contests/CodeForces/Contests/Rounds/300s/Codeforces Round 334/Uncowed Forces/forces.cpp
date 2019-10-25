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
double m[5];
double w[5];
int main()
{
	double score = 0;
	FOR(i, 0, 5)
	{
		cin >> m[i];
	}
	FOR(i, 0, 5)
	{
		cin >> w[i];
		double x = (i + 1) * 500;
		score += max(0.3 * x, (1 - m[i] / 250) * x - 50 * w[i]);
	}
	int a, b;
	cin >> a >> b;
	score += 100 * a - 50 * b;
	cout << round(score) << endl;
}