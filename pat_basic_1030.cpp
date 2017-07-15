#include<stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(const int a, const int b){
	return a < b;
}
int main(){
	float n, p;//数据类型要为float否则会不够
	cin >> n >> p;
	vector<int> vct;
	int temp, loc,res;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		vct.push_back(temp);
	}
	sort(vct.begin(), vct.end(), compare);
	for (int i = 0; i < n; i++)
	{
		if (vct[i] * p >= vct[n - 1]){
			loc = i;
			break;
		}
	}res = n - loc;
	int j = n-1;//记录右边位置
	int i = loc;//记录左边位置
	while (i != 0){
		if (vct[i] * p >= vct[j]){
			i--;
		}
		else{
			res = (j - i) > res ? (j - i) : res;
			j--;
		}
	}
	cout << res;
	return 0;
}