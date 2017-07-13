#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
int main(){
	string in,subin,zhishu;
	int loc1, zhishuInt;
	cin >> in;
	loc1 = in.find('E');
	subin = in.substr(1,loc1-1);//抠出数字部分
	zhishu = in.substr(loc1+2);
	zhishuInt = atoi(zhishu.c_str());//将指数转化成整型数字
	if (in[0] == '-'){
		cout << '-';
	}
	/*对应+1.23400E-03和+1.23400E+03这两种情况*/
	if (in[loc1 + 1] == '+'){
		if (zhishuInt >= (subin.size() - 2)){
			for (int i = 0; i < subin.size(); i++)
			{
				if (subin[i] == '.')
					continue;
				printf("%c", subin[i]);
			}
			for (int i = 0; i < zhishuInt-subin.size() + 2; i++)
			{
				printf("%c",'0');
			}
		}
		else{
			for (int i = 0; i < subin.size(); i++)
			{
				if (subin[i] == '.')
					continue;
				if (i == zhishuInt + 2){
					printf("%c", '.');
				}
				printf("%c", subin[i]);
			}
		}	
	}



	else if (in[loc1 + 1] == '-'){
		cout << "0.";
		for (int i = 0; i < zhishuInt - 1; i++)
		{
			printf("%c", '0');
		}
		for (int i = 0; i < subin.size(); i++)
		{
			if (subin[i] == '.')
				continue;
			printf("%c", subin[i]);
		}

	}

	return 0;
}