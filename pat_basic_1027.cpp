#include <stdio.h>
#include <iostream>
using namespace std;
/*网络上有20多一点行的结果，可以参考*/
int main(){
	int n, flag, left, beginLabel;
	int table[23];
	char label;
	cin >> n >> label;
	for (int i = 0; i < 23; i++)
	{
		table[i] = 2 * i*i + 4 * i + 1;
		if (n >= table[i])
			flag = i;
	}
	left = n - table[flag];
	beginLabel = 2 * flag + 1;
	/*print the pattern of result*/
	int temp = 1;
	for (int i = beginLabel ; i >= 1; i-=2)
	{
		for (int j = 1; j < temp; j++)
		{
			cout << ' ';
		}
		for (int k = 0; k < i; k++)
		{
			cout << label;
		}
		cout << endl;
		temp += 1;
	}
	for (int i = 3; i <=beginLabel; i += 2)
	{
		for (int j = 0; j < temp-3; j++)
		{
			cout << ' ';
		}
		for (int k = 0; k < i; k++)
		{
			cout << label;
		}
		cout << endl;
		temp -= 1;
	}
	cout << left<<endl;
	

	return 0;


}