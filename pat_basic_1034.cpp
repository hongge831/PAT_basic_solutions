#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int measure(long long x, long long y)//需要记住三种求最大公约数和最大公倍数的算法
{
	long long z = y;
	while (x%y != 0)
	{
		z = x%y;
		x = y;
		y = z;
	}
	return z;
}
void init(long long a, long long b){
	if (b == 0){
		cout << "Inf";
		return;
	}
	long long gys = 1;
	long long zs;
	bool f = true;
	gys = measure(a, b);
	a /= gys;
	b /= gys;
	if ((a > 0 && b < 0) || (a < 0 && b>0)){
		cout << '(' << '-';
		f = false;
	}
	a = a > 0 ? a : a*-1;
	b = b > 0 ? b : b*-1;
	zs = a / b;
	a -= zs*b;
	if (zs > 0 && a != 0){
		cout << zs << ' ' << a << '/' << b;
	}
	else if (a == 0){
		cout << zs;
	}
	else if (zs == 0 && a!=0){
		cout << a << '/' << b;
	}

	if (!f)
		cout << ')';

}
void add(long long a1, long long a2, long long b1, long long b2){
	long long fenzi, fenmu;
	fenzi = a1*b2 + a2*b1;
	fenmu = b1*b2;
	init(fenzi,fenmu);
}
void sub(long long a1, long long a2, long long b1, long long b2){
	long long fenzi, fenmu;
	fenzi = a1*b2 - a2*b1;
	fenmu = b1*b2;
	init(fenzi, fenmu);
}
void mul(long long a1, long long a2, long long b1, long long b2){
	long long fenzi, fenmu;
	fenzi = a1*a2;
	fenmu = b1*b2;
	init(fenzi, fenmu);
}
void division(long long a1, long long a2, long long b1, long long b2){
	long long fenzi, fenmu;
	fenzi = a1*b2;
	fenmu = b1*a2;
	init(fenzi, fenmu);
}

int main(){
	string num1, num2;
	string sum, diff, div, acc;
	long long a1, a2, b1, b2;
	cin >> num1 >> num2;
	sscanf_s(num1.substr(0, num1.find('/')).c_str(), "%lld", &a1);
	sscanf_s(num2.substr(0, num2.find('/')).c_str(), "%lld", &a2);
	sscanf_s(num1.substr(num1.find('/') + 1).c_str(), "%lld", &b1);
	sscanf_s(num2.substr(num2.find('/') + 1).c_str(), "%lld", &b2);
	init(a1, b1); 
	cout << ' '<<'+'<<' ';
	init(a2, b2);
	cout <<' '<< '='<<' ';
	add(a1, a2, b1, b2);

	cout << endl;
	init(a1, b1);
	cout << ' ' << '-' << ' ';
	init(a2, b2);
	cout << ' ' << '=' << ' ';
	sub(a1, a2, b1, b2);
	cout << endl;

	init(a1, b1);
	cout << ' ' << '*' << ' ';
	init(a2, b2);
	cout << ' ' << '=' << ' ';
	mul(a1, a2, b1, b2);
	cout << endl;

	init(a1, b1);
	cout << ' ' << '/' << ' ';
	init(a2, b2);
	cout << ' ' << '=' << ' ';
	division(a1, a2, b1, b2);
	return 0;
}