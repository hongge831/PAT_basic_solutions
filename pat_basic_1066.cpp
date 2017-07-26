#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
	int n, m, low, high, value;
	int temp;
	cin >> n >> m >> low >> high >> value;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf_s("%d", &temp);
			if (temp >= low&&temp <= high){
				printf("%03d",value);
			}
			else{
				printf("%03d", temp);
			}
			if (j == m - 1){
				printf("\n");
			}
			else{
				printf(" ");
			}
		}
	}
	return 0;
}