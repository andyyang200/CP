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
int marks[1000];
int main()
{
	int n, k, p, x, y;
	cin >> n >> k >> p >> x >> y;
	int lessY = 0;
	int sum = 0;
	FOR(i, 0, k)
	{
		cin >> marks[i];
		lessY += (marks[i] < y);
		sum += marks[i];
	}
	if (lessY > (n - 1) / 2)
	{
		cout << -1 << endl;
		return 0;
	}
	vector<int> ans;
	FOR(i, 0, (n - 1) / 2 - lessY)
	{
		if (k + ans.size() == n)
		{
			break;
		}
		ans.push_back(1);
		sum += 1;
	}
	FOR(i, 0, 1000000)
	{
		if (k + ans.size() == n)
		{
			break;
		}
		ans.push_back(y);
		sum += y;
	}
	if (sum > x)
	{
		cout << -1 << endl;
		return 0;
	}
	for (int i : ans)
	{
		cout << i << " ";
	}
	cout << endl;
}