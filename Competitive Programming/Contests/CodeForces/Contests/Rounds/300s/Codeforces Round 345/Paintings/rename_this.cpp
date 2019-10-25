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
vector<int> a;
int main()
{
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		int x;
		scanf("%d", &x);
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	int previous = a[0];
	a.erase(a.begin());
	int ans = 0;
	while (a.size() > 0)
	{
		auto itr = upper_bound(a.begin(), a.end(), previous);
		if (itr == a.end())
		{
			previous = a[0];
			a.erase(a.begin());
		}
		else
		{
			previous = *itr;
			a.erase(itr);
			ans++;
		}
	}
	cout << ans << endl;
}