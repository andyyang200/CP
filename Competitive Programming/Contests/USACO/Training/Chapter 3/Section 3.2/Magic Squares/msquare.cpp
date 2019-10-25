/*
ID: andyyang200
PROG: msquare
LANG: C++11
*/
#include <stdio.h>
#include <iostream>
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

map<int, bool> state;
int target[8];

int getKey(int a[])
{
	int result = 0;
	FOR(i, 0, 8)
	{
		result += a[i] * pow(10, 7 - i);
	}
	return result;
}
void A(int a[])
{
	FOR(i, 0, 4)swap(a[i], a[7 - i]);
}
void B(int a[])
{
	RFOR(i, 2, -1)swap(a[i], a[i + 1]);
	FOR(i, 4, 7)swap(a[i], a[i + 1]);
}
void C(int a[])
{
	swap(a[1], a[2]);
	swap(a[1], a[5]);
	swap(a[1], a[6]);
}
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

struct Data
{
	string path;
	int numbers[8];
};

int main()
{
	freopen("msquare.in", "r", stdin);
	freopen("msquare.out", "w", stdout);
	FOR(i, 0, 8)
	{
		cin >> target[i];
	}
	queue<Data> q;
	Data start;
	start.path = "";
	FOR(i, 0, 8) start.numbers[i] = i + 1;
	q.push(start);
	while (!q.empty())
	{
		Data d = q.front();
		q.pop();
		if (memcmp(d.numbers, target, sizeof(d.numbers)) == 0)
		{
			string& p = d.path;
			cout << p.length() << endl;
			while (p.length() >= 60)
			{
				cout << p.substr(0, 60) << endl;
				p = p.substr(60, p.length() - 60);
			}
			cout << p << endl;
			break;
		}
		if (state[getKey(d.numbers)])
		{
			continue;
		}
		state[getKey(d.numbers)] = 1;
		Data a;
		a.path = d.path + "A";
		memcpy(a.numbers, d.numbers, sizeof(d.numbers));
		A(a.numbers);
		q.push(a);
		Data b;
		b.path = d.path + "B";
		memcpy(b.numbers, d.numbers, sizeof(d.numbers));
		B(b.numbers);
		q.push(b);
		Data c;
		c.path = d.path + "C";
		memcpy(c.numbers, d.numbers, sizeof(d.numbers));
		C(c.numbers);
		q.push(c);
	}
}