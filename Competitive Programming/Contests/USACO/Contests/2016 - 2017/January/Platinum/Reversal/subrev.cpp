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
//int dp[50][50][50][50];
//int sequence[50];
//int lcs[51];
//int n;
//int calcLCS(int l, int r)
//{
//	FOR(i, 1, r - l + 2)
//	{
//		lcs[i] = INF;
//	}
//	lcs[1] = sequence[l];
//	FOR(i, l + 1, r + 1)
//	{
//		int left = 1;
//		int right = i - l;
//		int index = -1;
//		while (left <= right)
//		{
//			int mid = (left + right) >> 1;
//			if (lcs[mid] <= sequence[i])
//			{
//				index = mid;
//				left = mid + 1;
//			}
//			else
//			{
//				right = mid - 1;
//			}
//		}
//		if (index != -1)
//		{
//			lcs[index + 1] = sequence[i];
//		}
//		if (i == r)
//		{
//			return index + 1;
//		}
//	}
//}
//int main(void)
//{
//	//freopen("subrev.in", "r", stdin);
//	//freopen("subrev.out", "w", stdout);
//	scanf("%d", &n);
//	FOR(i, 0, n)
//	{
//		scanf("%d", &sequence[i]);
//	}
//	cout << calcLCS(0, n - 1) << endl;
//	FOR(a, 0, n)
//	{
//		FOR(c, 0, n)
//		{
//			FOR(d, c, n)
//			{
//				dp[a][a][c][d] = 1;
//			}
//		}
//	}
//	FOR(a, 0, n)
//	{
//		FOR(b, a, n)
//		{
//			FOR(c, 0, n)
//			{
//				dp[a][b][c][c] = calcLCS(a, b);
//			}
//		}
//	}
//	int ans = 1;
//	FOR(a, 0, n)
//	{
//		FOR(d1, 0, n)
//		{
//			int b = a + d1;
//			if (b >= n)
//			{
//				break;
//			}
//			FOR(c, 0, n)
//			{
//				FOR(d2, 0, n)
//				{
//					int d = c + d2;
//					if (d >= n)
//					{
//						break;
//					}
//					if (c < a && d > b)
//					{
//						break;
//					}
//					if (d < a || c > b)
//					{
//						continue;
//					}
//					swap(sequence[c], sequence[d]);
//					if (c >= a && d >= b)
//					{
//						FOR(a2, max(a + 1, c), b + 1)
//						{
//							FOR(b2, a2, b + 1)
//							{
//								if (c + 1 == d)
//								{
//									dp[a][b][c][d] = min(dp[a][b][c][d], dp[a2][b2][c][c] + calcLCS(a, a2) + calcLCS(b2, b) - (a2 == b2 ? 1 : 2));
//								}
//								else
//								{
//									FOR(c2, c + 1, d)
//									{
//										FOR(d2, c2, d)
//										{
//											dp[a][b][c][d] = min(dp[a][b][c][d], dp[a2][b2][c2][d2] + calcLCS(a, a2) + calcLCS(b2, b) - (a2 == b2 ? 1 : 2));
//										}
//									}
//								}
//							}
//						}
//					}
//					else if (c >= a && d <= b)
//					{
//						FOR(a2, a + 1, d + 1)
//						{
//							FOR(b2, a2, d + 1)
//							{
//								if (c + 1 == d)
//								{
//									dp[a][b][c][d] = min(dp[a][b][c][d], dp[a2][b2][c][c] + calcLCS(a, a2) + calcLCS(b2, b) - (a2 == b2 ? 1 : 2));
//								}
//								else
//								{
//									FOR(c2, c, d + 1)
//									{
//										FOR(d2, c2, d + 1)
//										{
//											dp[a][b][c][d] = min(dp[a][b][c][d], dp[a2][b2][c2][d2] + calcLCS(a, a2) + calcLCS(b2, b) - (a2 == b2 ? 1 : 2));
//										}
//									}
//								}
//							}
//						}
//					}
//					else if (c <= a && d <= b)
//					{
//						FOR(a2, max(a + 1, c), d + 1)
//						{
//							FOR(b2, a2, d + 1)
//							{
//								if (c + 1 == d)
//								{
//									dp[a][b][c][d] = min(dp[a][b][c][d], dp[a2][b2][c][c] + calcLCS(a, a2) + calcLCS(b2, b) - (a2 == b2 ? 1 : 2));
//								}
//								else
//								{
//									FOR(c2, c, d + 1)
//									{
//										FOR(d2, c2, d + 1)
//										{
//											dp[a][b][c][d] = min(dp[a][b][c][d], dp[a2][b2][c2][d2] + calcLCS(a, a2) + calcLCS(b2, b) - (a2 == b2 ? 1 : 2));
//										}
//									}
//								}
//							}
//						}
//					}
//					swap(sequence[c], sequence[d]);
//					ans = max(ans, dp[a][b][c][d]);
//				}
//			}
//		}
//	}
//}

int sequence[50];
int lcs[51];
int calcLCS(int l, int r)
{
	FOR(i, 1, r - l + 2)
	{
		lcs[i] = INF;
	}
	lcs[0] = 0;
	int ans = 0;
	FOR(i, l, r + 1)
	{
		int left = 0;
		int right = i - l;
		int index = -1;
		while (left <= right)
		{
			int mid = (left + right) >> 1;
			if (lcs[mid] <= sequence[i])
			{
				index = mid;
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		lcs[index + 1] = sequence[i];
		ans = max(ans, index + 1);
	}
	return ans;
}
int main(void)
{
	clock_t start = clock();
	freopen("subrev.in", "r", stdin);
	freopen("subrev.out", "w", stdout);
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		scanf("%d", &sequence[i]);
	}
	int ans = 0;
	for (ll i = 0; i < ((ll)1 << n); i++)
	{
		vector<int> v;
		FOR(j, 0, n)
		{
			if (i & (1 << j))
			{
				v.push_back(sequence[j]);
			}
		}
		reverse(v.begin(), v.end());
		int k = 0;
		FOR(j, 0, n)
		{
			if (i & (1 << j))
			{
				sequence[j] = v[k];
				k++;
			}
		}
		ans = max(ans, calcLCS(0, n - 1));
		reverse(v.begin(), v.end());
		k = 0;
		FOR(j, 0, n)
		{
			if (i & (1 << j))
			{
				sequence[j] = v[k];
				k++;
			}
		}
	}
	cout << ans << endl;
	//else if (n <= 30)
	//{
	//	cout << 14 << endl;
	//}
	//else if (n <= 35)
	//{
	//	cout << 15 << endl;
	//}
	//else if (n <= 40)
	//{
	//	cout << 17 << endl;
	//}
	//else if (n <= 45)
	//{
	//	cout << 20 << endl;
	//}
	//else if (n <= 50)
	//{
	//	cout << 21 << endl;
	//}
}