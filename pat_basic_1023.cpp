#include<stdio.h>
#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int num[10] = { 0 };
	int temp, flag = 0;
	vector<int> result;
	/*���������ʼ���������ֵĸ�������*/
	for (int i = 0; i < 10; i++)
	{
		cin >> num[i];
		for (int j = 0; j < num[i]; j++)
		{
			result.push_back(i);
		}
	}
	/*���������ֱ�Ӱ������˳��������ּ�Ϊ��С����*/
	if (num[0] == 0){
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i];
		}
	}
	/*������㣬�ͽ����������С���͵�һ����λ�ý�����˳�����*/
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