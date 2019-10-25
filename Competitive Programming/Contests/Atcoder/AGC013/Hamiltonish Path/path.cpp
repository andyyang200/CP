//Andrew Yang
//accepted
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
#include <deque>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
vector<int> edges[100001];
bool inPath[100001];
int main(void)
{
	int n, m;
	scanf("%d%d", &n, &m);
	FOR(i, 0, m)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	deque<int> d;
	d.push_back(0);
	inPath[0] = true;
	while (true)
	{
		int left = d.front();
		int right = d.back();
		bool done = true;
		for(int j : edges[left])
		{
			if (!inPath[j])
			{
				d.push_front(j);
				done = false;
				inPath[j] = true;
				break;
			}
		}
		for (int j : edges[right])
		{
			if (!inPath[j])
			{
				d.push_back(j);
				done = false;
				inPath[j] = true;
				break;
			}
		}
		if (done)
		{
			break;
		}
	}
	cout << d.size() << endl;
	for (int j : d)
	{
		cout << j + 1 << " ";
	}
	cout << endl;
}