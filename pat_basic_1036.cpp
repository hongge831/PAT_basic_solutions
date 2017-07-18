#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
	float n;
	int lineNun;
	char label;
	cin >> n>>label;
	lineNun = (int)(n*0.5+0.5);
	for (int i = 0; i < lineNun; i++)
	{
		if (i == 0 || i == lineNun - 1){
			for (int j = 0; j < n; j++)
			{
				cout << label;
			}cout << endl;
		}
		else{
			cout << label;
			for (int j = 0; j < n-2; j++)
			{
				cout << ' ';
			}
			cout << label<<endl;
		}
	}
	return 0;
}