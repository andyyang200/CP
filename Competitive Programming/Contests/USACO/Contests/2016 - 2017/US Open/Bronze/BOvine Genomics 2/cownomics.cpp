
#include <sstream>
#include <iostream>
using namespace std;
bool seen[26];
string a[200];
char c[] = { 'A', 'C', 'G', 'T' };
int main(void)
{
	//freopen("cownomics.in", "r", stdin);
	//freopen("cownomics.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < 2 * n; i++)
	{
		cin >> a[i];
	}
	int ans = 0;
	for (int j = 0; j < m; j++)
	{
		memset(seen, 0, sizeof(bool) * sizeof(seen));
		for (int i = 0; i < n; i++)
		{
			seen[a[i][j] - 'A'] = true;
		}
		bool okay = true;
		for (int k = 0; k < 4; k++)
		{

		}
	}
}