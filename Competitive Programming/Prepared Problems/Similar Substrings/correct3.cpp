#include <iostream>
using namespace std;

int n, m, k;
string a, b;

int ans = 0;

void Solve(int offa, int offb) {
    int left = 0;
    int num_bad = 0;
    for (int i = 0; i + offa < n and i + offb < m; i += 1) {
        if (a[offa + i] != b[offb + i]) {
            num_bad += 1;
        }

        if (num_bad == k + 1) {
            num_bad -= 1;
            while (a[offa + left] == b[offb + left]) {
                left += 1;
            }
            left += 1;
        }

        ans = max(ans, i - left + 1);
    }
}

int main() {
    cin >> k;
    cin >> a >> b;
    n = a.length();
    m = b.length();
    ans = 0;
    for (int i = 0; i < n; i += 1) {
        Solve(i, 0);
    }
    for (int j = 0; j < m; j += 1) {
        Solve(0, j);
    }

    cout << ans << '\n';

}
