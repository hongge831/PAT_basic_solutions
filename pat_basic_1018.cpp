#include <stdio.h>
#include<iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	int N, pjCount = 0;
	char jia, yi;
	int jiaR[3] = { 0 }, yiR[3] = { 0 };//数组三个位置上分别代表B/C/J获胜的数量
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> jia >> yi;
		switch (jia)
		{
		case 'C':
			if (yi == 'B')
				yiR[0] += 1;
			else if (yi == 'J')
				jiaR[1] += 1;
			else
				pjCount++;
			break;
		case 'J':
			if (yi == 'C')
				yiR[1] += 1;
			else if (yi == 'B')
				jiaR[2] += 1;
			else
				pjCount++;
			break;
		case 'B':
			if (yi == 'J')
				yiR[2] += 1;
			else if (yi == 'C')
				jiaR[0] += 1;
			else
				pjCount++;
			break;
		}
	}
	cout << jiaR[0] + jiaR[1] + jiaR[2] << ' ' << pjCount << ' ' << yiR[0] + yiR[1] + yiR[2] << endl;
	cout << yiR[0] + yiR[1] + yiR[2] << ' ' << pjCount << ' ' << jiaR[0] + jiaR[1] + jiaR[2] << endl;
	if (jiaR[0] >= jiaR[1] && jiaR[0] >= jiaR[2])
		cout << 'B' << ' ';
	else if (jiaR[1] > jiaR[0] && jiaR[1] >= jiaR[2])
		cout << 'C' << ' ';
	else
		cout << 'J' << ' ';
	if (yiR[0] >= yiR[1] && yiR[0] >= yiR[2])
		cout << 'B';
	else if (yiR[1] > yiR[0] && yiR[1] >= yiR[2])
		cout << 'C';
	else
		cout << 'J';
	
	return 0;
}
