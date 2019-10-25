//Andrew Yang
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
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; index++)
#define RFOR(index, start, end) for(int index = start; index > end; index--)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
int reverse(int x)
{
	int result = 0;
	while (x != 0){
		result = result * 10 + x % 10;
		x = x / 10;
	}
	return result;
}

bool checkDup(set<int>s1, set<int>s2)
{
	set<int> intersect;
	set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(),
		std::inserter(intersect, intersect.begin()));
	return intersect.size() != 0;
}

ll GetSteps(int st, int en)
{
	set<int> fr;
	set<int> frt;
	set<int> ba;
	set<int> bat;
	fr.insert(st);
	ba.insert(en);
	ll steps1 = 0;
	ll steps2 = 0;
	while (true)
	{
		bool found = checkDup(fr, ba);
		if (found)
			break;
		steps1++;
		for (auto i : fr)
		{
			int r = reverse(i);
			if (i < r && r <= en) frt.insert(r);
			if (i + 1 <= en)frt.insert(i + 1);
		}
		fr = frt;
		frt.clear();
		found = checkDup(fr, ba);
		if (found)
			break;

		steps2++;
		for (auto i : ba)
		{
			int r = reverse(i);
			if (r < i && r >= 1 && i == reverse(r)) bat.insert(r);
			if (i - 1 >= 1)bat.insert(i - 1);
		}
		ba = bat;
		bat.clear();
	}
	return steps1 + steps2;
}
bool visited[2000005];
int main()
{
	freopen("culture.in", "r", stdin);
	freopen("culture.out", "w", stdout);
	int sets;
	scanf("%d", &sets);
	FOR(set, 1, sets + 1)
	{
		int n;
		cin >> n;
		cout << "Case #" << set << ": " << GetSteps(1, n) << endl;
	}
}