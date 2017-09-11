#include <stdio.h>
#include<iostream>
#include <string>
using namespace std;
int main(){
	int da, temp = 1, sum = 0;
	string a;
	for (int i = 0; i < 2; i++)
	{
		cin >> a >> da;
		for (int j = 0; j < a.length(); j++)
		{
			if (a[j] == da + '0'){
				sum = sum+da * temp;
				temp *= 10;
			}
		}
		temp = 1;

	}
	cout << sum;
	return 0;
}
