#include <stdio.h>
#include <iostream>
#include <string>
#define M 10005
using namespace std;
struct info{
	int rank = 0;
	bool isget = true;
};

bool isPre(int n){
	if (n == 1)
		return false;
	else if (n == 2){
		return true;
	}
	else{
		for (int i = 2; i*i <= n; i++)//素数判断小于等于根号不是小于
		{
			if (n%i == 0)
				return false;
		}		
	}
	return true;
}
int main(){
	int n,temp;
	info stu[M];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		stu[temp].rank = i + 1;
		stu[temp].isget = false;
	}
	int n2;
	cin >> n2;
	for (int j = 0; j < n2; j++)
	{
		cin >> temp;
		if (stu[temp].isget == true){
			if (stu[temp].rank == 0){
				printf("%04d: Are you kidding?\n",temp);
			}
			else{
				printf("%04d: Checked\n",temp);
			}
			continue;
		}
		if (isPre(stu[temp].rank) == false){
			if (stu[temp].rank == 1){
				printf("%04d: Mystery Award\n",temp);
			}
			else{
				printf("%04d: Chocolate\n",temp);
			}
		}
		else{
			printf("%04d: Minion\n", temp);
		}
		stu[temp].isget = true;
	}

	return 0;
}