#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 100000, "n");
    inf.readEoln();
    for(int i = 0; i < n; i++){
        int x1 = inf.readInt(-100000000, 100000000);
        inf.readSpace();
        int y1 = inf.readInt(-100000000, 100000000);
        inf.readSpace();
        int x2 = inf.readInt(-100000000, 100000000);
        inf.readSpace();
        int y2 = inf.readInt(-100000000, 100000000);
        inf.readEoln();
        ensure(x1 != x2);
        ensure(y1 != y2);
    }

    inf.readEof();
}
