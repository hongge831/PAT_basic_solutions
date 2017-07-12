#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

struct stuInfo{
	string id;
	int deScore;
	int caiScore;
	int totalScore;
};


bool cmp(const stuInfo &x, const stuInfo &y){
	if ((x.totalScore > y.totalScore) || (x.totalScore == y.totalScore&&x.deScore > y.deScore) || (x.totalScore == y.totalScore&&x.id < y.id&&x.deScore == y.deScore))
		return true;
	else
		return false;
}


int main(){
	string id;
	int stuNum, lowLine, highLine, deScore, caiScor, count = 0;//记录未达线的学生数量
	stuInfo in;
	vector<stuInfo> set1, set2, set3, set4;//分别是4类学生
	vector<stuInfo>::iterator it;
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
			set1.push_back(in);
		}
		else if (in.caiScore < highLine && in.deScore >= highLine){
			set2.push_back(in);
		}
		else if (in.caiScore < highLine && in.deScore < highLine&&in.deScore >= in.caiScore){
			set3.push_back(in);
		}
		else{
			set4.push_back(in);
		}
	}
	/*输入分类结束*/
	/*结果输出*/
	cout << stuNum - count << endl;
	it = set1.begin();
	sort(set1.begin(), set1.end(), cmp);
	while (it != set1.end()){
		//cout << it->id << ' ' << it->deScore << ' ' << it->caiScore << endl;//不能用cout，否则超时严重
		printf("%s %d %d\n", it->id.c_str(), it->deScore, it->caiScore);//标准库中没有string类，所以用printf输出string类要用c_str进行转换
		it++;
	}
	it = set2.begin();
	sort(set2.begin(), set2.end(), cmp);
	while (it != set2.end()){
		printf("%s %d %d\n", it->id.c_str(), it->deScore, it->caiScore);
		it++;
	}
	it = set3.begin();
	sort(set3.begin(), set3.end(), cmp);
	while (it != set3.end()){
		printf("%s %d %d\n", it->id.c_str(), it->deScore, it->caiScore);
		it++;
	}
	it = set4.begin();
	sort(set4.begin(), set4.end(), cmp);
	while (it != set4.end()){
		printf("%s %d %d\n", it->id.c_str(), it->deScore, it->caiScore);
		it++;
	}
	return 0;
}