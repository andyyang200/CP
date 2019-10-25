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
pii notes[100001];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	FOR(i, 0, m)	
	{
		scanf("%d%d", &notes[i].first, &notes[i].second);
	}
	FOR(i, 1, m)
	{
		if (abs(notes[i].second - notes[i - 1].second) > notes[i].first - notes[i - 1].first)
		{
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
	}
	int ans = 0;
	FOR(i, 1, m)
	{
		ans = max(ans, max(notes[i].second, notes[i - 1].second) + (notes[i].first - notes[i - 1].first - abs(notes[i].second - notes[i - 1].second)) / 2);
	}
	ans = max(ans, notes[0].second + notes[0].first - 1);
	ans = max(ans, notes[m - 1].second + n - notes[m - 1].first);
	cout << ans << endl;
}