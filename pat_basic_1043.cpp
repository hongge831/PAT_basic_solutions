#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main(){
	string str;
	int count[7] = { 0 };
	char patern[6] = {'P','A','T','e','s','t'};
	int sum = 0;
	getline(cin, str);
	for (int i = 0; i < str.size(); i++)
	{
		switch (str[i])
		{
		case'P':count[0]++; sum++; break;
		case'A':count[1]++; sum++; break;
		case'T':count[2]++; sum++; break;
		case'e':count[3]++; sum++; break;
		case's':count[4]++; sum++; break;
		case't':count[5]++; sum++; break;
		}
	}
	int max = count[0];
	for (int k = 0; k < 6; k++)
	{
		if (count[k] > max)
			max = count[k];
	}
	for (int j = 0; j < max*6; j++)
	{
		if (count[j % 6] > 0){
			cout << patern[j % 6];
			count[j % 6]--;
		}
	}

	return 0;
}