#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    long long n = inf.readLong(1, 1000000000000000000LL, "n");
    inf.readEoln();
    string s = inf.readToken();
    inf.readEoln();
    string t = inf.readToken();
    inf.readEoln();
    inf.readEof();
    ensuref(s.length() >= 1 && s.length() <= 50, "S too long");
    ensuref(t.length() >= 1 && t.length() <= 1000, "T too long");
    for(int i = 0; i < s.length(); i++){
        ensuref(s[i] >= 'a' && s[i] <= 'e', "invalid characters");
    }
    for(int i = 0; i < t.length(); i++){
        ensuref(t[i] >= 'a' && t[i] <= 'e', "invalid characters");
    }
}
