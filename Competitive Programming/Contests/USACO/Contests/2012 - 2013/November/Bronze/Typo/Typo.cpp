#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string s;
int main()
{
	ifstream fin("typo.in");
	ofstream fout("typo.out");

	getline(fin, s);
	int depth = 0;
	int closingSeen = 0; 
	int openingSeen = 0;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
		{
			depth++;
			openingSeen++;
		}
		else
		{
			depth--;
			closingSeen++;
		}

		if (depth <= 1)
			openingSeen = 0;
		if (depth == -1)
		{
			fout << closingSeen << endl;
			return 0;
		}
	}
	fout << openingSeen << endl;
}