#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main(){
	string str;
	int count[30] = { 0 };
	int max = 0,flag=0;
	getline(cin, str);
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] <= 'Z'&&str[i] >= 'A')
			count[str[i] - 'A']+=1;
		else if (str[i] <= 'z'&&str[i] >= 'a')
			count[str[i] - 'a']+=1;
	}
	for (int i = 0; i < 30; i++)
	{
		if (count[i] > max){
			max = count[i];
			flag = i;
		}
	}
	cout << (char)(flag + 'a') << ' ' << max;
	return 0;
}