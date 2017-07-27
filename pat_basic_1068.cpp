#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <math.h>
using namespace std;
int m, n, tol;
vector<vector<int>> v;
bool judge(int i, int j){
	//�жϵ���������Ұ˸�������λ��
	int loc[8][2] = { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } };
	int di, dj;
	for (int k = 0; k < 8; k++)
	{
		di = i + loc[k][0];
		dj = j + loc[k][1];
		//�����ж�Ĭ�ϱ߽���ǿ���ͨ�����Եģ����߽��Ͳ����ǺͶ�Ӧ��ֵ�Ĳ�
		if (di >= 0 && dj >= 0 && di < n && dj < m && abs(v[i][j] - v[di][dj])<=tol){ return false; }
	}
	return true;
}

int main(){
	cin >> m >> n >> tol;
	//��ȫ���������д�С�ض���
	v.resize(n,vector<int>(m));
	int cnt = 0, x = 0, y = 0;
	map<int, int> mp;
	//��������
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];
			mp[v[i][j]]++;
		}
	}
	//�����map���Ѿ����ֶ�Ӧ���ݸ�������1���迼��
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
		printf("(%d, %d): %d\n", x, y, v[y - 1][x - 1]);//�����xyһ��Ҫ���������
	}
	else if (cnt == 0){
		printf("Not Exist\n");
	}
	else{
		printf("Not Unique\n");
	}


	return 0;
}