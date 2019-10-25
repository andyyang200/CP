/*
ID: andyyan1
PROG: spin
LANG: C++11
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

struct Wedge
{
	int angle;
	int size;
};

struct Wheel
{
	int angle = 0;
	int numWedges;
	Wedge wedges[5];
	int speed;
	void turn()
	{
		for (int x = 0; x < numWedges; x++)
		{
			wedges[x].angle += speed;
			wedges[x].angle %= 360;
			angle += speed;
			angle %= 360;
		}
	}
};

Wheel wheels[5];

bool check(int angle)
{
	for (Wheel wheel : wheels)
	{
		bool open = false;
		for (int x = 0; x < wheel.numWedges; x++)
		{
			Wedge& wedge = wheel.wedges[x];
			if ((angle >= wedge.angle && angle <= wedge.angle + wedge.size) || (angle + 360 >= wedge.angle && angle + 360 <= wedge.angle + wedge.size))
			{
				open = true;
				break;
			}
		}
		if (!open)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	freopen("spin.in", "r", stdin);
	freopen("spin.out", "w", stdout);
	for (int x = 0; x < 5; x++)
	{
		cin >> wheels[x].speed;
		cin >> wheels[x].numWedges;
		for (int i = 0; i < wheels[x].numWedges; i++)
		{
			cin >> wheels[x].wedges[i].angle;
			cin >> wheels[x].wedges[i].size;
		}
	}
	for (int time = 0; time >= 0; time++)
	{
		for (Wheel wheel : wheels)
		{
			for (int x = 0; x < wheel.numWedges; x++)
			{
				Wedge& wedge = wheel.wedges[x];

				if (check(wedge.angle) || check((wedge.angle + wedge.size) % 360))
				{
					cout << time << endl;
					return 0;
				}
			}
		}
		for (int x = 0; x < 5; x++)
		{
			wheels[x].turn();
		}
		bool cycle = true;
		for (int x = 0; x < 5; x++)
		{
			if (wheels[x].angle != 0)
			{
				cycle = false;
				break;
			}
		}
		if (cycle)
		{
			cout << "none" << endl;
			return 0;
		}
	}
}