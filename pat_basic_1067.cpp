#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main(){
	int n, tryNum = 0;
	string rtpw, temp;
	cin >> rtpw >> n;
	getchar();
	while (true){
		getline(cin, temp);//这里如果不用getline而用cin的话会有两个测试点通不过，因为cin遇到空白符会结束（空白符和空格符不一样）
		tryNum++;
		if(temp==rtpw){
			cout << "Welcome in" << endl; break;
		}
		if (temp != rtpw&&temp!="#"){
			cout << "Wrong password: "<<temp << endl;
		}
		if (temp == "#"){
			break;
		}
		if (tryNum == n){
			cout << "Account locked" << endl; break;
		}
	}
	return 0;
}