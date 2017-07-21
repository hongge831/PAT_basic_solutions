#include <stdio.h>
#include <iostream>
#define M 1005
using namespace std;
int main(){
	int n, teamN, mateN, score;
	int max = 0;
	int team[M] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d-%d %d", &teamN, &mateN, &score);
		team[teamN] += score;
	}
	int j = 0;
	for (int i = 0; i < M; i++)
	{
		if (team[i] > max){
			max = team[i];
			j = i;
		}
	}
	cout << j << ' ' << max << endl;
	return 0;
}