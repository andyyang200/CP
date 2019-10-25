// Suffix Array
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 200000

string T;
int n;

int RA[MAX_N], tempRA[MAX_N]; // 1-indexed
int SA[MAX_N], tempSA[MAX_N];

int c[MAX_N];
int lcp[MAX_N];
void constructLCP() {
	int k = 0;
	for (int i = 0; i<n; i++)
		RA[SA[i]] = i;
	for (int i = 0; i<n; i++, k ? k-- : 0){
		if (RA[i] == n) {
			k = 0;
			continue;
		}
		int j = SA[RA[i] + 1];
		while (i + k < n && j + k < n && T[i + k] == T[j + k])
			k++;
		lcp[RA[i]] = k;
	}
}
void countingSort(int k) {
	int i, sum, maxi = max(300, n);
	memset(c, 0, sizeof c);
	for (i = 0; i < n; i++)
		c[i + k < n ? RA[i + k] : 0]++;
	for (i = sum = 0; i < maxi; i++) {
		int t = c[i]; c[i] = sum; sum += t;
	}
	for (i = 0; i < n; i++)
		tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
	for (i = 0; i < n; i++)
		SA[i] = tempSA[i];
}

void constructSA() {
	int i, k, r;
	for (i = 0; i < n; i++) RA[i] = T[i];
	for (i = 0; i < n; i++) SA[i] = i;
	for (k = 1; k < n; k <<= 1) {
		countingSort(k);
		countingSort(0);
		tempRA[SA[0]] = r = 1;
		for (i = 1; i < n; i++)
			tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
		for (i = 0; i < n; i++)
			RA[i] = tempRA[i];
		if (RA[SA[n - 1]] == n) break;
	}
}
int main(void)
{
	T = "aaabba";
	n = T.length();
	constructSA();
	for(int i = 0; i < n; i++) {
		cout << SA[i] << " ";
	}
	cout << endl;
	constructLCP();
    for(int i = 0; i < n; i++) {
		cout << lcp[i] << " ";
	}
	cout << endl;

}




/* O(Nlog^2N)

const int MAXP = 17;
char S[100005];
int N;
pair<pair<int, int>, int> T[100005];
int sufrank[MAXP + 1][100005];
// rank[i] is the rank of i-th suffix
void getSuffixArray() {
    for (int i = 0; i < N; ++i) sufrank[0][i] = S[i];
    for (int l = 1; l <= MAXP; ++l) {
        int len = 1 << (l - 1);
        for (int i = 0; i < N; ++i) {
            int nex = i + len < N ? sufrank[l - 1][i + len] : -1;
            T[i] = {{sufrank[l - 1][i], nex}, i};
        }
        sort(T, T + N);
        for (int i = 0; i < N; ++i) {
            if (i && T[i].first == T[i - 1].first)
                sufrank[l][T[i].second] = sufrank[l][T[i - 1].second];
            else sufrank[l][T[i].second] = i;
        }
    }
}

*/


