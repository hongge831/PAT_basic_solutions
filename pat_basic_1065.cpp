#include <stdio.h>
#include <iostream>
#include <set>
#define M 99999
using namespace std;
struct information{
	int patner = -1;
	bool iscom = false;
};
int main(){
	int n,num1,num2;
	information info[M];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d %d", &num1, &num2);
		info[num1].patner = num2;
		info[num2].patner = num1;
	}

	int m,temp;
	set<int> s;
	set<int>::iterator it;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		info[temp].iscom = true;
		if (info[info[temp].patner].iscom != true){
			s.insert(temp);
		}
		else{
			s.erase(info[temp].patner);
		}
	}
	cout << s.size()<<endl;
	if (s.size() != 0){
		it = s.begin();
		printf("%05d", *(it++));
		for (int i = 1; i < s.size(); i++)
		{
			printf(" %05d", *(it++));
		}
	}
	return 0;
}