#include <stdio.h>
#include <iostream>
#include <list>
#include <math.h>
using namespace std;
bool isPrime(int inNum){
	if (inNum == 2){ return true; }
	else{
		for (int i = 2; i <= sqrt(inNum); i++)
		{
			if (inNum%i == 0){ return false; break; }
		}
		return true;
	}
}

int main(){
	int num, temp, Result = 0;
	int it1 = 0;
	int cnt[100010] = { 0 };
	cin >> num;
	for (int i = 2; i <= num; i++)
	{
		if (isPrime(i)){
			cnt[it1] = i;
			if (it1 > 0){
				if (cnt[it1] - cnt[it1 - 1] == 2){
					Result++;
				}
			}it1++;
		}
	}
	cout << Result;
	return 0;
}