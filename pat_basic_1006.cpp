#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	int inNum, Bai, Shi, Ge;
	cin >> inNum;
	Bai = (inNum / 100) % 10;
	Shi = (inNum / 10) % 10;
	Ge = inNum % 10;
	for (int i = 0; i < Bai; i++)
	{
		cout << "B";
	}
	for (int i = 0; i < Shi; i++)
	{
		cout << "S";
	}
	for (int i = 0; i < Ge; i++)
	{
		cout << i+1;
	}
	return 0;
}