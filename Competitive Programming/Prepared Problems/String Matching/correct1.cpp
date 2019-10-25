#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

typedef long long ll;
const int maxn = 2000005;
ll all;
int n, m;
char s[maxn], t[maxn], str[maxn];
int nxt[maxn], mat[maxn];
void getnext(char *s, int n)  {
	int j = -1; nxt[0] = -1;
       for (int i = 1; i < n; i ++)  {
		while (j != -1 && s[j + 1] != s[i]) j = nxt[j];
		if (s[j + 1] == s[i]) j ++;
		nxt[i] = j;
       }
}
void kmp(char *str, int m)  {
	memset(mat, 0, sizeof mat);
	int j = -1;
	for (int i = 0; i < m; i ++)  {
		while (j != -1 && s[j + 1] != str[i]) j = nxt[j];
	       if (s[j + 1] == str[i]) j ++;
       		if (j == n - 1)  mat[i] = 1, j = nxt[j];
	}

}

int main()  {
	scanf("%lld", &all);
	scanf("%s", s);
	scanf("%s", t);
	n = strlen(s);
	m = strlen(t);
	int m2 = m, k = 1;
	while (m < n) m += m2, k ++;
	getnext(s, n);
	if (k > all)  {
		for (int i = 0; i < all * m2; i ++)
			str[i] = t[i % m2];
		kmp(str, (int)(all * m2));
		int ans=0;
		for (int i = 0; i < all * m2; i ++)
			ans += mat[i];
		printf("%d\n", ans);
		return 0;
	}
	for (int i = 0; i < m * 2; i ++)
		str[i] = t[i % m2];
	kmp(str, m * 2);

	ll cnt = all / k;
	int adj = 0, in = 0;
	for (int i = 0; i < m; i ++) in += mat[i];
	for (int i = m; i < 2 * m; i ++)
		if (i - n + 1 < m) adj += mat[i];
	ll ans = (cnt - 1) * adj + cnt * in;
       for (int i = 0; i < (all * m2 % m); i ++)
       	if (mat[i]) ans ++;
	printf("%lld\n", ans);
	return 0;
}
