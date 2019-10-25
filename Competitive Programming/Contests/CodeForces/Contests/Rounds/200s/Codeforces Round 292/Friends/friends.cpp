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
typedef pair<int, int> pii;

bool boys[100];
bool girls[100];

int main()
{
	int n, m, b;
	scanf("%d%d%d", &n, &m, &b);
	int happy = 0;
	FOR(i, 0, b)
	{
		int x;
		scanf("%d", &x);
		boys[x] = true;
	}
	int g;
	scanf("%d", &g);
	FOR(i, 0, g)
	{
		int x;
		scanf("%d", &x);
		girls[x] = true;
	}
	happy += b + g;
	int i = 0;
	int noChange = 0;
	while (happy < n + m)
	{
		if (noChange == n * m)
		{
			break;
		}
		if (boys[i % n] ^ girls[i % m])
		{
			boys[i % n] = girls[i % m] = true;
			happy++;
			noChange = 0;
		}
		else
		{
			noChange++;
		}
		i++;
	}
	if (happy == n + m)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
}