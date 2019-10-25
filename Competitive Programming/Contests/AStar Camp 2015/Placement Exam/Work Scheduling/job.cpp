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
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
pii jobs[100001];
int main()
{
	freopen("job.in", "r", stdin);
	freopen("job.out", "w", stdout);
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		scanf("%d%d", &jobs[i].first, &jobs[i].second);
	}
	sort(jobs, jobs + n);
	priority_queue<pii> pq;
	ll ans = 0;
	int previous = jobs[n - 1].first + 1;
	RFOR(i, n - 1, -1)
	{
		int j;
		for (j = i; j >= 0; j--)
		{
			if (jobs[i].first == jobs[j].first)
			{
				pq.push(make_pair(jobs[j].second, jobs[j].first));
			}
			else
			{
				break;
			}
		}
		i = j + 1;
		FOR(k, 0, jobs[i].first - (i == 0 ? 0 :  jobs[i - 1].first))
		{
			if (pq.empty())
			{
				break;
			}
			ans += (ll)(pq.top().first);
			pq.pop();
		}
	}
	cout << ans << endl;
}