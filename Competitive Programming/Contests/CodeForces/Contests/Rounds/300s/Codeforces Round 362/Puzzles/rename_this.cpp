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
int p[100001];
double ans[100001];
vector<int> children[100001];
int s[100001];
void dfs(int u)
{
    s[u]++;
    for (int v : children[u])
    {
        dfs(v);
        s[u] += s[v];
    }
}
void calc(int u)
{
    int parent = p[u];
    ans[u] += 0.5 * (s[parent] - s[u] - 1);
    ans[u] += 1;
    ans[u] += ans[parent];
    for (int v : children[u])
    {
        calc(v);
    }
}
int main(void)
{
    int n;
    scanf("%d", &n);
    p[0] = -1;
    FOR(i, 1, n)
    {
        scanf("%d", &p[i]);
        p[i]--;
        children[p[i]].push_back(i);
    }
    dfs(0);
    ans[0] = 1;
    for (int v : children[0])
    {
        calc(v);
    }
    FOR(i, 0, n)
    {
        printf("%.9f ", ans[i]);
    }
    cout << endl;
}