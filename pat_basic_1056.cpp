#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
	int n, temp, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		sum += temp * 10 * (n - 1) + temp*(n - 1);
		
	}cout << sum;
	return 0;
}