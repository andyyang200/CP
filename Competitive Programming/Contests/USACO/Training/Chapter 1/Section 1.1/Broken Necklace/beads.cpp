/*
ID: andyyang200
LANG: C++11
TASK: beads
*/
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

int main(void)
{
	freopen("beads.in", "r", stdin);
	freopen("beads.out", "w", stdout);
	int n; // size of necklace
	scanf("%d", &n);
	string necklace; // string representing necklace
	cin >> necklace;
	int ans = 0; // overall answer
	for (int i = 0; i < n; i++) // cut after this index
	{
		char lColor = ' '; // color of left segment
		int count = 0; // beads collected if we cut after index i
		for (int j = i; j != (i + 1) % n; j = (j - 1 + n) % n) // move left and wrap around if needed
		{
			if (lColor == ' ' && necklace[j] != 'w') // first colored bead
			{
				lColor = necklace[j]; // establish left color
			}
			if (necklace[j] != 'w' && lColor != ' ' && necklace[j] != lColor) //check if new bead is not ok
			{
				break; // stop collecting
			}
			count++; // we can collect a new bead, update count
		}
		char rColor = ' '; // color of right segment
		for (int j = (i + 1) % n; j != i; j = (j + 1) % n) // move right and wrap around if needed
		{
			if (rColor == ' ' && necklace[j] != 'w') // first colored bead
			{
				rColor = necklace[j]; // establish right color
			}
			if (necklace[j] != 'w' && rColor != ' ' && necklace[j] != rColor) //check if new bead is not ok
			{
				break; // stop collecting
			}
			count++; // we can collect a new bead, update count
		}
		if (count > n) // AVOID CASE IF BOTH SIDES OVERLAP
		{
			count = n;
		}
		ans = max(ans, count); // update answer
	}
	cout << ans << endl;
}