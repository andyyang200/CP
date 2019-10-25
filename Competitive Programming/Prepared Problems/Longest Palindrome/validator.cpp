#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", z = " << z << endl
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    string s = inf.readToken();
    ensuref(s.length() <= 100000, "string too long");
    for(int i = 0; i < s.length(); i++){
        ensuref(s[i] >= 'a' && s[i] <= 'z', "invalid characters");
    }
    inf.readEoln();
    inf.readEof();
}
