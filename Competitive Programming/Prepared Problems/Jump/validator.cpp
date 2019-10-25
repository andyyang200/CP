#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int maxN = 100000;
    int n = inf.readInt(2, maxN, "n");
    inf.readSpace();
    int t = inf.readInt(1, n - 1, "t");
    inf.readEoln();
    for (int i = 0; i < n; i++) {
        inf.readInt(1, n - 1, "a[i]");
        if (i + 1 != n) {
            inf.readSpace();
        }
    }
    inf.readEoln();
    inf.readEof();
}
