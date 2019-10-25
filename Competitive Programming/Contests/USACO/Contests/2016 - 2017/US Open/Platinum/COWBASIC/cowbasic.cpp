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
	char *eof;
	eof = fgets(l, sizeof(l), stdin);
	return eof != NULL;
}
bool isI(const string & s)
{
	if (s.empty() || ((s[0] != '-') && (s[0] != '+') && (!isdigit(s[0]))))
	{
		return false;
	}
	char * p;
	strtol(s.c_str(), &p, 10);
	return *p == 0;
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
struct Statement
{
	virtual void go() {};
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

	int getValue()
	{
		if (isL)
			return v;
		return vars[vI];
	}
};

struct Expression
{
	vector<Token> ts;
	int evaluate()
	{
		int x = 0;
		for (auto& t : ts)
		{
			x += t.getValue();
			x %= M;
		}
		return x;
	}
};


struct Assignment : public Statement
{
	int at;
	Expression e;
	virtual void go()
	{
		vars[at] = e.evaluate();
	}
};

ll powmod(ll a, ll b)
{
	ll ans = 1;
	a %= M;
	for (; b; b >>= 1)
	{
		if (b & 1)
			ans = ans * a % M;
		a = a *a % M;
	}
	return ans;
}
struct Return : public Statement
{
	int i;
	void go()
	{
		cout << vars[i] << endl;
		exit(0);
	}
};
struct Loop : public Statement
{
	int cnt;
	vector<Statement*> ss;
	void go()
	{
		FOR(i, 0, cnt)
		{
			for (auto& s : ss)
			{
				s->go();
			}
		}
	}
};


int main(void)
{
	freopen("cowbasic.in", "r", stdin);
	freopen("cowbasic.out", "w", stdout);
	stack<Loop*> lp;
	vector<Statement*> p;
	while (read())
	{
		char* eq = strchr(l, '=');
		if (eq != NULL)
		{
			string at;
			at.assign(l, eq - l);
			at = tr(at);

			vector<string> tokens = cut(eq + 1, '+');
			Expression e;
			FOR(i, 0, tokens.size())
			{
				e.ts.push_back(Token(tokens[i]));
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
		char* ret = strstr(l, "RETURN");
		if (ret != NULL)
		{
			Return* r = new Return;
			r->i = getV(ret + 6);
			p.push_back(r);
			break;
		}
		char* moo = strstr(l, "MOO {");
		if (moo != NULL)
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
			Loop* lo = lp.top();
			lp.pop();
			if (!lp.empty())
			{
				lp.top()->ss.push_back(lo);
			}
			else
			{
				p.push_back(lo);
			}
		}
	}
	FOR(i, 0, p.size())
	{
		p[i]->go();
	}
	return 0;
}