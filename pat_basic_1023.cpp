#include<stdio.h>
#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int num[10] = { 0 };
	int temp, flag = 0;
	vector<int> result;
	/*根据输入初始化各个数字的个数数组*/
	for (int i = 0; i < 10; i++)
	{
		cin >> num[i];
		for (int j = 0; j < num[i]; j++)
		{
			result.push_back(i);
		}
	}
	/*如果不含零直接按升序的顺序输出数字即为最小的数*/
	if (num[0] == 0){
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i];
		}
	}
	/*如果含零，就将大于零的最小数和第一个零位置交换后顺序输出*/
	else{
		for (int i = 1; i < 10; i++)
		{
			if (num[i] != 0){
				flag = i;
				break;
			}	
		}
		temp = result[num[0]];
		result[num[0]] = result[0];
		result[0] = temp;
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i];
		}
		
	}

	return 0;
}