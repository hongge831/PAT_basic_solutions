/*@copyright��hongge831*/
#include <stdio.h>
#include<iostream>
#include <algorithm>
using namespace std;
typedef struct mooncake{
	float storage;
	float totalPrice;
	float unitprice;

} mk;
void arrinit(mk *arr, int n){
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].storage;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].totalPrice;
	}
	for (int i = 0; i < n; i++)
	{
		arr[i].unitprice = arr[i].totalPrice / arr[i].storage;
	}

}
//�����Զ����������
bool compare(const mk &a, const mk &b){
	return a.unitprice > b.unitprice;
}

int main(){
	int n, d,dtemp=0;
	float result=0.0;
	cin >> n >> d;
	mk *arr = (mk*)malloc(n*sizeof(mk));//��̬���ٽṹ������
	arrinit(arr, n);//��ʼ�����飬�������㵥��
	sort(arr, arr + n, compare);//���ݵ��۽�������
	int sum = 0, i = 0;
	//����ٽ������λ��
	for (i = 0; i < n; i++)
	{
		sum = arr[i].storage + sum;
		if (sum > d)
			break;
	}
	//�ٽ�λ��֮ǰ��ȫ���±��ܼ۵ĺ�
	for (int j = 0; j < i; j++)
	{
		result = arr[j].totalPrice + result;
		dtemp = arr[j].storage+dtemp;
	}
	//�����ٽ������±�һ���ֵļ۸�
	printf("%.2f", result+arr[i].unitprice*(d-dtemp));
	return 0;
}
