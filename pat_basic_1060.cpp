#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const int a, const int b){
	return a > b;
}
int main(){
	int n,temp,max=0;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), cmp);
	int p = 1;
	for (int i = 0; i < n; i++)
	{
		if (v[i] > p){
			p++;
		}
	}cout << p - 1;;
	return 0;
}