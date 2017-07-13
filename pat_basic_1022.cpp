#include<stdio.h>
#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int a, b, d,sum;
	vector<int> vct;
	cin >> a >> b >> d;
	sum = a + b;
	while (sum / d){
		vct.push_back(sum%d);
		sum = sum / d;
	}vct.push_back(sum%d);
	for (int i = vct.size()-1; i >=0; i--)
	{
		cout << vct[i];
	}
	return 0;
}