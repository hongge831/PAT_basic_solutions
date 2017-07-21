#include <stdio.h>
#include <iostream>
#include <string>
#define M 100005
using namespace std;

int main(){
	int n, temp, max = 0, maxi = 0;
	cin >> n;
	int nums[M] = { 0 };
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		if (temp > max){
			max = temp;
			nums[maxi] = max;
			maxi++;
		}
		else{
			for (int j = maxi - 1; j >= 0; j--)
			{
				if (nums[j] > temp){
					nums[j] = 0;
					maxi--;
				}
				else{
					break;
				}
			}
		}
	}
	cout << maxi << endl;
	if (maxi != 0){
		for (int i = 0; i < maxi - 1; i++)
		{
			cout << nums[i] << ' ';
		}cout << nums[maxi - 1];
	}
	else{
		cout << endl;
	}

	return 0;
}