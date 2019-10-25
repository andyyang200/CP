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
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
int p[100];
int t[100];
int main()
{
	int n, c;
	scanf("%d%d", &n, &c);
	int score1 = 0;
	int score2 = 0;
	int t1 = 0;
	int t2 = 0;
	FOR(i, 0, n)
	{
		scanf("%d", &p[i]);
	}
	FOR(i, 0, n)
	{
		scanf("%d", &t[i]);
	}
	FOR(i, 0, n)
	{
		t1 += t[i];
		score1 += max(0, p[i] - c * t1);
	}
	RFOR(i, n - 1, -1)
	{
		t2 += t[i];
		score2 += max(0, p[i] - c * t2);
	}
	if (score1 > score2)
	{
		cout << "Limak" << endl;
	}
	else if (score1 < score2)
	{
		cout << "Radewoosh" << endl;
	}
	else
	{
		cout << "Tie" << endl;
	}
}