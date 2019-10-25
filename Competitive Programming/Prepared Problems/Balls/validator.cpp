#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long ll;
int main(int argc, char* argv[]) {
	registerValidation(argc, argv);
	int N = inf.readInt(1, 100000, "N");
	inf.readSpace();
	int Q = inf.readInt(1, 100000, "Q");
	inf.readSpace();
	int P = inf.readInt(N, 1000000000, "P");
	inf.readEoln();
	map<int, bool> has;
	for (int i = 0; i < N; ++i) {
		if (i) inf.readSpace();
		int p = inf.readInt(0, P - 1, "w");
		ensuref(!has.count(p), "Positions not distinct");
		has[p] = true;
	}
	inf.readEoln();
	for (int i = 0; i < Q; ++i) {
		int t = inf.readInt(1, 2, "t");
		if (t == 1) {
			inf.readSpace();
			int x = inf.readInt(0, P - 1, "x");
		}
		inf.readEoln();
	}
	inf.readEof();
}

