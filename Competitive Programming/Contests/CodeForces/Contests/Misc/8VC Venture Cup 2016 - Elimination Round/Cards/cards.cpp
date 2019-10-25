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
bool visited[210][210][210];
int r, g, b, n;
char s[210];
void dfs(int r, int g, int b) 
{
	if (visited[r][g][b]) return;
	visited[r][g][b] = 1;
	if (r&&g) dfs(r - 1, g - 1, b + 1);
	if (r&&b) dfs(r - 1, g + 1, b - 1);
	if (g&&b) dfs(r + 1, g - 1, b - 1);
	if (r >= 2) dfs(r - 1, g, b);
	if (g >= 2) dfs(r, g - 1, b);
	if (b >= 2) dfs(r, g, b - 1);
}
int main() 
{
	scanf("%d", &n);
	scanf("%s", s);
	FOR(i, 0, n) 
	{
		if (s[i] == 'R') r++;
		else if (s[i] == 'G') g++;
		else if (s[i] == 'B') b++;
	}
	dfs(r, g, b);
	if (visited[0][0][1]) cout << 'B';
	if (visited[0][1][0]) cout << 'G';
	if (visited[1][0][0]) cout << 'R';
	cout << endl;
}