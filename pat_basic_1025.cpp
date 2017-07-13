/*
˵��������û�ж�һЩ�Ƿ���������жϡ�
*/
#include <iostream>
#include <stdio.h>
#include <list>
#include <iomanip>
using namespace std;
typedef int ElementType;
//����ṹ���飬���ڹ�������
struct Node {
	ElementType left;
	ElementType value;
	ElementType right;
};
//����������
list<Node> init(int startPoint, int num, int k);//��ʼ���������������ڴ����ȡ��������
list<Node> ReverseL(list<Node> L, int k, int size);//����������Ҫ������
void Print(list<Node> L);//��ӡ����

int main(){
	list<Node> L, reverseL;
	int startPoint, num, k;
	cin >> startPoint >> num >> k;
	L = init(startPoint, num, k);//�����������޳��޹��ڴ���
	int size = L.size();
	reverseL = ReverseL(L, k, size);//�Թ����õ������������
	Print(reverseL);
	return 0;
}

list<Node> init(int startPoint, int num, int k){
	list<Node> L, tempL;
	list<Node>::iterator iter;
	Node tempNode;
	for (int i = 0; i < num; i++)//�������ű����ʽ���������ʵ��
	{
		cin >> tempNode.left;
		cin >> tempNode.value;
		cin >> tempNode.right;
		tempL.push_back(tempNode);
	}
	iter = tempL.begin();
	while (iter != tempL.end()){
		if (startPoint == iter->left){
			L.push_back(*iter);
			startPoint = iter->right;
			tempL.erase(iter);//���Ե�5��ʱ��Ҫ��ߣ���ԭʼ�������޳��Ѿ��ҵ�������
			iter = tempL.begin();
		}
		else{
			iter++;
		}
	}
	return L;
}

list<Node> ReverseL(list<Node> L, int k, int size){
	int shan = size / k;//��Ҫ���ε���
	list<Node>::iterator iter1;
	list<Node> RL;
	iter1 = L.begin();
	for (int j = 0; j < shan; j++)
	{
		advance(iter1, k - 1);
		for (int i = 0; i < k; i++)
		{
			RL.push_back(*iter1);
			if (i < k - 1)iter1--;

		}
		advance(iter1, k);
	}
	//��ʣ��Ĳ��ֲ��������������
	while (iter1 != L.end()){
		RL.push_back(*iter1);
		iter1++;
	}
	return RL;
}

void Print(list<Node> L){
	list<Node>::iterator iter1, temp;
	iter1 = L.begin();
	temp = L.end();
	advance(temp, -1);
	while (iter1 != temp){
		cout << setw(5) << setfill('0') << iter1->left << " " << iter1->value << " ";
		cout << setw(5) << setfill('0') << (++iter1)->left << endl;
	}
	cout << setw(5) << setfill('0') << iter1->left << " " << iter1->value << " " << -1 << endl;
}