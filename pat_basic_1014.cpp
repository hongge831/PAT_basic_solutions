/*z这道题真的AC了好久，题目理解很有问题，另外两对字符串最后一次比较后不能继续比较，一定要记得跳出循环*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main(){
	string result[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
	char re[2];
	int length, loc;
	bool isFirst = true;
	string str1, str2, str3, str4;
	cin >> str1 >> str2 >> str3 >> str4;
	length = str1.length() < str2.length() ? str1.length() : str2.length();
	for (int i = 0; i < length; i++)
	{
		if (isFirst){
			if (str1[i] == str2[i] && str1[i] <= 'G'&&str1[i] >= 'A'){
				cout << result[(str1[i] - 'A')]<<' ';
				isFirst = false;
			}
		}
		else{
			if (str1[i] == str2[i] && ((str1[i] <= 'N'&&str1[i] >= 'A') || (str1[i] <= '9'&&str1[i] >= '0'))){
				if (str1[i] <= '9'&&str1[i] >= '0'){
					cout << setw(2) << setfill('0')<<str1[i];
					cout << ':'; break;
				}
				else{
					loc = str1[i] - 'A' + 10;
					cout << setw(2) << setfill('0') << loc << ':'; break;
				}
			}
		}
		
	}
	length = str3.length() < str4.length() ? str3.length() : str4.length();
	for (int i = 0; i <= length; i++)
	{
		if (str3[i] == str4[i]){
			if ((str3[i] <= 'Z'&&str3[i] >= 'A') || (str3[i] <= 'z'&&str3[i] >= 'a')){
				cout << setw(2) << setfill('0') << i; break;
			}

		}
	}

	return 0;
}