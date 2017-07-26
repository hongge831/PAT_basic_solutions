#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	float max = 0, temp;
	int a, b;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d %d", &a, &b);
		temp = sqrt(1.0*a*a + 1.0*b*b);
		if (temp > max){
			max = temp;
		}
	}
	printf("%.2f",max);

	return 0;
}