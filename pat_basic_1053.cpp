#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	int n, d;
	double e,temp;
	cin >> n >> e >> d;
	int maybe = 0, must = 0, total;
	for (int i = 0; i < n; i++)
	{
		cin >> total;
		int day = 0;
		for (int j = 0; j < total; j++)
		{
			cin >> temp;
			if (temp < e){
				day++;
			}
		}
		if (2*day > total){
			if (total > d)//特别注意这里，是total大于d不是day大于d
				must++;
			else{
				maybe++;
			}
		}

	}
	printf("%.1lf%% %.1lf%%\n", (double)(maybe) / n * 100, (double)(must) / n * 100);

	return 0;
}