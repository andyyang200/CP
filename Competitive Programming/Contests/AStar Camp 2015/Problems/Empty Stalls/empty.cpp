#include <fstream>
#include <iostream>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; index++)

int stalls[3000001];

int main()
{
	freopen("empty.in", "r", stdin);
	freopen("empty.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	long long x, y, a, b;
	FOR(i, 0, k)
	{
		cin >> x >> y >> a >> b;
		FOR(j, 1, y + 1)
		{
			stalls[(a * j + b) % n] += x;
		}
	}
	int cur = 0;
	while (true)
	{
		FOR(i, 0, n)
		{
			if (stalls[i] > 1)
			{
				cur += stalls[i] - 1;
				stalls[i] = 1;
			}
			if (stalls[i] == 0 && cur > 0)
			{
				cur--;
				stalls[i]++;
			}
		}
		if (cur == 0)
		{
			break;
		}
	}
	FOR(i, 0, n)
	{
		if (stalls[i] == 0)
		{
			cout << i << endl;
			break;
		}
	}
}
