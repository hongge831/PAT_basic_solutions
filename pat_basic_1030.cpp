#include<stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(const int a, const int b){
	return a < b;
}
int main(){
	float n, p;//��������ҪΪfloat����᲻��
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
	int j = n-1;//��¼�ұ�λ��
	int i = loc;//��¼���λ��
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