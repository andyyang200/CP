#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
set<int>Set;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(2, 15, "n");
    inf.readEoln();
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            int v = inf.readInt(1, (int)1e9, "a_ij");
            if(j == n-1) inf.readEoln(); else inf.readSpace();
        }
    }
    inf.readEof();
}
