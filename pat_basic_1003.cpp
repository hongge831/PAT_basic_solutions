#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main(){
	bool result = true;
	string str;
	int num, pcnt, acnt, tcnt, ploc, tloc;
	pcnt = acnt = tcnt = 0;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		result = true;
		pcnt = acnt = tcnt = 0;
		cin >> str;
		for (int j = 0; j < str.length(); j++)
		{
			if (str[j] != 'P' && str[j] != 'A' && str[j] != 'T'){
				result = false;
				break;
			}
			if (str[j] == 'P'){ pcnt += 1; }
			if (str[j] == 'A'){ acnt += 1; }
			if (str[j] == 'T'){ tcnt += 1; }
			if (pcnt == 2 || tcnt == 2){ result = false; break; }
		}
		ploc = str.find('P');
		tloc = str.find('T');
		if ((ploc*(tloc - ploc - 1) != str.length() - tloc - 1) || tloc < ploc || tloc - ploc < 2){
			result = false;
		}
		if (result == false){ cout << "NO" << endl; }
		else{ cout << "YES" << endl; }
	}
	return 0;
}