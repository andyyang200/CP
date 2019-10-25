#include <iostream>

using namespace std;
    int board[2014][2014];
    long long sums1[4000] = {0};
    long long sums2[4000] = {0};

int main()
{
    int n = 0;
    cin >> n;

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            int k;
            cin >> k;
            board[r][c] = k;
            sums1[r + c] += k;
            sums2[r + n - 1 - c] += k;
        }
    }
    long long max1 = 0;
    long long max2 = 0;
    int maxR1 = 1;
    int maxC1 = 1;
    int maxR2 = 2;
    int maxC2 = 1;
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            long long sum = sums1[r + c] + sums2[r + n - 1 - c] - board[r][c];
            if ((r + c) & 1)
            {
                 if (sum > max2)
                {
                    max2 = sum;
                    maxR2 = r + 1;
                    maxC2 = c + 1;
                }
            }
            else
            {
               if (sum > max1)
                {
                    max1 = sum;
                    maxR1 = r + 1;
                    maxC1 = c + 1;
                }
            }
        }
    }
    cout << max1 + max2 << endl;
    cout << maxR1 << " " << maxC1 << " " << maxR2 << " " << maxC2 << endl;
    return 0;
}
