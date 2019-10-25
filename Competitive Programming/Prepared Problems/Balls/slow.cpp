#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n, q, p;
	scanf("%d%d%d", &n, &q, &p);
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < q; i++) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int x;
			scanf("%d", &x);
			if (find(v.begin(), v.end(), x) == v.end()) {
				v.push_back(x);
				sort(v.begin(), v.end());
			}
		}
		else {
			for (int i = 0; i < v.size() - 1; i++) {
				v[i] = v[i + 1] - 1;
			}
			v[v.size() - 1] = p - 1;
		}
	}
	for (int x : v) {
		printf("%d ", x);
	}
	printf("\n");
}
