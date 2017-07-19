#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct stuInfo{
	string id;
	int num;
};
int main(){
	stuInfo stuArr[1005];
	int n1;
	int num, testnum;
	string id;
	cin >> n1;
	for (int i = 0; i < n1; i++)
	{
		cin >> id >> testnum >> num;
		stuArr[testnum].id=id;
		stuArr[testnum].num = num;
	}
	int n2;
	cin >> n2;
	for (int i = 0; i < n2; i++)
	{
		cin >> testnum;
		cout << stuArr[testnum].id <<' '<< stuArr[testnum].num<<endl;
	}
	return 0;
}
