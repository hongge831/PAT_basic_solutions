#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main(){
	int n, count = 0;
	double temp, sum = 0;
	bool flag = true;
	cin >> n;
	string str;
	int point = 0;
	for (int i = 0; i < n; i++)
	{
		flag = true;
		cin >> str;
		if ((str[0] != '-' && (str[0] >'9' || str[0] < '0'))){
			printf("ERROR: %s is not a legal number\n", str.c_str()); continue;
		}
		point = str.find('.');//寻找小数点的位置
		if (point == -1){
			for (int k = 1; k < str.size(); k++)
			{
				if (str[k] > '9' || str[k] < '0'){
					flag = false;
					break;
				}
			}
			if (flag){
				sscanf_s(str.c_str(), "%lf", &temp);
				if (temp > 1000 || temp < -1000){
					printf("ERROR: %s is not a legal number\n", str.c_str()); continue;
				}
				else{
					sum += temp;
					count++;
				}
			}
			else{
				printf("ERROR: %s is not a legal number\n", str.c_str()); continue;
			}
		}//如果有小数，则point为小数的位置
		else{
			if (str[0] == '-'&&str[1] == '.'){
				printf("ERROR: %s is not a legal number\n", str.c_str()); continue;
			}
			for (int k = 1; k < str.size(); k++)//遍历其实可以从第二个数开始
			{
				if ((str[k] >= '0'&&str[k] <= '9') || (str[k] == '.' && k == point && str.size()-point<=3)){
					continue;
				}
				else{
					flag = false;
					break;
				}
			}

			if (flag){
				sscanf_s(str.c_str(), "%lf", &temp);
				if (temp > 1000 || temp < -1000){
					printf("ERROR: %s is not a legal number\n", str.c_str()); continue;
				}
				else{
					sum += temp;
					count++;
				}
			}
			else{
				printf("ERROR: %s is not a legal number\n", str.c_str()); continue;
			}

		}
	}
	if (count == 0){
		printf("The average of 0 numbers is Undefined\n");
	}
	else if (count == 1){
		printf("The average of 1 number is %.2lf", sum);
	}
	else{
		printf("The average of %d numbers is %.2lf", count, sum / count);
	}
	return 0;
}