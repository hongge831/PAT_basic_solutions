#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main(){
	string line1, line2;
	int flag = -1;
	char temp;
	getline(cin, line1);
	getline(cin, line2);
	flag = (int)line1.find('+');
	for (int i = 0; i < line2.length(); i++)
	{
		if (flag < 0){
			temp = line2[i];
			if (line2[i]<='z'&&line2[i]>='a')
				temp = line2[i] - 32;
			if ((int)line1.find(temp) < 0){
				cout << line2[i];
			}
		}
		else{
			temp = line2[i];
			if (line2[i]<='z'&&line2[i]>='a')
				temp = line2[i] - 32;
			if ((int)line1.find(temp) < 0 && (line2[i]>'Z'||line2[i]<'A')){
				cout << line2[i];
			}
		}

	}

	return 0;
}