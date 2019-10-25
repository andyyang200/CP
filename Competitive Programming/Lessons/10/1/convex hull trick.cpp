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
/*
There are N fields (N <= 100000). Each field has length li and width wi.
The cost to purchase a set of fields is product of the maximum length in that set
and the maximum width in that set. What is the minimum cost to purchase all fields?
*/
pii a[100001];
vector<pair<ll, ll>> land;
vector<pair<ll, ll>> lines;
vector<pair<double, double>> segments;
double getIntersectionX(pair<ll, ll > x, pair<ll, ll > y)
{
	ll a = x.first;
	ll b = y.first;
	ll c = x.second;
	ll d = y.second;
	return (double)(d - c) / (a - b);
}
ll query(ll x)
{
	int l = 0;
	int r = lines.size() - 1;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (x >= segments[mid].first && x <= segments[mid].second)
		{
			return lines[mid].first * x + lines[mid].second;
		}
		if (x > segments[mid].second)
		{
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	return 0;
}
void update(pair<ll, ll> p)
{
	while (lines.size() >= 2 && getIntersectionX(p, lines.back()) <= getIntersectionX(lines.back(), lines[lines.size() - 2]))
	{
		lines.pop_back();
		segments.pop_back();
	}
	double x = getIntersectionX(p, lines.back());
	segments.back().second = x;
	segments.push_back({ x, x + INF });
	lines.push_back(p);
}

int main()
{
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		scanf("%d%d", &a[i].first, &a[i].second);
	}
	sort(a, a + n);
	FOR(i, 0, n)
	{
		while (!land.empty() && land.back().second <= a[i].second)
		{
			land.pop_back();
		}
		land.push_back(a[i]);
	}
	if (land.size() == 1)
	{
		cout << (ll)land[0].first * land[0].second << endl;
		return 0;
	}
	lines.push_back({ land[land.size() - 2].first, (ll)land[land.size() - 1].first * land[land.size() - 1].second });
	segments.push_back({ -INF, INF });
	RFOR(i, land.size() - 2, -1)
	{
		ll x = query(land[i].second);
		x = min(x, (ll)land[i].second * land[land.size() - 1].first);
		if (i > 0)
		{
			update({ land[i - 1].first, x });
		}
		else
		{
			cout << x << endl;
		}
	}
}
/*
Suppose that both of field A's dimensions equal or exceed the corresponding dimensions of field B. 
Then, we may remove field B from the input because its presence cannot affect the answer, because we can 
merely compute an optimal solution without it and then insert it into whichever subset contains field A 
without changing the cost. We first sort the fields in ascending order of length (width is a secondary factor) 
and then sweep through them in linear time to select relevant fields. What remains is a list of fields in 
which height is strictly increasing and width is strictly decreasing (Otherwise, a contradiction would exist
to our assumption that all irrelevant fields have been removed).

In the sorted list of remaining field, one way to yield the optimal answer is by buying contiguous 
subarrays. This is true because, in any subset, if rectangle A is the tallest and rectangle B is the widest, 
then all rectangles between them in the sorted list may be added to this subset without any additional cost.

This yields a simple dp solution. Let dp(i) be the minimum cost to purchase fields i, i + 1, i + 2, ..., n - 1.
Then dp(i) = min(l[j - 1] * w[i] + dp(j)), where i < j <= n. The logic here is that for each j, we are buying 
fields i, i + 1, i + 2, ..., j - 1 as a single subset. This dp is O(n^2), because there are n states that each require
n transitions.
________________________________________________________________________________________________________________________

To make the optimization to O(nlogn), we first solve another problem.

Suppose we are given a N number of lines in the form y = ax + b along with Q queries.
In each query, we are given an x value, and must return the minimum value that can be obtained be evalutaing
one of our linear functions at x. How can we answer each query in log(N)?

Let a line be the minimum line at x if it yields the lowest y coordinate at x.
After randomly drawing some lines on the coordinate plane, we realize that each line is the minimum in a single
continuous interval (possible having positive or negative infinity as bounds), or is never the minimum at all.
It is not difficult to see that this is always true. Thus, if we remove irrevelant lines, we can build a collection of 
sorted intervals, in each of which one of the functions is the minimum. Then for each query, we can simply use binary
search to find which interval x lies in, and then evaluate the corresponding function at x.

How do we build these intervals?

Notice that the minimum segments of each line create the top of a convex polygon. This is easy to prove.
It follows that the segments are decreasing in slope from left to right, and that the first interval must belong
to the line with the largest slope. 
This inspires the following solution: we add lines one by one in order of decreasing slope. However,
each time, we must remove lines that become irrelevant. 

Heres one way to do it: imagine we are trying to addline C, and the last line in our collection is B, and the line 
before that is A. Then if the intersection of A and C has a larger x coordinate than the intersection of B and C, 
line B is uneccessary and is removed. We repeat this until there are no more possible lines to be removed 
(we cannot remove the first line), or until we reach a line thatshould not be removed (we stop here because
there clearly cannot be any more lines to remove, as addition of previous lines would have already removed them). 

If this is unclear, here's another way to see it: Since each line is decreasing in slope, it can intersect
our current convex polygon at only one location. Every segment of the convex polygon on the right of this intersection
becomes irrelevant and is removed.

At the end, our data collection of minimum segments will be complete.
This is called the convex hull trick.
___________________________________________________________________________________________________________________________

So how can this be used to solve our original problem?

Recall that dp(i) = min(l[j - 1] * w[i] + dp(j)), where i < j <= n. Notice that this is equivalent to minimizing
the functions y = l[j - 1]x + dp(j), where i < j <= n, at the x coordinate of w[i]. We use the convex hull trick to
compute these queries in O(logN). After calculating dp[i], we should update our structure with the line 
y = l[i - 1]x + dp[i], because in future iterations i2, we have the new option of buying fields
i2, i2 + 1, i2 + 2, ..., i - 1 as a single subset.

Now the only issue is that our convex hull data structure does not seem to support updates. However, since l[i] 
is strictly increasing, our lines are added in decreasing order of slope, so updates can be handled like adding a new line
in the process of building our data structure. Also note that since l[] is strictly increasing, we don't need to worry
about lines with the same slope.

Thus, the overall runtime is O(NlogN + NlogN) = O(logN).

Finally, the runtime can be improved to O(NlogN + N). Instead of using binary search to answer each query w[i],
notice instead that w[i] is strictly increasing. Therfore, we can the two-pointer technique technique to find out which
interval contains w[i] as w[i] increases.
*/