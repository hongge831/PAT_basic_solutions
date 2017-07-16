#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main(){
	int weigh[17] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
	char M[11] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2' };
	int n, sum = 0, count = 0;
	string idNum;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> idNum;
		for (int j = 0; j < 17; j++)
		{
			if (idNum[j] > '9' || idNum[j] < '0'){
				sum = 0;
				break;
			}
			sum += (idNum[j] - '0')*weigh[j];
		}
		if (sum == 0 || M[sum % 11] != idNum[17])
		{
			
			cout << idNum << endl;
		}
		else{
			count++;
		}
		sum = 0;

	}
	if (count == n)
		cout << "All passed";

	return 0;
}