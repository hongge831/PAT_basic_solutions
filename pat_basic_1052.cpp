#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	vector<vector<string>> vct;
	string str;
	int left = 0;
	/*�����ַ���*/
	for (int i = 0; i < 3; i++)
	{
		getline(cin, str);
		vector<string> v;
		for (int j = 0; j < str.length(); j++)
		{
			if (str[j] == '['){
				left = j;
			}if (str[j] == ']'){
				v.push_back(str.substr(left + 1, j - left - 1));
			}
		}vct.push_back(v);
	}
	/*�����û����뿪ʼ���*/
	int n;
	cin >> n;
	int a1, a2, a3, a4, a5;
	for (int i = 0; i < n; i++)
	{
		cin >> a1 >> a2 >> a3 >> a4 >> a5;
		if (a1<1 || a2<1 || a3<1 || a4<1 || a5<1 || a1 > vct[0].size() || a2>vct[1].size() || a3>vct[2].size() || a4 > vct[1].size() || a5 > vct[0].size()){
			cout << "Are you kidding me? @\\/@" << endl;//б�ܵ����Ҫ�������б�ܣ���ת���ַ����ǰ��б��
			continue;
		}
		else{
			cout << vct[0][a1-1] <<'('<< vct[1][a2-1] << vct[2][a3-1] << vct[1][a4-1] <<')'<< vct[0][a5-1] << endl;
		}
	}
	return 0;
}