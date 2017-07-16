#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
#define M 100005
int main(){
	int n, max = 0, maxsum=0, sumlabel = 0;
	int label, score;
	int res[M] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> label >> score;
		res[label] += score;
		if (label > max)
			max = label;
	}
	for (int i = 1; i <= max; i++)
	{
		if (res[i] > maxsum)
		{
			maxsum = res[i];
			sumlabel = i;
		}
	}
	cout << sumlabel << ' ' << maxsum;
	return 0;
}