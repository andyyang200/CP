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
typedef long long ll;
typedef pair<int, int> pii;
#define MAXN 501
#define MAXK 100
char original[MAXN][MAXN];
char pieces[MAXK][MAXN][MAXN];
bool matched[MAXN][MAXN];
int weight[MAXK][26];
int weight0[26];
int n, m, k;
bool used[MAXK][MAXK][MAXK];
void shiftLeft(char mat[][MAXN], int x)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j + x < n)
			{
				mat[i][j] = mat[i][j + x];
			}
			else
			{
				mat[i][j] = '.';
			}
		}
	}
}
void shiftRight(char mat[][MAXN], int x)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			if (j - x >= 0)
			{
				mat[i][j] = mat[i][j - x];
			}
			else
			{
				mat[i][j] = '.';
			}
		}
	}
}
void shiftUp(char mat[][MAXN], int x)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i + x < n)
			{
				mat[i][j] = mat[i + x][j];
			}
			else
			{
				mat[i][j] = '.';
			}
		}
	}
}
void shiftDown(char mat[][MAXN], int x)
{
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < n; j++)
		{
			if (i - x >= 0)
			{
				mat[i][j] = mat[i - x][j];
			}
			else
			{
				mat[i][j] = '.';
			}
		}
	}
}
void flipVert(char mat[][MAXN])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n / 2; j++)
		{
			swap(mat[i][j], mat[i][n - 1 - j]);
		}
	}
}
void flipHori(char mat[][MAXN])
{
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			swap(mat[i][j], mat[n - i - 1][j]);
		}
	}
}
void rotate(char mat[][MAXN])
{
	int f = floor((double)n / 2);
	int c = ceil((double)n / 2);
	FOR(x, 0, f)
	{
		FOR(y, 0, c)
		{
			int temp = mat[x][y];
			mat[x][y] = mat[y][n - 1 - x];
			mat[y][n - 1 - x] = mat[n - 1 - x][n - 1 - y];
			mat[n - 1 - x][n - 1 - y] = mat[n - 1 - y][x];
			mat[n - 1 - y][x] = temp;
		}
	}
}
bool canMatch;
void match(char mat[][MAXN])
{
	int r1 = -1;
	int c1 = -1;
	int r2 = -1;
	int c2 = -1;
	FOR(i, 0, n)
	{
		if (r1 != -1)
		{
			break;
		}
		FOR(j, 0, n)
		{
			if (r1 != -1)
			{
				break;
			}
			if (original[i][j] != '.' && !matched[i][j])
			{
				r1 = i;
				c1 = j;
			}
		}
	}
	int minC = MAXN;
	int maxC = 0;
	int minR = MAXN;
	int maxR = 0;
	FOR(i, 0, n)
	{
		FOR(j, 0, n)
		{
			if (mat[i][j] != '.')
			{
				if (r2 == -1)
				{
					r2 = i;
					c2 = j;
				}
				minC = min(minC, j);
				maxC = max(maxC, j);
				minR = min(minR, i);
				maxR = max(maxR, i);
			}
		}
	}
	if (original[r1][c1] != mat[r2][c2])
	{
		canMatch = false;
		return;
	}
	int dR = r1 - r2;
	int dC = c1 - c2;
	if (dC < 0)
	{
		dC *= -1;
		if (minC - dC < 0)
		{
			canMatch = false;
			return;
		}
		shiftLeft(mat, dC);
	}
	else
	{
		if (maxC + dC >= n)
		{
			canMatch = false;
			return;
		}
		shiftRight(mat, dC);
	}
	if (dR < 0)
	{
		dR *= -1;
		if (minR - dR < 0)
		{
			canMatch = false;
			return;
		}
		shiftUp(mat, dR);
	}
	else
	{
		if (maxR + dR >= n)
		{
			canMatch = false;
			return;
		}
		shiftDown(mat, dR);
	}
	FOR(i, 0, n)
	{
		FOR(j, 0, n)
		{
			if (mat[i][j] != '.')
			{
				if (original[i][j] == mat[i][j] && !matched[i][j])
				{
					matched[i][j] = true;
				}
				else
				{
					canMatch = false;
					return;
				}
			}
		}
	}
}
char temp[MAXN][MAXN];
int main()
{
	freopen("bcs.in", "r", stdin);
	freopen("bcs.out", "w", stdout);
	scanf("%d%d%d", &k, &n, &m);
	int shiftLeftNeeded = MAXN;
	int shiftUpNeeded = MAXN;
	FOR(i, 0, n)
	{
		scanf("%s", original[i]);
		FOR(j, 0, max(n, m))
		{
			if (original[i][j] != '.')
			{
				weight0[original[i][j] - 'a']++;
				shiftLeftNeeded = min(shiftLeftNeeded, j);
				shiftUpNeeded = min(shiftUpNeeded, i);
			}
		}
	}
	n = max(n, m);
	shiftLeft(original, shiftLeftNeeded);
	shiftUp(original, shiftUpNeeded);
	FOR(x, 0, k)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		FOR(i, 0, a)
		{
			scanf("%s", pieces[x][i]);
			FOR(j, b, n)
			{
				pieces[x][i][j] = '.';
			}
			FOR(j, 0, b)
			{
				if (pieces[x][i][j] != '.')
				{
					weight[x][pieces[x][i][j] - 'a']++;
				}
			}
		}
		FOR(i, a, n)
		{
			FOR(j, 0, n)
			{
				pieces[x][i][j] = '.';
			}
		}
	}
	int ans = 0;
	FOR(x, 0, k)
	{
		bool bad = false;
		FOR(i, 0, 26)
		{
			if (weight[x][i] >  weight0[i])
			{
				bad = true;
				break;
			}
		}
		FOR(y, 0, k)
		{
			bool bad = false;
			FOR(i, 0, 26)
			{
				if (weight[x][i] + weight[y][i] > weight0[i])
				{
					bad = true;
					break;
				}
			}
			if (bad)
			{
				continue;
			}
			FOR(z, 0, k)
			{
				if (x == z || y == z)
				{
					continue;
				}
				bool bad = false;
				FOR(i, 0, 26)
				{
					if (weight[x][i] + weight[y][i] + weight[z][i] != weight0[i])
					{
						bad = true;
						break;
					}
				}
				FOR(flipX, 0, 3)
				{
					if (flipX == 1)
					{
						flipVert(pieces[x]);
					}
					else if (flipX == 2)
					{
						flipHori(pieces[x]);
					}
					FOR(rotateX, 0, 4)
					{
						rotate(pieces[x]);
						if (bad)
						{
							continue;
						}
						if (x == y)
						{
							continue;
						}
						FOR(flipY, 0, 3)
						{
							if (flipY == 1)
							{
								flipVert(pieces[y]);
							}
							else if (flipY == 2)
							{
								flipHori(pieces[y]);
							}
							FOR(rotateY, 0, 4)
							{
								rotate(pieces[y]);
								if (bad)
								{
									continue;
								}
								FOR(flipZ, 0, 3)
								{
									if (flipZ == 1)
									{
										flipVert(pieces[z]);
									}
									else if (flipZ == 2)
									{
										flipHori(pieces[z]);
									}
									FOR(rotateZ, 0, 4)
									{
										rotate(pieces[z]);
										if (used[x][y][z])
										{
											break;
										}
										FOR(i, 0, n)
										{
											FOR(j, 0, n)
											{
												matched[i][j] = false;
											}
										}
										canMatch = true;
										match(pieces[x]);
										if (!canMatch)
										{
											continue;
										}
										match(pieces[y]);
										if (!canMatch)
										{
											continue;
										}
										match(pieces[z]);
										if (!canMatch)
										{
											continue;
										}
										FOR(i, 0, n)
										{
											if (!canMatch)
											{
												break;
											}
											FOR(j, 0, n)
											{
												if (!canMatch)
												{
													break;
												}
												if (original[i][j] != '.' && !matched[i][j])
												{
													canMatch = false;
												}
											}
										}
										if (canMatch)
										{
											ans++;
											used[x][y][z] = true;
											used[x][z][y] = true;
											used[y][x][z] = true;
											used[y][z][x] = true;
											used[z][x][y] = true;
											used[z][y][x] = true;
										}
									}
									if (flipZ == 1)
									{
										flipVert(pieces[z]);
									}
									else if (flipZ == 2)
									{
										flipHori(pieces[z]);
									}
								}
							}
							if (flipY == 1)
							{
								flipVert(pieces[y]);
							}
							else if (flipY == 2)
							{
								flipHori(pieces[y]);
							}
						}
					}
					if (flipX == 1)
					{
						flipVert(pieces[x]);
					}
					else if (flipX == 2)
					{
						flipHori(pieces[x]);
					}
				}
			}
		}
	}
	cout << ans << endl;
}
/*
4 4 4
xxxx
x..x
x.xx
....
4 4
.x..
.x..
xx..
....
4 4
....
....
....
....
4 4
....
.xxx
.x..
.x..
4 4
xxxx
xx..
x..x
xxxx
*/
/*
*/