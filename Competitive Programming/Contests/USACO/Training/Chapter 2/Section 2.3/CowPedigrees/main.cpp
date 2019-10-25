/*
ID: andyyan1
PROG: nocows
LANG: C++
*/

#include <iostream>
#include <fstream>
using namespace std;

long ways[105][205];

int main()
{
    ifstream fin ("nocows.in");
    ofstream fout ("nocows.out");

    int N, K;
    fin >> N >> K;

    ways[1][1] = 1;
    for (int height = 2; height <= K; height++)
    {
        for (int nodes = 1; nodes <= N; nodes += 2)
        {
            for (int rightNodes = 1; rightNodes < nodes; rightNodes += 2)
            {
                int rightHeight = height - 1;
                long rightWays = ways[rightHeight][rightNodes];
                if (rightWays == 0)
                {
                    continue;
                }
                for (int leftHeight = 1; leftHeight <= rightHeight; leftHeight++)
                {
                    int leftNodes = nodes - 1 - rightNodes;
                    long leftWays = ways[leftHeight][leftNodes];
                    if (leftWays == 0)
                    {
                        continue;
                    }
                    if (leftHeight == rightHeight)
                    {
                        ways[height][nodes] += leftWays * rightWays;
                    }
                    else
                    {
                        ways[height][nodes] += 2 * leftWays * rightWays;
                    }
                    ways[height][nodes] %= 9901;
                }
            }
        }
    }
    fout << ways[K][N] << endl;
    fout.close();
}
