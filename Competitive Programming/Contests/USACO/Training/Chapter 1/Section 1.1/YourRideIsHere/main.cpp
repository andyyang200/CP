/*
ID: andyyan1
TASK: ride
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string group;
    string comet;
    fin >> group >> comet;
    int groupNumber = 1;
    int cometNumber = 1;
    for (int x = 0; x < group.length(); x++)
    {
        groupNumber *= (group[x] - 'A' + 1);
    }
    for (int x = 0; x < comet.length(); x++)
    {
        cometNumber *= (comet[x] - 'A' + 1);
    }
    if (groupNumber % 47 == cometNumber % 47)
    {
        fout << "GO" << endl;
    }
    else
    {
        fout << "STAY" << endl;
    }
    return 0;
}
