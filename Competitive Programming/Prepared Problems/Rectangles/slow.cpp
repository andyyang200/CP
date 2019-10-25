#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int MAXN = 111111;

int N, x1[MAXN], y1[MAXN], x2[MAXN], y2[MAXN], all_x[2 * MAXN];

int main()
{

	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		scanf("%d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]);
		all_x[2 * i] = x1[i];
		all_x[2 * i + 1] = x2[i];
	}
	sort(all_x, all_x + 2 * N);

	// sweep the x-coordinates
	long long answer = 0;
	for(int i = 0; i < 2 * N; )
	{
		int x = all_x[i];
		if(i != 0 && x == all_x[i - 1])
		{
			i++;
			continue;
		}
		vector<pair<int, int> > y;
		// look for relevant rectangles
		for(int j = 0; j < N; j++)
			if(x1[j] <= x && x2[j] > x)
			{
				y.push_back(make_pair(y2[j], 1));
				y.push_back(make_pair(y1[j], -1));
			}
		if(y.size() == 0)
		{
			i++;
			continue;
		}
		// sweep
		sort(y.begin(), y.end());
		long long cur_area = 0;
		int num_rectangles = 0, pos = 0;
		while(pos < y.size())
		{
			int bottom_y = y[pos].first;
			num_rectangles += y[pos].second; // num_rectangles == 1
			while(num_rectangles > 0)
				num_rectangles += y[++pos].second;
			int top_y = y[pos].first;
			cur_area += top_y - bottom_y;
			pos++;
		}
		// find the next x-coordinate
		int j = i + 1;
		while(all_x[j] == all_x[i])
			j++;
		answer += cur_area * (all_x[j] - x);
		i = j;
	}

	printf("%lld\n", answer);

	return 0;
}
