//���Ե�1����������Ĵ�С�Ƚϣ���һ����С��������
//���Ե�2�ǵ�Y�����������ʱҪ��һ�����ѭ�������򽫰�������
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
bool judge(int x, int y){
	int z = y;
	while (x%y != 0)
	{
		z = x%y;
		x = y;
		y = z;
	}
	if (z == 1)
		return true;
	else
		return false;
}
int main(){
	int a1, a2, b1, b2, n;
	float x, y;
	scanf_s("%d/%d %d/%d %d", &a1, &a2, &b1, &b2, &n);
	if (a1*b2 > b1*a2){
		int t1 = a1, t2=a2;
		a1 = b1; a2 = b2;
		b1 = t1; a2 = t2;
	}
	x = 1.0*n*a1 / a2;
	y = 1.0*n*b1 / b2;
	if (y == int(y))//���y�����������Ҫ��һ������������
		y--;
	bool isfirst = true;
	for (int i = x + 1; i <= y; i++)
	{
		if (judge(n, i) && isfirst == true){
			printf("%d/%d", i, n);
			isfirst = false;
		}
		else if (judge(n, i) && isfirst == false){
			printf(" %d/%d", i, n);
		}
	}

	return 0;
}