#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main(){
	string a1, a2;//�������������ʵ������,����
	char res[40] = { ' ' };
	int j = 0, k = 0, m = 0;//jָ��ʵ���ַ���λ�ã�k����洢λ��
	cin >> a1 >> a2;
	for (int i = 0; i < a1.length(); i++)
	{
		if (a1[i] != a2[j]){
			if (a1[i] <= 'z' && a1[i] >= 'a')
			{
				a1[i] -= 32;
			}
			for (m = 0; m < k; m++)
			{
				if (res[m] == a1[i])
					break;
			}
			if (m == k){
				res[k++] = a1[i];
			}

		}
		else{
			j++;
		}

	}
	for (int i = 0; i < k; i++)
	{
		cout << res[i];
	}

	return 0;
}