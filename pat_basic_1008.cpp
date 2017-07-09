#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;
int main(){
	int N, M, temp, local;
	list<int> List;
	cin >> N >> M;
	local = M%N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		List.push_back(temp);
	}
	list<int>::iterator it1, it2;
	it1 = it2 = List.end();
	advance(it1, -local);
	advance(it2, -local-1);
	for (; it1 != List.end(); it1++)
	{
		cout << *it1 << " ";
	}it1 = List.begin();
	for (; it1 != it2; it1++)
	{
		cout << *it1 << " ";
	}cout << *it1;
	return 0;
}