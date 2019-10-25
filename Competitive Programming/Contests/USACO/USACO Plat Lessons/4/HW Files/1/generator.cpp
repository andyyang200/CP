#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    /* Read number from command line. */
    int n = atoi(argv[1]);
    int maxc = atoi(argv[2]);

    string s = "";
    for(int i = 0; i < n; i++) {
        s += (char)(rnd.next(0, maxc - 1) + 'a');
    }
    cout << s << endl;
}
