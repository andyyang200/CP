/*
ID: andyyang200
PROG: ratios
LANG: C++
*/

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

int main()
{
	freopen("ratios.in", "r", stdin);
	freopen("ratios.out", "w", stdout);
	int x, y, z, x1, y1, z1, x2, y2, z2, x3, y3, z3;
	cin >> x >> y >> z >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3;
	int minX, minY, minZ, minRatio;
	minX = minY = minZ = minRatio = -1;
	int minSum = 1000;
	for (int a = 0; a < 100; a++)
	{
		for (int b = 0; b < 100; b++)
		{
			if (a + b >= minSum)
			{
				break;
			}
			for (int c = 0; c < 100; c++)
			{
				if (a == 0 && b == 0 && c == 0)
				{
					continue;
				}
				if (a + b + c >= minSum)
				{
					break;
				}
				int totalX = a * x1 + b * x2 + c * x3;
				int totalY = a * y1 + b * y2 + c * y3;
				int totalZ = a * z1 + b * z2 + c * z3;
				int ratio;
				if (x == 0 && totalX != 0 || y == 0 && totalY != 0 || z == 0 && totalZ != 0)
				{
					continue;
				}
				if (x != 0)
				{
					ratio = totalX / x;
				}
				else if (y != 0)
				{
					ratio = totalY / y;
				}
				else
				{
					ratio = totalZ / z;
				}
				if (((x == 0 && totalX == 0) || (totalX % x == 0 && ratio == totalX / x)) && ((y == 0 && totalY == 0) || (totalY % y == 0 && ratio == totalY / y)) && ((z == 0 && totalZ == 0) || (totalZ % z == 0 && ratio == totalZ / z)))
				{
					minSum = a + b + c;
					minX = a;
					minY = b;
					minZ = c;
					minRatio = ratio;
				}
			}
		}
	}
	if (minRatio == -1)
	{
		cout << "NONE" << endl;
	}
	else
	{
		cout << minX << " " << minY << " " << minZ << " " << minRatio << endl;
	}
}