#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string mdw[13] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string mgw[13] = { "", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
int main(){
	int n, num, result;
	result = 0;
	string in, str = "";
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++)
	{
		getline(cin, in);
		if (in[0] >= '0' && in[0] <= '9'){
			sscanf_s(in.c_str(), "%d", &num);
			if (num == 0){
				cout << mdw[0] << endl;
			}
			else{
				if (num % 13 == 0 && num != 0){
					cout << mgw[num / 13] << endl;
				}
				else if (num / 13 != 0){
					cout << mgw[num / 13] << ' ';
				}
				if (num % 13 != 0)
					cout << mdw[num % 13] << endl;
			}

		}
		else{
			for (int i = 0; i < in.size(); i += 4)
			{
				str = str + in[i] + in[i + 1] + in[i + 2];
				for (int j = 0; j < 13; j++)
				{
					if (str == mgw[j])
						result += j * 13;
					if (str == mdw[j])
						result += j;
				}
				str = "";
			}
			cout << result << endl;
			result = 0;
		}

	}
	return 0;
}
