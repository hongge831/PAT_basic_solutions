#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <math.h>
using namespace std;
int m, n, tol;
vector<vector<int>> v;
bool judge(int i, int j){
	//判断点的上下左右八个点的相对位置
	int loc[8][2] = { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } };
	int di, dj;
	for (int k = 0; k < 8; k++)
	{
		di = i + loc[k][0];
		dj = j + loc[k][1];
		//这里判断默认边界点是可以通过测试的，即边界点就不考虑和对应阈值的差
		if (di >= 0 && dj >= 0 && di < n && dj < m && abs(v[i][j] - v[di][dj])<=tol){ return false; }
	}
	return true;
}

int main(){
	cin >> m >> n >> tol;
	//对全局向量进行大小重定义
	v.resize(n,vector<int>(m));
	int cnt = 0, x = 0, y = 0;
	map<int, int> mp;
	//输入数据
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];
			mp[v[i][j]]++;
		}
	}
	//如果在map中已经发现对应数据个数超过1则不予考虑
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (mp[v[i][j]] == 1 && judge(i, j) == true){
				cnt++;
				x = j + 1;
				y = i + 1;
			}
		}
	}
	if (cnt == 1){
		printf("(%d, %d): %d\n", x, y, v[y - 1][x - 1]);//这里的xy一定要搞清楚方向
	}
	else if (cnt == 0){
		printf("Not Exist\n");
	}
	else{
		printf("Not Unique\n");
	}


	return 0;
}