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

priority_queue<double, vector<double>, greater<double>> t;
priority_queue<double, vector<double>, greater<double>> d;

int main()
{
	freopen("slowdown.in", "r", stdin);
	freopen("slowdown.out", "w", stdout);
	int n;
	cin >> n;
	FOR(i, 0, n)
	{
		char type;
		cin >> type;
		double x;
		cin >> x;
		type == 'T' ? t.push(x) : d.push(x);
	}
	int speed = 1; //second per meter
	double time = 0;
	double distance = 0;
	while (!t.empty() || !d.empty())
	{
		if (d.empty() || (!t.empty() && t.top() - time <= (d.top() - distance) * speed))
		{
			distance += (t.top() - time) / speed;
			time = t.top();
			speed++;
			t.pop();
		}
		else
		{
			time += (d.top() - distance) * speed;
			distance = d.top();
			speed++;
			d.pop();
		}
	}
	time += (1000 - distance) * speed;
	cout << (long)(round(time)) << endl;
}