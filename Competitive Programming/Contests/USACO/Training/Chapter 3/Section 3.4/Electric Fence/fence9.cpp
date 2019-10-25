/*
ID: andyyan1
PROG: fence9
LANG: C++11
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
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;



double n, m, p;

const double INF = 1E200;
const double EP = 1E-10;
const int MAXV = 300;
const double PI = 3.14159265;
struct POINT
{
	double x;
	double y;
	POINT(double a = 0, double b = 0) { x = a; y = b; }
};
struct LINESEG
{
	POINT s;
	POINT e;
	LINESEG(POINT a, POINT b) { s = a; e = b; }
	LINESEG() { }
};
struct LINE
{
	double a;
	double b;
	double c;
	LINE(double d1 = 1, double d2 = -1, double d3 = 0) { a = d1; b = d2; c = d3; }
};
double dist(POINT p1, POINT p2)
{
	return(sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y)));
}
double multiply(POINT sp, POINT ep, POINT op)
{
	return((sp.x - op.x)*(ep.y - op.y) - (ep.x - op.x)*(sp.y - op.y));
}
double amultiply(POINT sp, POINT ep, POINT op)
{
	return fabs((sp.x - op.x)*(ep.y - op.y) - (ep.x - op.x)*(sp.y - op.y));
}
double dotmultiply(POINT p1, POINT p2, POINT p0)
{
	return ((p1.x - p0.x)*(p2.x - p0.x) + (p1.y - p0.y)*(p2.y - p0.y));
}
bool online(LINESEG l, POINT p)
{
	return (abs(multiply(l.e, p, l.s) <= EP) 
		&& (((p.x - l.s.x) * (p.x - l.e.x) <= EP) && ((p.y - l.s.y)*(p.y - l.e.y) <= EP)));
}

POINT rotate(POINT o, double alpha, POINT p)
{
	POINT tp;
	p.x -= o.x;
	p.y -= o.y;
	tp.x = p.x*cos(alpha) - p.y*sin(alpha) + o.x;
	tp.y = p.y*cos(alpha) + p.x*sin(alpha) + o.y;
	return tp;
}

bool intersect(LINESEG u, LINESEG v)
{
	return ((max(u.s.x, u.e.x) >= min(v.s.x, v.e.x)) &&
		(max(v.s.x, v.e.x) >= min(u.s.x, u.e.x)) &&
		(max(u.s.y, u.e.y) >= min(v.s.y, v.e.y)) &&
		(max(v.s.y, v.e.y) >= min(u.s.y, u.e.y)) &&
		(multiply(v.s, u.e, u.s)*multiply(u.e, v.e, u.s) >= 0) &&
		(multiply(u.s, v.e, v.s)*multiply(v.e, u.e, v.s) >= 0));
}
bool intersect_A(LINESEG u, LINESEG v)
{
	return ((intersect(u, v)) &&
		(!online(u, v.s)) &&
		(!online(u, v.e)) &&
		(!online(v, u.e)) &&
		(!online(v, u.s)));
}

LINE makeline(POINT p1, POINT p2)
{
	LINE tl;
	int sign = 1;
	tl.a = p2.y - p1.y;
	if (tl.a<0)
	{
		sign = -1;
		tl.a = sign*tl.a;
	}
	tl.b = sign*(p1.x - p2.x);
	tl.c = sign*(p1.y*p2.x - p1.x*p2.y);
	return tl;
}
bool lineintersect(LINE l1, LINE l2, POINT &p)
{
	double d = l1.a*l2.b - l2.a*l1.b;
	if (abs(d)<EP)
		return false;
	p.x = (l2.c*l1.b - l1.c*l2.b) / d;
	p.y = (l2.a*l1.c - l1.a*l2.c) / d;
	return true;
}
bool intersection(LINESEG l1, LINESEG l2, POINT &inter)
{
	LINE ll1, ll2;
	ll1 = makeline(l1.s, l1.e);
	ll2 = makeline(l2.s, l2.e);
	if (lineintersect(ll1, ll2, inter)) return online(l1, inter) && online(l2, inter); 
	else return false;
}

void Input()
{
	scanf("%lf%lf%lf", &n, &m, &p);
}

bool isInt(double d)
{
	return (d - (int)d <= EP);
}

void Solve()
{
	int i, maxL, ans = 0;
	LINESEG nmLine, pLine, l;
	POINT inter1, inter2;
	bool interNm, interP;
	int tmp;

	nmLine.s.x = 0;
	nmLine.s.y = 0;
	nmLine.e.x = n;
	nmLine.e.y = m;
	pLine.s.x = p;
	pLine.s.y = 0;
	pLine.e.x = n;
	pLine.e.y = m;
	l.s.y = 0;
	l.e.y = m;

	ans = 0;
	maxL = max(n, p);
	for (i = 1; i < maxL; i++)
	{
		l.s.x = l.e.x = i;
		interNm = intersection(nmLine, l, inter1);
		interP = intersection(pLine, l, inter2);
		if (interNm && !interP)
		{
			ans += floor(inter1.y);
			if (isInt(inter1.y))
				--ans;
		}
		if (!interNm && interP)
		{
			ans += floor(inter2.y);
			if (isInt(inter2.y))
				--ans;
		}
		if (interNm && interP)
		{
			if (inter1.y > inter2.y)
			{
				if (isInt(inter1.y))
					--inter1.y;
				if (isInt(inter2.y))
					++inter2.y;
				tmp = floor(inter1.y) - ceil(inter2.y) + 1;
				if (tmp > 0)
					ans += tmp;
			}
			else
			{
				if (p > n)
					ans += (int)inter1.y - 1;
			}
		}
	}

	printf("%d\n", ans);
}

int main()
{
	freopen("fence9.in", "r", stdin);
	freopen("fence9.out", "w", stdout);

	Input();
	Solve();

	return 0;
}