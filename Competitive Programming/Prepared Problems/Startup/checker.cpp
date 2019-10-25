#include "testlib.h"
#include <stdio.h>
#include <set>

using namespace std;
typedef pair<int, int> pii;

int main(int argc, char * argv[])
{
    registerTestlibCmd(argc, argv);

    set<int> used;
    set<pii> edges;

    int n = inf.readInt();
    int m = inf.readInt();
    for (int i = 0; i < m; ++i) {
        int x = inf.readInt();
        int y = inf.readInt();
        edges.insert(pii(x, y));
        edges.insert(pii(y, x));
    }

    string uans = lowerCase(ouf.readWord());
    if (uans == "yes") {
        int p = ouf.readInt(1, n, "l");
        int k = ouf.readInt(0, n - 1, "k");

        used.insert(p);

        for (int i = 0; i < k; ++i) {
            int x = ouf.readInt(-1, n, "x_" + vtos(i));
            int y = ouf.readInt(-1, n, "y_" + vtos(i));

            if (x == 0 || y == 0) quitf(_wa, "there is no vertex with index 0");
            if (x == y) quitf(_wa, "the same vertex used twice");
            if (x != -1 && used.count(x)) quitf(_wa, "%s", format("vertex %d used in several lines", x).c_str());
            if (y != -1 && used.count(y)) quitf(_wa, "%s", format("vertex %d used in several lines", y).c_str());
            if (x != -1) used.insert(x);
            if (y != -1) used.insert(y);
            if (edges.count(pii(x, y)) == 0 && x != -1 && y != -1) {
                quitf(_wa, "%s", format("there is no edge (%d, %d)", x, y).c_str());
            }
            if (edges.count(pii(x, p)) + edges.count(pii(y, p)) == 0) {
                quitf(_wa, "%s", format("there are no edges (%d, %d) and (%d, %d)", x, p, y, p).c_str());
            }
        }

        if ((int)used.size() != n) {
            quitf(_wa, "%s", format("covered %d vertices of %d", (int)used.size(), n).c_str());
        }
    }

    string jans = lowerCase(ans.readWord());
    ensure(jans == "yes" || jans == "no");

    if (jans != uans) {
        quitf(uans == "yes" ? _fail: _wa, "%s", format("Expected %s, found %s", jans.c_str(), uans.c_str()).c_str());
    }

    quitf(_ok, "%s", ("Correct answer: " + jans).c_str());
}
