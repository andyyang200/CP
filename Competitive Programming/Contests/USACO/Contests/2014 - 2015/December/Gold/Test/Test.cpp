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
#include <map>
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
#define FOREACH(itr, b) for(auto& itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto& itr = b.rbegin(); itr != b.rend; itr++)
typedef long long ll;
typedef pair<int, int> pii;

ll cows[1000]; // end position of each cow
bool used[1000]; // if cow is put on track yet
vector<int> lis[100001]; // longest increasing subsequence ending at each point

int main()
{
	freopen("cowjog.in", "r", stdin);
	freopen("cowjog.out", "w", stdout);
	ll n, t;
	cin >> n >> t;
	FOR(i, 0, n)
	{
		ll p, s;
		cin >> p >> s;
		cows[i] = p + t * s;
	}
	int lanes = 0;
	int cowsLeft = n;
	while (cowsLeft > 0)
	{
		int maxLength = 0;
		int maxPosition = 0;
		FOR(i, 0, n)
		{
			if (used[i])
			{
				continue;
			}
			lis[i].clear();
			FOR(j, 0, i)
			{
				if (!used[j] && cows[j] < cows[i] && lis[j].size() > lis[i].size())
				{
					lis[i] = lis[j];
				}
			}
			lis[i].push_back(i);
			if (lis[i].size() > maxLength)
			{
				maxLength = lis[i].size();
				maxPosition = i;
			}
		}
		FOR(i, 0, lis[maxPosition].size())
		{
			used[lis[maxPosition][i]] = true;
			cowsLeft--;
		}
		lanes++;
	}
	cout << lanes << endl;
	return 0;
}

