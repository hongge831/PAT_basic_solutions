#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
	int n,count1=0,count2=0;
	int j1, j2, y1, y2;
	j1 = j2 = y1 = y2 = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d %d %d %d",&j1,&j2,&y1,&y2);
		if (j2 == (j1 + y1) && y2 != (j1 + y1)){
			count1++;
		}
		else if (y2 == (j1 + y1) && j2 != (j1 + y1)){
			count2++;
		}

	}cout << count2 << ' ' << count1 << endl;
	return 0;
}