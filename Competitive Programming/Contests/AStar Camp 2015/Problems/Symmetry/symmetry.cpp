//Andrew Yang
//#include <iostream>
//#include <stdio.h>
//#include <sstream>
//#include <fstream>
//#include <string>
//#include <string.h>
//#include <vector>
//#include <deque>
//#include <queue>
//#include <stack>
//#include <set>
//#include <map>
//#include <algorithm>
//#include <functional>
//#include <utility>
//#include <bitset>
//#include <cmath>
//#include <cstdlib>
//#include <ctime>
//#include <cstdio>
//#include <climits>
//using namespace std;
//#define FOR(index, start, end) for(int index = start; index < end; index++)
//#define RFOR(index, start, end) for(int index = start; index > end; index--)
//#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); itr++)
//#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
//#define INF 1000000000
//#define M 1000000007
//typedef long long ll;
//typedef pair<int, int> pii;
//pii points[1001];
//map<pii, bool> exists;
//map < pair<double, double>, bool > counted;
//int main()
//{
//	freopen("symmetry.in", "r", stdin);
//	freopen("symmetry.out", "w", stdout);	
//	int n;
//	scanf("%d", &n);
//	FOR(i, 0, n)
//	{
//		cin >> points[i].first >> points[i].second;
//		exists[make_pair(points[i].first, points[i].second)] = true;
//	}
//	int ans = 0;
//	FOR(i, 1, n)
//	{
//		double x = (double)(points[0].first + points[i].first) / 2;
//		double y = (double)(points[0].second + points[i].second) / 2;
//		double m = (double)(points[i].second - points[0].second) / (points[i].first - points[0].first);
//		m = -1 / m;
//		double b = y - m * x;
//		bool s = true;
//		FOR(j, 0, n)
//		{
//			double x1 = points[j].first;
//			double y1 = points[j].second;
//			double x2, y2;
//			if (b > INF || b < -INF)
//			{
//				y2 = y1;
//				if (x1 < x)
//				{
//					x2 = x + (x - x1);
//				}
//				else
//				{
//					x2 = x - (x1 - x);
//				}
//			}
//			else
//			{
//				double d = (x1 + (y1 - b)*m) / (1 + m * m);
//				x2 = 2 * d - x1;
//				y2 = 2 * d * m - y1 + 2 * b;
//			}
//			if (!dequals(round(x2), x2) || !dequals(round(y2), y2) || !exists[make_pair((int)round(x2), (int)round(y2))])
//			{
//				s = false;
//				break;
//			}
//		}
//		m = round(m * 100) / 100;
//		b = round(b * 100) / 100;
//		if (m > INF || m < -INF)
//		{
//			m = INF;
//		}
//		if (b > INF || b < -INF)
//		{
//			b = INF;
//		}
//		if (s && !counted[make_pair(m, b)])
//		{
//			ans++;
//			counted[make_pair(m, b)] = true;
//		}
//	}
//	FOR(i, 0, n)
//	{
//		double x = (double)(points[1].first + points[i].first) / 2;
//		double y = (double)(points[1].second + points[i].second) / 2;
//		double m = (double)(points[i].second - points[1].second) / (points[i].first - points[1].first);
//		m = -1 / m;
//		double b = y - m * x;
//		bool s = true;
//		FOR(j, 0, n)
//		{
//
//			double x1 = points[j].first;
//			double y1 = points[j].second;
//			double x2, y2;
//			if (b > INF || b < -INF)
//			{
//				y2 = y1;
//				if (x1 < x)
//				{
//					x2 = x + (x - x1);
//				}
//				else
//				{
//					x2 = x - (x1 - x);
//				}
//			}
//			else
//			{
//				double d = (x1 + (y1 - b)*m) / (1 + m * m);
//				x2 = 2 * d - x1;
//				y2 = 2 * d * m - y1 + 2 * b;
//			}
//			if (!dequals(round(x2), x2) || !dequals(round(y2), y2) || !exists[make_pair((int)round(x2), (int)round(y2))])
//			{
//				s = false;
//				break;
//			}
//		}
//		m = round(m * 100) / 100;
//		b = round(b * 100) / 100;
//		if (m > INF || m < -INF)
//		{
//			m = INF;
//		}
//		if (b > INF || b < -INF)
//		{
//			b = INF;
//		}
//		if (s && !counted[make_pair(m, b)])
//		{
//			ans++;
//			counted[make_pair(m, b)] = true;
//		}
//	}
//	double m = (double)(points[1].second - points[0].second) / (points[1].first - points[0].first);
//	double b = points[0].second - m * points[0].first;
//	bool s = true;
//	FOR(j, 0, n)
//	{
//		double x1 = points[j].first;
//		double y1 = points[j].second;
//		double x2, y2;
//		if (b > INF || b < -INF)
//		{
//			y2 = y1;
//			if (x1 < points[0].first)
//			{
//				x2 = points[0].first + (points[0].first - x1);
//			}
//			else
//			{
//				x2 = points[0].first - (x1 - points[0].first);
//			}
//		}
//		else
//		{
//			double d = (x1 + (y1 - b)*m) / (1 + m * m);
//			x2 = 2 * d - x1;
//			y2 = 2 * d * m - y1 + 2 * b;
//		}
//		if (!dequals(round(x2), x2) || !dequals(round(y2), y2) || !exists[make_pair((int)round(x2), (int)round(y2))])
//		{
//			s = false;
//			break;
//		}
//	}
//	m = round(m * 100) / 100;
//	b = round(b * 100) / 100;
//	if (m > INF || m < -INF)
//	{
//		m = INF;
//	}
//	if (b > INF || b < -INF)
//	{
//		b = INF;
//	}
//	if (s && !counted[make_pair(m, b)])
//	{
//		ans++;
//		counted[make_pair(m, b)] = true;
//	}
//	cout << ans << endl;
//}
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
#include <map>
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
pii points[1001];
map<pii, bool> exists;
vector<pair<double, double> > counted;
bool dequals(double a, double b)
{
	return fabs(a- b) < 1e-7;
}
int main()
{
	freopen("symmetry.in", "r", stdin);
	freopen("symmetry.out", "w", stdout);
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		cin >> points[i].first >> points[i].second;
		exists[make_pair(points[i].first, points[i].second)] = true;
	}
	int ans = 0;
	FOR(i, 0, n)
	{
		FOR(j, i + 1, n)
		{
			double x = (double)(points[i].first + points[j].first) / 2;
			double y = (double)(points[i].second + points[j].second) / 2;
			double m = (double)(points[i].second - points[j].second) / (points[i].first - points[j].first);
			m = -1 / m;
			double b = y - m * x;
			bool s = true;
			if (m > INF || m < -INF)
			{
				m = INF;
				b = x;
			}
			FOR(k, 0, n)
			{
				double x1 = points[k].first;
				double y1 = points[k].second;
				double x2, y2;
				if (points[i].second - points[j].second == 0)
				{
					y2 = y1;
					if (x1 < x)
					{
						x2 = x + (x - x1);
					}
					else
					{
						x2 = x - (x1 - x);
					}
				}
				else
				{
					double d = (x1 + (y1 - b) * m) / (1 + m * m);
					x2 = 2 * d - x1;
					y2 = 2 * d * m - y1 + 2 * b;
				}
				if (!dequals(round(x2), x2) || !dequals(round(y2), y2) || !exists[make_pair((int)round(x2), (int)round(y2))])
				{
					s = false;
					break;
				}
			}
			if (s)
			{
				bool contains = false;
				FOR(i, 0, counted.size())
				{
					if (dequals(counted[i].first, m) && dequals(counted[i].second, b))
					{
						contains = true;
						break;
					}
				}
				if (!contains)
				{
					ans++;
					counted.push_back(make_pair(m, b));
				}
			}
		}
	}
	cout << ans << endl;
}