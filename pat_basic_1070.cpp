#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const int a,const int b){
	return a < b;
}
int main(){
	int n,sum=0,temp;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v[i] = temp;
	}sort(v.begin(), v.end(), cmp);
	sum = v[0];
	for (int i = 1; i < n; i++)
	{
		sum += v[i];
		sum /= 2;
	}cout << sum;

	return 0;
}