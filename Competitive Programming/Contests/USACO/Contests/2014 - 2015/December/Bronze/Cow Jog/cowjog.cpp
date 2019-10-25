#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
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

int position[100005];
int speed[100005];

int main()
{
	freopen("cowjog.in", "r", stdin);
	freopen("cowjog.out", "w", stdout);

	int n;
	cin >> n;
	for (int x = 0; x < n; x++)
	{
		cin >> position[x];
		cin >> speed[x];
	}
	int count = 1;
	for (int x = n - 2; x >= 0; x--)
	{
		if (speed[x] > speed[x + 1])
		{
			speed[x] = speed[x + 1];
		}
		else
		{
			count++;
		}
	}
	cout << count << endl;
}