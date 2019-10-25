#include "testlib.h"
#include <set>

using namespace std;

typedef pair<int, int> pii;

int main(int argc, char* argv[])
{
    registerValidation(argc, argv);

    int n = inf.readInt(2, 1000, "n");
    inf.readSpace();
    int m = inf.readInt(0, 10000, "m");
    inf.readEoln();
    
    set<pii> used;
    
    for (int i = 0; i < m; ++i) {
        int x = inf.readInt(1, n, "x");
        inf.readSpace();
        int y = inf.readInt(1, n, "y");
        inf.readEoln();
        ensure(x != y);
        used.insert(pii(x, y));
        used.insert(pii(y, x));
    }
    inf.readEof();

    ensure(used.size() == 2 * m);
    
    return 0;
}
