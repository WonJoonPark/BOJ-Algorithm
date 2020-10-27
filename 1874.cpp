#include<iostream>
#include<stdio.h>
#include<stack>
#include<queue>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, tmp;
	cin >> n;
	queue<int> qar; //�������ϴ� ���
	vector<bool> oper; //��� ����� ���� +,- ���庤��
	stack<int> sar; // ����� ���� ����� ����
	for(int i=0;i<n;i++) {
		cin >> tmp;
		qar.push(tmp);
	}
	for (int i = 1; i <= n; i++) {
		if (i == qar.front()) {
			sar.push(i);
			oper.push_back(1);
			sar.pop();
			oper.push_back(0);
			qar.pop();
			while (1) {
				if (sar.empty() == false) {
					if (sar.top() == qar.front()) {
						sar.pop();
							oper.push_back(0);
							qar.pop();
					}
					else { break; }
				}
				else { break; }
			}
		}
		else {
			sar.push(i);
			oper.push_back(1);
		}
	}
	if(sar.empty()==true){
		for (int i = 0; i < oper.size(); i++) {
			if (oper[i] == 1) {
				cout << '+' << '\n';
			}
			else {
				cout << '-' << '\n';
			}
	    }
	}
	else { cout << "NO" << '\n'; }
	return 0;
}