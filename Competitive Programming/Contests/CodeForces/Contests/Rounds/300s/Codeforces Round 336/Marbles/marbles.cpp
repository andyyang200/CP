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
#define P 97
typedef long long ll;
typedef pair<int, int> pii;
ll hasha[1000001];
ll hashb[1000001];
ll power[1000001];
int main()
{
	int n;
	scanf("%d", &n);
	n--;
	string a, b;
	cin >> a >> b;
	reverse(a.begin(), a.end());
	FOR(i, 0, n)
	{
		if (a[i] == 'N')
		{
			a[i] = 'S';
		}
		else if (a[i] == 'S')
		{
			a[i] = 'N';
		}
		else if (a[i] == 'E')
		{
			a[i] = 'W';
		}
		else if (a[i] == 'W')
		{
			a[i] = 'E';
		}
	}
	hasha[0] = a[0];
	power[0] = 1;
	FOR(i, 1, n)
	{
		hasha[i] = (hasha[i - 1] * P + a[i]) % M;
		power[i] = power[i - 1] * P % M;
	}
	hashb[n - 1] = b[n - 1];
	RFOR(i, n - 2, -1)
	{
		hashb[i] = (hashb[i + 1] + power[b.length() - 1 - i] * b[i]) % M;
	}
	FOR(i, 0, n)
	{
		if (hasha[i] == hashb[n - 1 - i])
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}