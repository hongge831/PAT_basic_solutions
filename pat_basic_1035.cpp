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
//�����������ҵ��Ĵ𰸣����������Լ��ġ�û����sort�����Լ�ʵ�ֹ鲢�������һ�����Դ����Գ�
#include <stdio.h>
#include <iostream>
using namespace std;
//�������֮�����
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
//�ж��Ƿ�Ϊ�������򣬲������ǹ鲢����
int isinsert(int * in1, int * in2, int n){
	int loc = -1;//������ǲ��������򷵻�-1�����򷵻ز��������λ����Ϣ
	int i;
	for (i = 0; i < n - 1; i++)
	{
		if (in2[i] > in2[i + 1]){
			loc = i;
			break;
		}
	}
	//��������������������ȫһ����Ϊ�������򣬷���1
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
	int L, i;//����鲢�γ���
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
	//������һ���Ĺ鲢����ʱ�Ĺ鲢�γ���ΪL
	//cout << L<<endl;
	int j = 0, k = L, m = 0;//m�����������е�λ��
	int j0 = j + L, k0 = k + L;
	while (k < n){
		for (; j < j0 && k < k0 && k < n;)
		{
			mgr[m] = in2[j] < in2[k] ? in2[j++] : in2[k++];
			m += 1;
		}
		if (j == j0){
			for (; k < k0&&k<n; k++)//�����K<N�����������������������Ե�5 ��6 ͨ����
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
	int n, loc;//loc��¼����������м䲽��Ľ���λ��
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