//accepted
#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
const int N = 3e5 + 500;
int n, m, p[N], ra[N], dir[N], ans[N];
bool cmp(int x, int y) 
{ 
	return p[x] < p[y]; 
}
ll s;
int main() 
{
	scanf("%d%d%I64d", &n, &m, &s);
	rep(i, 0, n - 1) 
	{
		char ch[10]; 
		scanf("%d %s", p + i, ch);
		--p[i]; 
		ra[i] = i;
		dir[i] = ch[0] == '2' ? -1 : 1;
	}
	sort(ra, ra + n, cmp);
	int t = 0;
	rep(i, 0, n - 1) 
	{
		if (dir[i] == 1) 
			t += (p[i] + s) / m%n;
		else 
			t += (p[i] - s - m + 1) / m%n;
		t = (t%n + n) % n;
		p[i] = p[i] + s%m*dir[i];
		p[i] = (p[i] % m + m) % m;
	}
	sort(p, p + n);
	rep(i, 0, n - 1) 
		ans[ra[(i + n - t) % n]] = p[i] + 1;
	rep(i, 0, n - 1) 
		printf("%d%c", ans[i] % m, i == n - 1 ? '\n' : ' ');
	return 0;
}