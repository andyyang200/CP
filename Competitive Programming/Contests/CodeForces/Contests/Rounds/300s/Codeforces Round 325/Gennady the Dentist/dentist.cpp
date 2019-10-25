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
vector<int> v, d, p, id, ans;
int main()
{
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		v.push_back(a);
		d.push_back(b);
		p.push_back(c);
		id.push_back(i + 1);
	}
	FOR(i, 0, v.size())
	{
		ans.push_back(id[i]);
		FOR(j, i + 1, min(i + 1 + v[i], (int)v.size()))
		{
			p[j] -= v[i];
			p[j] += j - i - 1;
		}
		FOR(j, i + 1, v.size())
		{
			if (p[j] < 0)
			{
				FOR(k, j + 1, v.size())
				{
					if (p[k] >= 0)
					{
						p[k] -= d[j];
					}
				}
				v.erase(v.begin() + j);
				d.erase(d.begin() + j);
				p.erase(p.begin() + j);
				id.erase(id.begin() + j);
				j--;
			}
		}
	}
	cout << ans.size() << endl;
	FOR(i, 0, ans.size())
	{
		cout << ans[i] << " ";
	}
	cout << endl;
}