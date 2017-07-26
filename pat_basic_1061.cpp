#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> v1(m), v2(m);
	for (int i = 0; i < m; i++)
	{
		cin>>v1[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> v2[i];
	}
	int temp,sum=0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> temp;
			if (temp == v2[j]){
				sum += v1[j];
			}
		}
		cout << sum << endl;
		sum = 0;
	}
	return 0;
}