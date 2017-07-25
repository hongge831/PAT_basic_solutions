#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
struct info{
	int score;
	int num;
	int answerN;
	string str;
};
int main(){
	int n, m;
	cin >> n >> m;
	vector<info> stu(m);
	for (int i = 0; i < m; i++)
	{
		cin >> stu[i].score >> stu[i].num >> stu[i].answerN;
		getchar();//用getline之前要用getchar清一下缓存
		getline(cin, stu[i].str);//获取选项字符串
	}
	int xzn;
	int fenshu = 0, wrongMax = 0;
	vector<int> wrong(m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			getchar();
			scanf_s("%d", &xzn);
			int len = xzn + xzn - 1;
			char *an = (char *)malloc((len + 1)*sizeof(char));
			for (int k = 0; k < len; k += 2)
			{
				scanf_s(" %c", &an[k]);
				an[k + 1] = ' ';
			}
			getchar();
			getchar();
			an[len] = '\0';
			//如果答对则加上相对应的分数
			if (strcmp(an, stu[j].str.c_str()) == 0){
				fenshu += stu[j].score;
			}//如果答错则加上答错的数目
			else{
				wrong[j]++;
			}

		}
		printf("%d\n", fenshu);
		fenshu = 0;

	}


	//输出最后结果
	for (int i = 0; i < m; i++)
	{
		if (wrong[i] > wrongMax){
			wrongMax = wrong[i];
		}
	}
	if (wrongMax == 0){
		cout << "Too simple" << endl;
	}
	else{
		printf("%d", wrongMax);
		for (int i = 0; i < m; i++) {
			if (wrong[i] == wrongMax) {
				printf(" %d", i + 1);
			}
		}
	}

	return 0;
}