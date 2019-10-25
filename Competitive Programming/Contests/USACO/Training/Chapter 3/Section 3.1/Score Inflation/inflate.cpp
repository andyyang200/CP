/*
ID: andyyang200
PROG: inflate
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
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

using namespace std;
int maxScore[10001];

int main()
{
	ifstream fin("inflate.in");
	ofstream fout("inflate.out");
	int M, N;
	fin >> M >> N;
	int max = 0;
	for (int x = 0; x < N; x++)
	{
		int score, minutes;
		fin >> score >> minutes;
		for (int i = minutes; i <= M; i++)
		{
			if (maxScore[i - minutes] + score > maxScore[i])
			{
				maxScore[i] = maxScore[i - minutes] + score;
			}
		}
	}
	fout << maxScore[M] << endl;
}