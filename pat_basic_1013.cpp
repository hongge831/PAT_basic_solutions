#include <stdio.h>
#include <iostream>
using namespace std;
#define M 110001
int Array[M];
int Prime[10100];
int main(){
	int m, n;
	cin >> m >> n;
	/*�������ʼ*/
	//��������кܶ෽���������õ��ǰ�ʽɸ�����ܹ���ЧAC1013��������Ҫ���Բ鿴����ɸ��
	Array[0] = Array[1] = 1;//����������0������������1�����������������±��������ֵ
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
	/*����������*/
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
