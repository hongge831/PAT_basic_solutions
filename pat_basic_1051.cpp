#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int main(){
	double r1, p1, r2, p2;//要用长整型，否则精度不够，另外要考虑四舍五入的规律
	double r, p, a, b;
	cin >> r1 >> p1 >> r2 >> p2;
	p = p1 + p2;
	r = r1*r2;
	a = r*cos(p);
	b = r*sin(p);
	if (a<0 && a>-0.005){
		printf("0.00");
	}
	else{
		printf("%.2lf", a);
	}
	if (b > 0){
		printf("+%.2lfi",b);
	}
	else if (b<0&&b>-0.005){
		printf("+%.2lfi", -1 * b);
	}
	else
	{
		printf("%.2lfi", b);
	}
	return 0;
}