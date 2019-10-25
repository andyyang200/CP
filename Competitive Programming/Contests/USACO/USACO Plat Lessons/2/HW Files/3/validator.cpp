#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[])
{
    registerValidation(argc, argv);

    int m = inf.readInt(1, 20, "m");
    inf.readSpace();
    int n = inf.readInt(1, 1 << m, "n");
    inf.readEoln();
    set<string> se;
    for(int i = 0; i < n; i++){
        string s = inf.readToken();
        inf.readEoln();
        ensuref(s.length() == m, "must be length m");
        for(int j = 0; j < m; j++){
            ensuref(s[j] == '0' || s[j] == '1', "must be binary string");
        }
        se.insert(s);
    }
    ensuref(se.size() == n, "must be unique");
    inf.readEof();
}
