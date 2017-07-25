#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main(){
	string str;
	getline(cin, str);
	int sum = 0, one = 0, zero = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] <= 'z'&&str[i] >= 'a'){
			sum += str[i] - 'a' + 1;
		}
		else if (str[i] <= 'Z'&&str[i] >= 'A'){
			sum += str[i] - 'A' + 1;
		}
	}
	while (sum){
		if (sum % 2 == 0){
			zero += 1;
		}
		else{
			one += 1;
		}
		sum /= 2;
	}
	cout << zero << ' ' << one;

	return 0;
}