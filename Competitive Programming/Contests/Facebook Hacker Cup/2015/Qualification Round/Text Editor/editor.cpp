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
int main()
{
	//freopen("editor.in", "r", stdin);
	//freopen("editor.out", "w", stdout);
	int sets;
	scanf("%d", &sets);
	FOR(set, 0, sets)
	{

	}
}