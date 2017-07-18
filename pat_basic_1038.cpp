#include <stdio.h>
#include<iostream>
#include<iostream>
#define M 103
using namespace std;
int main(){
	int n,temp,num;
	int score[M] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		score[temp]+=1;
	}
	cin >> num;
	for (int i = 0; i < num-1; i++)
	{
		cin >> temp;
		cout << score[temp]<<' ';
	}
	cin >> temp;
	cout << score[temp];
	return 0;
}