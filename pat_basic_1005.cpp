#include <stdio.h>
#include <iostream>
#include <set>
using namespace std;
//set默认是排好序的,find 返回的是指针地址
int main(){
	int k, temp;
	cin >> k;
	set<int> hash;
	set<int>::iterator it;
	for (int i = 0; i < k; i++)
	{
		cin >> temp;
		hash.insert(temp);
	}
	for (it = hash.begin(); it != hash.end(); it++)
	{
		temp = *it;
		while (temp != 1){
			//如果是奇数
			if (temp & 0x01){
				temp = (temp * 3 + 1) / 2;
			}
			else{
				temp = temp / 2;
			}
			if (hash.find(temp) != hash.end()){
				hash.erase(temp);
			}
		}
	}
	for (it--; it != hash.begin(); it--){
		cout << *it << " ";
	}
	cout << *it;
	return 0;
}