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
int a[101];
bool canCode(int i)
{
    return i >= 0 && (a[i] == 1 || a[i] == 3);
}
bool canGym(int i)
{
    return i >= 0 && (a[i] == 2 || a[i] == 3);
}
int main3(void)
{
    int n;
    scanf("%d", &n);
    FOR(i, 0, n)
    {
        scanf("%d", &a[i]);
    }
    int rest = 0;
    int code = 0;
    int gym = 0;
    FOR(i, 0, n)
    {
        int rest1 = 0;
        int code1 = 0;
        int gym1 = 0;
        rest1 = rest;
        if (canGym(i - 1) )
        {
            rest1 = min(rest1, gym);
        }
        if (canCode(i - 1) )
        {
            rest1 = min(rest1, code);
        }
        rest1++;
        if (canCode(i))
        {
            code1 = rest;
            if (canGym(i - 1) )
            {
                code1 = min(code1, gym);
            }
        }
        if (canGym(i))
        {
            gym1 = rest;
            if (canCode(i - 1) )
            {
                gym1 = min(gym1, code);
            }
        }
        rest = rest1;
        gym = gym1;
        code = code1;
    }
    int ans = rest;
    if (canGym(n - 1))
    {
        ans = min(ans, gym);
    }
    if (canCode(n - 1))
    {
        ans = min(ans, code);
    }
    cout << ans << endl;
    return 0;
}