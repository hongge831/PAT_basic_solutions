#include <stdio.h>
#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;
int main(){
	int m, n, s, count = 0;
	cin >> m >> n >> s;
	set<string> st;
	vector<string> v(m);
	for (int i = 0; i < m; i++)
	{
		cin >> v[i];
	}
	for (int i = s - 1; i < m; i += n)
	{
		if (st.find(v[i]) == st.end()){
			st.insert(v[i]);
			cout << v[i] << endl;
		}
		else{
			while (i < m){
				i += 1;
				if (st.find(v[i]) == st.end()){
					st.insert(v[i]);
					cout << v[i] << endl;
					break;
				}
				else{
					continue;
				}
			}
		}count++;
	}
	if (count == 0)
		cout << "Keep going..." << endl;
	return 0;
}

//别人的代码
#include <iostream>
#include <map>
using namespace std;
int main() {
    int m, n, s;
    scanf("%d%d%d", &m, &n, &s);
    string str;
    map<string, int> mapp;
    bool flag = false;
    for (int i = 1; i <= m; i++) {
        cin >> str;
        if (mapp[str] == 1) s = s + 1;
        if (i == s && mapp[str] == 0) {
            mapp[str] = 1;
            cout << str << endl;
            flag = true;
            s = s + n;
        }
    }
    if (flag == false) cout << "Keep going...";
    return 0;
}