
#include <iostream>
using namespace std;

int main(void)
{
	freopen("lostcow.in", "r", stdin);
	freopen("lostcow.out", "w", stdout);
	int x;
	int y;
	cin >> x >> y;
	int dis = 0;
	int cur = x;
	int change = 1;
	while (true)
	{
		int end = x + change;
		while (cur < end)
		{
			cur++;
			dis++;
			if (cur == y)
			{
				cout << dis << endl;
				return 0;
			}
		}
		while (cur > end)
		{
			cur--;
			dis++;
			if (cur == y)
			{
				cout << dis << endl;
				return 0;
			}
		}
		change += change;
		change = -change;
	}
	cout << dis << endl;
}