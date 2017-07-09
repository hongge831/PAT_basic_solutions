#include <stdio.h>
#include <iostream>

using namespace std;
int main(){
	int k;
	double A, B, C;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> A >> B >> C;
		if (A + B > C){
			cout << "Case #" << i + 1 << ": " << "true" << endl;
		}
		else{
			cout << "Case #" << i + 1 << ": " << "false" << endl;
		}

	}
}