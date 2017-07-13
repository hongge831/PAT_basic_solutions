#include<stdio.h>
#include<iostream>
#include <algorithm>
#include <string>
using namespace std;
bool comp(const char &a, const char &b){
	return a < b;
}
int main(){
	int count = 0;
	string n;
	cin >> n;
	sort(n.begin(), n.end(), comp);
	for (int i = 0; i < n.size(); i++)
	{
		count += 1;
		if (n[i] != n[i+1]){
			cout << n[i] << ':' << count << endl;
			count = 0;
		}
	}

	return 0;
}