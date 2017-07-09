#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
	char in = ' ';
	int conf, conp;
	bool flag = true;
	while (in != '\n'){
		cin >> conf >> conp;
		in = getchar();
		if (conf == 0 || conp == 0){
			continue;
		}
		else{
			if (!flag){ cout << " "; }
			else{
				flag = false;
			}
			cout << conf*conp << " " << conp - 1;
		}
	}
	if (flag){
		cout << "0 0";
	}
	return 0;
}
