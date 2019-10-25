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
struct Node
{
	bool isEnd;
	Node *children[26];
	Node()
	{
		isEnd = false;
		FOR(i, 0, 26)
		{
			children[i] = NULL;
		}
	}
};
Node start;
void addWord(string word)
{
	Node* traverse = &start;
	FOR(i, 0, word.length())
	{
		Node& current = *traverse;
		if (current.children[word[i] - 'a'] == NULL)
		{
			current.children[word[i] - 'a'] = new Node();
		}
		traverse = current.children[word[i] - 'a'];
	}
	(*traverse).isEnd = true;
}
bool edge[26][26];
int color[26];
bool can;
void makeGraph(string word)
{
	Node* traverse = &start;
	FOR(i, 0, word.length())
	{
		Node& current = *traverse;
		FOR(j, 0, 26)
		{
			if (j == word[i] - 'a')
			{
				continue;
			}
			if (current.children[j] != NULL)
			{
				edge[word[i] - 'a'][j] = true;
			}
		}
		traverse = current.children[word[i] - 'a'];
		if (i != word.length() - 1 && (*traverse).isEnd)
		{
			can = false;
		}
	}
}
void dfs(int node)
{
	if (color[node] == 1)
	{
		can = false;
	}
	if (color[node] != 0)
	{
		return;
	}
	color[node] = 1;
	FOR(i, 0, 26)
	{
		if (edge[node][i])
		{
			dfs(i);
		}
	}
	color[node] = 2;
}
void check()
{
	FOR(i, 0, 26)
	{
		if (color[i] == 0)
		{
			dfs(i);
		}
	}
}
string words[30001];
int main()
{
	freopen("first.in", "r", stdin);
	freopen("first.out", "w", stdout);
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		cin >> words[i];
		addWord(words[i]);
	}
	vector<string> ans;
	FOR(i, 0, n)
	{
		memset(color, 0, sizeof(color));
		memset(edge, false, sizeof(edge));
		can = true;
		makeGraph(words[i]);
		check();
		if (can)
		{
			ans.push_back(words[i]);
		}
	}
	cout << ans.size() << endl;
	FOR(i, 0, ans.size())
	{
		cout << ans[i] << endl;
	}
}
