#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main(){
	int n;
	double temp,sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		sum += temp*(n - i)*(i + 1);
	}
	printf("%.2lf",sum);
	return 0;
}