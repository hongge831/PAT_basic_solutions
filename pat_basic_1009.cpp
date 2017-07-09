#include <stdio.h>
#include <iostream>
#include <list>
#include <stack>
#include <string>
using namespace std;
int main(){
	string strIn;
	stack<string> stk;
	getline(cin, strIn);
	int count, mark, cnt;
	cnt = count = mark = 0;
	for (int i = 0; i < strIn.length(); i++)
	{
		if (strIn[i] == ' '){
			count = i - mark;
			stk.push(strIn.substr(mark, count));
			mark = i + 1;
			cnt += 1;
		}
	}
	stk.push(strIn.substr(mark));//最后一个字符串不能用空格判断，直接输出
	while (cnt != 0){
		cout << stk.top() << " ";
		stk.pop();
		cnt--;
	}
	cout << stk.top();
}