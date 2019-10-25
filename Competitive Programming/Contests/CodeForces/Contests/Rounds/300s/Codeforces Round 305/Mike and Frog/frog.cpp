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
	bool seen1[1000005];
	bool seen2[1000005];

	int main()
	{
		ll m, h1, a1, x1, y1, h2, a2, x2, y2;
		cin >> m >> h1 >> a1 >> x1 >> y1 >> h2 >> a2 >> x2 >> y2;
		ll t1 = 0;
		ll t2 = 0;
		while (h1 != a1)
		{
			seen1[h1] = true;
			h1 = (h1 * x1 + y1) % m;
			t1++;
			if (seen1[h1])
			{
				cout << -1 << endl;
				return 0;
			}
		}
		while (h2 != a2)
		{
			seen2[h2] = true;
			h2 = (h2 * x2 + y2) % m;
			t2++;
			if (seen2[h2])
			{
				cout << -1 << endl;
				return 0;
			}
		}
		if (t1 == t2)
		{
			cout << t1 << endl;
			return 0;
		}
		ll r1 = 0;
		ll r2 = 0;
		memset(seen1, false, sizeof(seen1));
		memset(seen2, false, sizeof(seen2));
		h1 = (h1 * x1 + y1) % m;
		h2 = (h2 * x2 + y2) % m;
		if (h1 != (h1 * x1 + y1) % m)
		{
			h1 = (h1 * x1 + y1) % m;
			r1++;
			while (h1 != a1)
			{
				seen1[h1] = true;
				h1 = (h1 * x1 + y1) % m;
				r1++;
				if (seen1[h1])
				{
					cout << -1 << endl;
					return 0;
				}
			}
		}
		
		if (r1 == 1)
		{
			cout << max(t1, t2) << endl;
			return 0;
		}
		if (h2 != (h2 * x2 + y2) % m)
		{
			h2 = (h2 * x2 + y2) % m;
			r2++;
			while (h2 != a2)
			{
				seen2[h2] = true;
				h2 = (h2 * x2 + y2) % m;
				r2++;
				if (seen2[h2])
				{
					cout << -1 << endl;
					return 0;
				}
			}
		}
		if (r1 == 0 || r2 == 0)
		{
			cout << max(t1, t2) << endl;
			return 0;
		}
		FOR(i, 0, 5000000)
		{
			if (t1 + i * r1 >= t2)
			{
				if ((t1 + i * r1 - t2) % r2 == 0)
				{
					cout << t1 + i * r1 << endl;
					return 0;
				}
			}
			
		}
		cout << -1 << endl;
	}