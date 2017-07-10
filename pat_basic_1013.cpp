#include <stdio.h>
#include <iostream>
using namespace std;
#define M 110001
int Array[M];
int Prime[10100];
int main(){
	int m, n;
	cin >> m >> n;
	/*素数打表开始*/
	//素数打表有很多方法，本例用的是埃式筛法，能够有效AC1013，如有需要可以查看更多筛法
	Array[0] = Array[1] = 1;//假设数组中0代表是素数，1代表不是素数，数组下标代表素数值
	for (int i = 2; i*i < M; i++)
	{
		if (Array[i] == 1){
			continue;
		}
		for (int j = i*i; j < M; j = j + i)
		{
			Array[j] = 1;
		}
	}
	int k = 1;
	for (int i = 2; i < M; i++)
	{
		if (Array[i] == 0){
			Prime[k++] = i;
		}
	}
	/*素数打表结束*/
	for (int i = m, k = 1; i <= n; i++, k++)
	{
		if (k % 10 == 0){
			cout << Prime[i]<< endl;
		}
		else if (i == n){
			cout << Prime[i];
		}
		else{
			cout << Prime[i] << " ";
		}
	}
	return 0;
}
