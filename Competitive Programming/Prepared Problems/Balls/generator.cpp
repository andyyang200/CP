#include "testlib.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<int, bool> m;
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int n = atoi(argv[1]);
	int q = atoi(argv[2]);
	int p = atoi(argv[3]);
	printf("%d %d %d\n", n, q, p);

	for (int i = 0; i < n; i++) {
		int x = rnd.next(0, p - 1);
		while (m[x]) {
			x = rnd.next(0, p - 1);
		}
		m[x] = true;
		if (i > 0) {
			cout << " ";
		}
		cout << x;
	}
	cout << endl;
	for (int i = 0; i < q; i++) {
		int t = rnd.next(1, 2);
		cout << t;
		if (t == 1) {
			printf(" %d", rnd.next(0, p - 1));
		}
		cout << endl;
	}
}


