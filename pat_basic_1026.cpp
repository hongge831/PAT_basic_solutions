#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
	int diff;
	float c1, c2;
	cin >> c1 >> c2;
	diff = (int)((c2 - c1)/100 + 0.5);
	printf("%02d",diff/3600);
	cout << ':';
	printf("%02d", (diff % 3600) / 60);
	cout << ':';
	printf("%02d", diff % 60);

}