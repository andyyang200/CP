#include "testlib.h"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
typedef vector<pair<int, int> > Graph;

void error(string s) {
    cerr << s << endl;
    exit(1);
};


int main(int argc, char* argv[])
{

    registerGen(argc, argv, 1);

    if (argc < 1 + 1) {
        error("Usage: gen <test_type> [args...]");
    }

    string t = argv[1];
    int n = atoi(argv[2]);
    int init = -1;
    vector<int> a(n, -1);
    if (t == "random") {
        if (argc < 1 + 2) {
            error("Usage: gen random <n>");
        }
        init = rnd.next(1, n - 1);
        for (int i = 0; i < n; i++) {
            a[i] = rnd.next(1, n - 1);
        }
    }
    else if (t == "smart") {
        if (argc < 1 + 2) {
            error("Usage: gen random <n>");
        }
        if (n < 10) {
            error("(n >= 10) isn't true ");
        }
        init = rnd.next(1, n - 1);

        int pos = rnd.next(1, n / 10 + 1);
        db(pos);
        a[pos] = 1;
        a[0] = pos;
        vector<int> cand;
        for (int i = 0; i < n * 2 / 10; i++) {
            cand.push_back(rnd.next(n / 2, n - 1));
        }
        map<int,int> c;
        int top = min(n - 1, (int)(sqrt(n) * 4));
        for (; (int)cand.size() < n - 2;) {
            for (;;)  {
                int x = rnd.next(2, top);
                if (c.count(x) >= x) continue;
                cand.push_back(x);
                c[x]++;
                break;
            }
        }

        assert((int)cand.size() + 2 == n);
        shuffle(cand.begin(), cand.end());
        for (int i = 0; i < n; i++) {
            if (a[i] == -1) {
                a[i] = cand.back();
                cand.pop_back();
            }
        }
    }
    else if (t == "stairs") {
        if (argc < 1 + 3) {
            error("Usage: gen random <n> <noise>");
        }

        int noisePart = atoi(argv[3]);
        init = rnd.next(1, n - 1);

        int cur = 0;
        for (int go = 1; cur < n; go++) {
            for (int j = 0; j < go && cur < n; j++, cur++) {
                a[cur] = go;
            }
        }
        int noise = n / noisePart;
        for (int i = 0; i < noise; i++) {
            int pos = rnd.next(0, n - 1);
            int val = rnd.next(1, n - 1);
            a[pos] = val;
        }
    }
    else {
        error("incorrect argument");
    }
    cout << n << " " << init << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i + 1 != n) {
            cout << " ";
        }
    }
    cout << endl;


}
