#include <stdio.h>
#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	int n, sum = 0;
	cin >> n;
	string temp;
	set<int> v;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		for (int j = 0; j < temp.size(); j++)
		{
			sum += temp[j] - '0';
		}
		v.insert(sum);
		sum = 0;
	}
	cout << v.size() << endl;
	set<int>::iterator it = v.begin();
	cout << *(it++);
	for (int i = 1; i < v.size(); i++)
	{
		cout << ' ' << *(it++);
	}
	return 0;
}