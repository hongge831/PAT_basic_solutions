#include <stdio.h>
#include <iostream>
#include <string>
#include <set>
using namespace std;

struct stuInfo{
	string id;
	int deScore;
	int caiScore;
	int totalScore;
};

struct greater{
	bool operator ()(const stuInfo &x, const stuInfo &y)const{
		if ((x.totalScore > y.totalScore) || (x.totalScore == y.totalScore&&x.deScore > y.deScore) || (x.totalScore == y.totalScore&&x.id < y.id&&x.deScore == y.deScore))
			return true;
		else
			return false;
	}
};

int main(){
	string id;
	int stuNum, lowLine, highLine, deScore, caiScor,count=0;//记录未达线的学生数量
	stuInfo in;
	multiset<stuInfo, greater> set1, set2, set3, set4;//分别是4类学生
	multiset<stuInfo, greater>::iterator it;
	cin >> stuNum >> lowLine >> highLine;
	/*输入分类开始*/
	for (int i = 0; i < stuNum; i++)
	{
		cin >> in.id;
		cin >> in.deScore >> in.caiScore;
		in.totalScore = in.deScore + in.caiScore;
		if (in.caiScore < lowLine || in.deScore < lowLine){
			count++;
			continue;
		}
		if (in.caiScore >= highLine && in.deScore >= highLine){
			set1.insert(in);
		}
		else if (in.caiScore < highLine && in.deScore >= highLine){
			set2.insert(in);
		}
		else if (in.caiScore < highLine && in.deScore < highLine&&in.deScore >= in.caiScore){
			set3.insert(in);
		}
		else{
			set4.insert(in);
		}
	}
	/*输入分类结束*/
	/*结果输出*/
	cout << stuNum - count << endl;
	it = set1.begin();
	while (it != set1.end()){
		cout << it->id<<' '<<it->deScore<<' '<<it->caiScore<<endl;
		it++;
	}
	it = set2.begin();
	while (it != set2.end()){
		cout << it->id << ' ' << it->deScore << ' ' << it->caiScore << endl;
		it++;
	}
	it = set3.begin();
	while (it != set3.end()){
		cout << it->id << ' ' << it->deScore << ' ' << it->caiScore << endl;
		it++;
	}
	it = set4.begin();
	while (it != set4.end()){
		cout << it->id << ' ' << it->deScore << ' ' << it->caiScore << endl;
		it++;
	}
	return 0;
}