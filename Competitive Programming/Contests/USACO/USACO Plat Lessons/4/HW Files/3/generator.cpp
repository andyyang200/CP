#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    /* Read number from command line. */
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int maxc = atoi(argv[3]);
    string k = argv[4];

    string s = "";
    string t = "";
    for(int i = 0; i < n; i++) {
        s += (char)(rnd.next(0, maxc - 1) + 'a');
    }
    for(int i = 0; i < m; i++) {
        t += (char)(rnd.next(0, maxc - 1) + 'a');
    }
    cout << k << endl;
    cout << s << endl;
    cout << t << endl;
}
