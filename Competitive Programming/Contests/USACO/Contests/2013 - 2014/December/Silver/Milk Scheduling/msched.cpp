#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
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
#define FOR(index, start, end) for(int index = start; index < end; index++)
#define RFOR(index, start, end) for(int index = start; index > end; index--)
#define FOREACH(itr, b) for(auto& itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto& itr = b.rbegin(); itr != b.rend; itr++)
typedef long long ll;
using namespace std;
map<int, vector<int> > cows;
priority_queue<int> pq;
int main()
{
	ifstream fin("msched.in");
	ofstream fout("msched.out");
	int n;
	fin >> n;
	FOR(i, 0, n)
	{
		int g, d;
		fin >> g >> d;
		cows[d].push_back(g);
	}
	int sum = 0;
	RFOR(i, 10004, -1)
	{
		if (!pq.empty())
		{
			sum += pq.top();
			pq.pop();
		}
		if (cows[i].size() > 0)
		{
			for (int g : cows[i])
			{
				pq.push(g);
			}
		}
	}
	fout << sum << endl;
}