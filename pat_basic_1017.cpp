#include <stdio.h>
#include<iostream>
#include <string>
using namespace std;
int main(){
	string a;
	int b, m;
	cin >> a >> b;
	if (a.length() == 1)
		cout << (a[0] - '0') / b << ' ' << (a[0] - '0') % b;
	else{
		m = 0;
		for (int i = 0; i < a.length(); i++)
		{
			m = m * 10 + a[i] - '0';
			if (m >= b){
				cout << m / b;
			}
			else{
				if (i != 0)
					cout << 0;
			}
			m = m%b;
		}cout <<' '<< m;
	}
	return 0;
}
