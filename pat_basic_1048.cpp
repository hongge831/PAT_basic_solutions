#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
	string a, b;
	char temp, ta, tb;
	char zifu[15] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K' };
	stack<char> stk;
	cin >> a >> b;
	int la = a.length()-1, lb = b.length()-1;
	int length = la > lb ? la+1 : lb+1;
	int k = 1;
	for (int i = length - 1; i >= 0; la--, lb--, i--, k++)
	{
		if (la >= 0 && lb >= 0){
			ta = a[la];
			tb = b[lb];
		}
		else if (la < 0 && lb >= 0){
			ta = '0';
			tb = b[lb];
		}
		else if (la >=0 && lb < 0){
			ta = a[la];
			tb = '0';
		}

		if (k % 2 == 0){
			temp = (tb - ta) >= 0 ? (tb - ta) : (tb - ta) + 10;
			temp = temp + '0';
		}
		else{
			temp = (ta - '0' + tb - '0') % 13;
			temp = zifu[temp];
		}
		stk.push((char)(temp));
	}
	for (int i = 0; i < length; i++)
	{
		cout << stk.top();
		stk.pop();
	}

	return 0;
}