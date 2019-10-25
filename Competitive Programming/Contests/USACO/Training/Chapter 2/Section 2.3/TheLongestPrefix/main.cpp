/*
ID: andyyan1
PROG: prefix
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ifstream fin ("prefix.in");
    ofstream fout ("prefix.out");

    vector<string> primitives;
    string primitive;
    fin >> primitive;
    while(primitive != ".")
    {
        primitives.push_back(primitive);
        fin >> primitive;
    }
    string sequence;
    string line;
    while(getline(fin, line))
    {
        sequence += line;
    }
    fin.close();

    bool possible [sequence.length()];
    for (int x = 0; x < sequence.length(); x++)
    {
        possible[x] = false;
    }

int kk=sequence.length();
    for (int i = -1; i < (int)sequence.length(); i++)
    {
        if (i == -1 || possible[i])
        {
            for (int x = 0; x < primitives.size(); x++)
            {
                primitive = primitives[x];
                if (sequence.substr(i + 1, primitive.length()) == primitive)
                {
                    possible[i + primitive.length()] = true;
                }
            }
        }

    }
    int i;
    for (i = sequence.length() - 1; i >= 0; i--)
    {
        if (possible[i])
        {
            fout << i + 1 << endl;
            break;
        }
    }
    if (i == -1)
    {
        fout << 0 << endl;
    }
    fout.close();
    return 0;
}
