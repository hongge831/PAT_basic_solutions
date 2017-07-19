#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
//这道题很妙
int main(){
	string str;
	cin >> str;
	int numt, numat, numpat;
	numt = numat = numpat = 0;
	for (int i = str.size(); i >= 0; i--)
	{
		if (str[i] == 'T')
			numt++;
		else if (str[i] == 'A')
			numat = (numat + numt) % 1000000007;
		else
			numpat = (numpat + numat) % 1000000007;
	}
	cout << numpat;
	return 0;
}
