    #include <iostream>  
    #include <algorithm>  
    using namespace std;  
    int cmp(int a, int b) {  
     return a < b;  
    }  
    int main() {  
        int n;  
        cin >> n;  
        int *a = new int [n];  
        int *b = new int [n];  
          
        for (int i = 0; i < n; i++) {  
            cin >> a[i];  
        }  
        for (int i = 0; i < n; i++) {  
            cin >> b[i];  
        }  
          
        int i, j;  
        for (i = 0; i < n - 1 && b[i] <= b[i + 1]; i++);  
        for (j = i + 1; a[j] == b[j] && j < n; j++);  
        if (j == n) {  
            cout << "Insertion Sort" << endl;  
            sort(a, a + i + 2, cmp);  
        } else {  
            cout << "Merge Sort" << endl;  
            int k = 1;  
            int flag = 1;  
            while(flag) {  
                flag = 0;  
                for (i = 0; i < n; i++) {  
                    if (a[i] != b[i])  
                        flag = 1;  
                }  
                k = k * 2;  
                for (i = 0; i < n / k; i++)  
                    sort(a + i * k, a + (i + 1) * k, cmp);  
                sort(a + n / k * k, a + n, cmp);  
            }  
        }  
          
        for (j = 0; j < n - 1; j++) {  
            cout << a[j] << " ";  
        }  
        cout << a[n - 1];  
        return 0;  
    }  
//===============================================================================================================
//上面是网上找到的答案，下面是我自己的。没有用sort函数自己实现归并排序的下一步所以代码略长
#include <stdio.h>
#include <iostream>
using namespace std;
//排序完成之后输出
void print(int * in, int n){
	bool isfirst = true;
	for (int i = 0; i < n; i++)
	{
		if (isfirst){
			cout << in[i];
			isfirst = false;
		}
		else{
			cout << ' ' << in[i];
		}
	}
}
//判断是否为插入排序，不是则是归并排序
int isinsert(int * in1, int * in2, int n){
	int loc = -1;//如果不是插入排序则返回-1，否则返回插入排序的位置信息
	int i;
	for (i = 0; i < n - 1; i++)
	{
		if (in2[i] > in2[i + 1]){
			loc = i;
			break;
		}
	}
	//如果输入和排序后的序列完全一致则为插入排序，返回1
	if (i == n - 1){
		loc = 1;
	}
	else{
		for (int j = loc + 1; j < n; j++)
		{
			if (in1[j] != in2[j]){
				loc = -1;
				break;
			}
		}
	}
	return loc;
}

void insertion(int *in2, int loc){
	int temp = in2[loc + 1];
	int i = loc;
	while (in2[i] > temp){
		in2[i + 1] = in2[i];
		i--;
	}
	in2[i + 1] = temp;
}

void merge(int * in2, int n){
	int L, i;//代表归并段长度
	int *mgr = (int*)malloc(n*sizeof(int));
	for (L = 2; L < n; L *= 2)
	{
		for (i = L; i < n; i += 2 * L)
		{
			if (in2[i - 1] > in2[i]){
				break;
			}
		}
		if (i < n){
			break;
		}
	}
	//继续下一步的归并，此时的归并段长度为L
	//cout << L<<endl;
	int j = 0, k = L, m = 0;//m代表新数组中的位置
	int j0 = j + L, k0 = k + L;
	while (k < n){
		for (; j < j0 && k < k0 && k < n;)
		{
			mgr[m] = in2[j] < in2[k] ? in2[j++] : in2[k++];
			m += 1;
		}
		if (j == j0){
			for (; k < k0&&k<n; k++)//这里的K<N的情况和容易遗忘，否则测试点5 和6 通不过
			{
				mgr[m] = in2[k];
				m += 1;
			}
		}
		else if (k == k0||k==n){
			for (; j < j0; j++)
			{
				mgr[m] = in2[j];
				m += 1;
			}
		}

		j = k;
		k = k + L;
		j0 = j + L, k0 = k + L;
	}
	for (; j < j0; j++)
	{
		mgr[m] = in2[j];
		m += 1;
	}
	print(mgr, n);
	free(mgr);
}
int main(){
	int n, loc;//loc记录插入排序的中间步骤的进行位置
	cin >> n;
	int *in1 = (int *)malloc(n*sizeof(int));
	int *in2 = (int *)malloc(n*sizeof(int));
	for (int i = 0; i < n; i++)
	{
		cin >> in1[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> in2[i];
	}
	loc = isinsert(in1, in2, n);
	if (loc != -1){
		cout << "Insertion Sort" << endl;
		insertion(in2, loc);
		print(in2, n);
	}
	else{
		cout << "Merge Sort" << endl;
		merge(in2, n);
	}
	return 0;
}