#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
struct info{
	string name;
	int height;
};
bool cmp(const info a, const info b){
	if (a.height > b.height){
		return true;
	}
	else if (a.height == b.height&&strcmp(a.name.c_str(), b.name.c_str()) < 0)
	{
		return true;
	}
	else{
		return false;
	}
}

int main(){
	int n, k, m;
	cin >> n >> k;
	info stu;
	vector<info> v;
	for (int i = 0; i < n; i++)
	{
		cin >> stu.name >> stu.height;
		v.push_back(stu);
	}
	sort(v.begin(), v.end(), cmp);
	//�������
	int row = k;
	int loc = 0;
	while (row){
		if (row == k){
			m = n / k + n - k*(n / k);
		}
		else{
			m = n / k;
		}vector<string> vct(m);
		vct[m / 2] = v[loc].name;//��ȷ���м������ˣ�ע�������±��ʵ���±�Ĺ�ϵ
		int j = m / 2 - 1;
		//�����������
		for (int i = loc + 1; i < loc + m; i += 2)
		{
			vct[j--] = v[i].name;
		}
		j = m / 2 + 1;
		//���������ұ�
		for (int i = loc + 2; i < loc + m; i += 2)
		{
			vct[j++] = v[i].name;
		}
		cout << vct[0];
		for (int i = 1; i < vct.size(); i++)
		{
			cout << ' ' << vct[i];
		}
		cout << endl;
		loc += m;
		row--;

	}

	return 0;
}