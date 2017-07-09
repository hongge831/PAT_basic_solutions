#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
typedef struct score_info
{
	string name;
	string scoreNum;
	int score;

} studentInfo;

int main(){
	int num;
	cin >> num;
	studentInfo inputScore, tempMin, tempMax;
	tempMax.score = -1;
	tempMin.score = 101;
	for(int i = 0; i < num; i++)
	{
		cin >> inputScore.name >> inputScore.scoreNum >> inputScore.score;
		if (inputScore.score > tempMax.score){ tempMax = inputScore; }
		if (inputScore.score < tempMin.score){ tempMin = inputScore; }

	}
	cout << tempMax.name << " " << tempMax.scoreNum << endl;
	cout << tempMin.name << " " << tempMin.scoreNum << endl;
	return 0;
}