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
pair<string, int> dictionary[1000000];
bool pairCompare(const pair<string, int>& firstElem, const pair<string, int>& secondElem) {
	return firstElem.first < secondElem.first;
}

int main()
{
	ifstream fin("auto.in");
	ofstream fout("auto.out");
	int w, n;
	fin >> w >> n;
	for (int x = 0; x < w; x++)
	{
		fin >> dictionary[x].first;
		dictionary[x].second = x;
	}
	sort(dictionary, dictionary + w, pairCompare);
	for (int x = 0; x < n; x++)
	{
		int k;
		fin >> k;
		string word;
		fin >> word;
		pair<string, int> st;
		st.first = word;
		int currentIndex = lower_bound(dictionary, dictionary + w, st, pairCompare) - dictionary + k - 1;
		if (currentIndex >= w)
		{
			fout << -1 << endl;
			continue;
		}

		bool found = dictionary[currentIndex].first.compare(0, word.length(), word) == 0;

		if (found)
		{
			fout << dictionary[currentIndex].second + 1 << endl;
		}
		else
		{
			fout << -1 << endl;
		}
	}
}