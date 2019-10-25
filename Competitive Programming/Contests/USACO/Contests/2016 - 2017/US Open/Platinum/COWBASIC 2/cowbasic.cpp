//Andrew Yang
#include <cctype>
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

char l[350];
bool read()
{
	char *e;
	e = fgets(l, sizeof(l), stdin);
	return e != NULL;
}
bool isI(const string & s)
{
	if (s.empty() || ((s[0] != '-') && (s[0] != '+') && (!isdigit(s[0]))))
	{
		return false;
	}
	char * p;
	strtol(s.c_str(), &p, 10);
	return (*p == 0);
}
string & tr(string & s)
{
	auto it1 = find_if(s.rbegin(), s.rend(), [](char ch) { return !(isspace(ch) || ch == '(' || ch == ')'); });
	s.erase(it1.base(), s.end());
	auto it2 = find_if(s.begin(), s.end(), [](char ch) { return !(isspace(ch) || ch == '(' || ch == ')'); });
	s.erase(s.begin(), it2);
	return s;
}
vector<int> vars;
map<string, int> m;
int getV(string v)
{
	v = tr(v);
	auto itr = m.find(v);
	if (itr == m.end())
	{
		vars.push_back(0);
		m[v] = vars.size() - 1;
	}
	return m[v];
}
vector<string> cut(const char *s, char c = ' ')
{
	vector<string> v;
	do
	{
		const char *begin = s;
		while (*s != c && *s)
		{
			s++;
		}
		v.push_back(string(begin, s));
	} while (0 != *s++);
	return v;
}
void one(vector<vector<ll>>& a)
{
	int sz = a.size();
	FOR(i, 0, sz)
	{
		FOR(j, 0, sz)
		{
			a[i][j] = (i == j) ? 1 : 0;
		}
	}
}	
void mmul(vector<vector<ll>>& a, vector<vector<ll>>& b)
{
	int sz = a.size();
	vector<ll> line(sz, 0);
	vector<vector<ll>> res(sz, line);
	FOR(i, 0, sz)
	{
		FOR(j, 0, sz)
		{
			FOR(k, 0, sz)
			{
				res[i][j] += a[i][k] * b[k][j] % M;
			}
		}
	}
	FOR(i, 0, sz)
	{
		FOR(j, 0, sz)
		{
			a[i][j] = res[i][j] % M;
		}
	}
}
void mpow(vector<vector<ll>>& a, int n, vector<vector<ll>>& res)
{
	one(res);
	while (n > 0) 
	{
		if (n % 2 == 0)
		{
			mmul(a, a);
			n /= 2;
		}
		else 
		{
			mmul(res, a);
			n--;
		}
	}
}
void build(vector<vector<ll>>& a)
{
	int sz = vars.size() + 1;
	vector<ll> l(sz, 0);
	vector<vector<ll>> res(sz, l);
	a = res;
}
struct Statement
{
	vector<vector<ll>> mat;
	virtual bool isR() { return false; }
	virtual void go() {
		build(mat);
		FOR(i, 0, mat.size())
		{
			mat[i][i] = 1;
		}
	}
	
};
struct Token
{
	bool isL;
	int v;
	int vI;
	Token(string t)
	{
		t = tr(t);
		if (isI(t))
		{
			isL = true;
			v = stoi(t);
		}
		else
		{
			isL = false;
			vI = getV(t);
		}
	}
	
};
struct Expression
{
	vector<Token> ts;
};
struct Assignment : public Statement
{
	int at;
	Expression e;
	virtual void go()
	{
		Statement::go();
		vector<ll>& x = mat[at];
		FOR(i, 0, x.size())
		{
			x[i] = 0;
		}
		for (auto& t : e.ts)
		{
			if (t.isL)
			{
				x[x.size() - 1] += t.v;
			}
			else
			{
				x[t.vI] ++;

			}
		}
	}
};

ll powmod(ll a, ll b)
{
	ll res = 1;
	a %= M;
	for (; b; b >>= 1)
	{
		if (b & 1)
		{
			res = res * a % M;
		}
		a = a *a % M;
	}
	return res;
}

struct Return : public Statement
{
	int i;
	virtual bool isR() { return true; }
};
struct Loop : public Statement
{
	int cnt;
	vector<Statement*> ss;
	virtual void go()
	{
		Statement::go();
		for (auto& s : ss)
		{
			s->go();
			vector<vector<ll>> tmp = s->mat;
			mmul(tmp, mat);
			mat = tmp;
		}
		vector<vector<ll>> res;
		build(res);
		mpow(mat, cnt, res);
		mat = res;
	}
};
int main(void)
{
	freopen("cowbasic.in", "r", stdin);
	freopen("cowbasic.out", "w", stdout);
	vector<Statement*> p;
	stack<Loop*> lp;
	while (read())
	{
		char* c = strstr(l, "RETURN");
		if (c != NULL)
		{
			Return* r = new Return;
			r->i = getV(c + 6);
			p.push_back(r);
			break;
		}
		c = strstr(l, "MOO {");
		if (c != NULL)
		{
			Loop* lo = new Loop();
			lo->cnt = stoi(l);
			lp.push(lo);
			continue;
		}
		string l2(l);
		l2 = tr(l2);
		if (l2 == "}")
		{
			Loop* l = lp.top();
			lp.pop();
			if (lp.empty())
			{
				p.push_back(l);
			}
			else
			{
				lp.top()->ss.push_back(l);
			}
		}
		 c = strchr(l, '=');
		if (c != NULL)
		{	
			string at;
			at.assign(l, c - l);
			at = tr(at);
			vector<string> ts = cut(c + 1, '+');
			Expression e;
			FOR(i, 0, ts.size())
			{
				e.ts.push_back(Token(ts[i]));
			}
			Assignment* a = new Assignment();
			a->at = getV(at);
			a->e = e;
			if (lp.empty())
			{
				p.push_back(a);
			}
			else
			{
				lp.top()->ss.push_back(a);
			}
			continue;
		}
	}
	vector<vector<ll>> res;
	build(res);
	one(res);
	FOR(i, 0, p.size())
	{
		if (p[i]->isR())
		{
			Return * r = (Return*)p[i];
			cout << res[r->i][vars.size()] << endl;
			break;
		}
		p[i]->go();
		vector<vector<ll>> tmp = p[i]->mat;
		mmul(tmp, res);
		res = tmp;
	}
}