#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int N, temp, flag;
	int count[5] = { 0 };
	float a[5] = {0};
	bool isfirst = true;
	flag = 1;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		switch (temp%5)
		{
		case 0:
			if (temp % 2 == 0){
				count[0] += 1;
				a[0] = a[0] + temp;
			}break;
		case 1:
			count[1] += 1;
			a[1] = a[1] + flag*temp;
			flag = flag*(-1);
			break;
		case 2:count[2] += 1; a[2] += 1; break;
		case 3:count[3] += 1; a[3] += temp; break;
		case 4:
			count[4] += 1;
			if (temp > a[4]){ a[4] = temp; }
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (!isfirst){
			cout << " ";
		}
		else{
			isfirst = false;
		}
		if (count[i] == 0){
			cout << 'N';
		}
		else if(i!=3){
			cout << setprecision(0) << fixed << a[i];
		}
		else{
			cout << setprecision(1) << fixed << a[i]/count[i];
		}
	}
	return 0;

}