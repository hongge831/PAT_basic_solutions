#include <iostream>
#include <string.h> 
using namespace std;

int bigger(char a[20], char b[20])
{
    int i=0;
    for(i=0;i<10;i++)
    {
        if(a[i]-b[i]>0)
            return 1;
        if(a[i]-b[i]<0)
            return 0;
    }
    return 0;
}

int main()
{
    int n,i,count=0;
    char a[10],old[10],young[10];
    char b[20],big[20]="1814/09/05",small[20]="2014/09/07";
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf("%s %s",a,b);
        if((bigger(b,"1814/09/05"))&&(bigger("2014/09/07",b)))
        {
            count++;
            if(bigger(b,big))
            {
                strcpy(big,b);
                strcpy(old,a);
            }
            if(bigger(small,b))
            {
                strcpy(small,b);
                strcpy(young,a);
            }
        }
    }
    if(count>0) 
        printf("%d %s %s\n",count,young,old);
    else 
        printf("0");
    system("pause");
    return 0; 
}
/*上面的是网络上的答案，没有用到结构体，时间稍微好一点，下面是我自己的答案，时间长一点*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
struct info{
	string name;
	string birthday;
} infoTemp;
bool compare(string a, string b){
	int i = 0;
	for (i = 0; i<10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (a[i] - b[i]>0)
			return false;
		if (a[i] - b[i]<0)
			return true;
	}
	return 0;

}
int main(){
	info infoArr, max, min;
	max.name = "hello";
	min.name = "fine";
	min.birthday = "2014/09/06";
	max.birthday = "1814/09/06";
	int n, count;
	count = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> infoArr.name >> infoArr.birthday;
		if (compare("1814/09/05", infoArr.birthday) && compare(infoArr.birthday, "2014/09/07")){
			count++;
			if (compare(infoArr.birthday, min.birthday)){
				min = infoArr;
			}if (compare(max.birthday, infoArr.birthday)){
				max = infoArr;
			}
		}
	}
	if (count >= 1)
		cout << count << ' ' << min.name << ' ' << max.name;
	else 
		cout << '0';


	return 0;


}