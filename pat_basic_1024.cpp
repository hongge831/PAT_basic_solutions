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
	subin = in.substr(1,loc1-1);//�ٳ����ֲ���
	zhishu = in.substr(loc1+2);
	zhishuInt = atoi(zhishu.c_str());//��ָ��ת������������
	if (in[0] == '-'){
		cout << '-';
	}
	/*��Ӧ+1.23400E-03��+1.23400E+03���������*/
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