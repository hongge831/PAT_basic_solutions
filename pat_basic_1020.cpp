/*@copyright：hongge831*/
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
//定义自定义排序规则
bool compare(const mk &a, const mk &b){
	return a.unitprice > b.unitprice;
}

int main(){
	int n, d,dtemp=0;
	float result=0.0;
	cin >> n >> d;
	mk *arr = (mk*)malloc(n*sizeof(mk));//动态开辟结构体数组
	arrinit(arr, n);//初始化数组，包括计算单价
	sort(arr, arr + n, compare);//根据单价降序排序
	int sum = 0, i = 0;
	//获得临界种类的位置
	for (i = 0; i < n; i++)
	{
		sum = arr[i].storage + sum;
		if (sum > d)
			break;
	}
	//临界位置之前的全部月饼总价的和
	for (int j = 0; j < i; j++)
	{
		result = arr[j].totalPrice + result;
		dtemp = arr[j].storage+dtemp;
	}
	//加上临界种类月饼一部分的价格
	printf("%.2f", result+arr[i].unitprice*(d-dtemp));
	return 0;
}
