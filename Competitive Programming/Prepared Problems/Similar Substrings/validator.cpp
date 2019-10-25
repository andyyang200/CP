#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int k = inf.readInt(0, 4000, "k");
    inf.readEoln();
    string s = inf.readToken();
    inf.readEoln();
    string t = inf.readToken();
    inf.readEoln();
    inf.readEof();
    ensuref(s.length() >= 1 && s.length() <= 4000, "S too long");
    ensuref(t.length() >= 1 && t.length() <= 4000, "T too long");
    ensuref(k <= min(s.length(), t.length()), "k too big");
    for(int i = 0; i < s.length(); i++){
        ensuref(s[i] >= 'a' && s[i] <= 'z', "invalid characters");
    }
    for(int i = 0; i < t.length(); i++){
        ensuref(t[i] >= 'a' && t[i] <= 'z', "invalid characters");
    }
}
