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
		getline(cin, temp);//�����������getline����cin�Ļ������������Ե�ͨ��������Ϊcin�����հ׷���������հ׷��Ϳո����һ����
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