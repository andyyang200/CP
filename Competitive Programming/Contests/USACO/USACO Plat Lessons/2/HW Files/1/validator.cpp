#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

#define INF 1000000000

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int q = inf.readInt(1, 50000, "q");
    inf.readEoln();
    for(int i = 0; i < q; i++){
        int t = inf.readInt(1, 2, "t");
        inf.readSpace();
        if (t == 1){
            int x = inf.readInt(-INF, INF, "x");
            inf.readSpace();
            int y = inf.readInt(-INF, INF, "y");
            inf.readSpace();
            int v = inf.readInt(-INF, INF, "v");
            inf.readEoln();
        }
        else if (t == 2){
            int x1 = inf.readInt(-INF, INF, "x1");
            inf.readSpace();
            int x2 = inf.readInt(-INF, INF, "x2");
            inf.readSpace();
            int y1 = inf.readInt(-INF, INF, "y1");
            inf.readSpace();
            int y2 = inf.readInt(-INF, INF, "y2");
            inf.readEoln();
        }
    }
    inf.readEof();
}
