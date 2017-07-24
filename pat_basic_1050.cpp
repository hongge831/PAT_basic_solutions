#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	/*数据初始化，包括求出矩阵的行和列，以及对输入数组进行降序排列*/
	int N, mind, m, n, temp = 0;
	vector<int> vct;
	cin >> N;
	mind = N;
	for (int i = 1; i*i <= N; i++)
	{
		if (N%i == 0){
			if ((N / i - i) < mind){
				mind = N / i - i;
				n = i;
				m = N / n;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		vct.push_back(temp);
	}
	sort(vct.rbegin(), vct.rend());
	/*设置螺旋边界值，并开始循环填入二维数组中*/
	vector<int> a(n, 0);
	vector<vector<int>> b(m, a);
	int b1 = n - 1, b2 = m - 1, b3 = 0, b4 = 0, sum = 0;
	int i = b4, j = b4;
	while (sum != N){
		for (i = b4; i <= b1&&sum != N; i++)
		{
			b[j][i] = vct[sum++];
		}i = b1; b1--; b4++;
		for (j = b4; j <= b2&&sum != N; j++)
		{
			b[j][i] = vct[sum++];
		}j = b2; b2--;
		for (i = b1; i >= b3&&sum != N; i--)
		{
			b[j][i] = vct[sum++];
		}i = b3, b3++;
		for (j = b2; j >= b4&&sum != N; j--)
		{
			b[j][i] = vct[sum++];
		}j = b4;

	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << b[i][j];
			if (j == (n - 1))
				cout << endl;
			else
				cout << ' ';
		}
	}
	return 0;
}