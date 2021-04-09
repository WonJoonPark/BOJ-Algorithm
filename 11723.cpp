#include<bits/stdc++.h>
using namespace std;

int n, num;
char ss[10];
int main() {
	cin >> n;
	set<int> si;
	set<int>::iterator it;
	int x = 0;
	while (n--) {
		scanf(" %s", &ss);
		if (ss[0] == 'a' && ss[1] == 'd') {
			scanf("%d", &num);
			si.insert(num);
		}
		else if (ss[0] == 'r') {
			scanf("%d", &num);
			si.erase(num);
		}
		else if (ss[0] == 'c') {
			scanf("%d", &num);
			if (si.find(num) == si.end()) cout << "0" << "\n"; //못찾음 없음
			else cout << "1" << "\n";;
		}
		else if (ss[0] == 't') {
			scanf("%d", &num);
			if (si.find(num) == si.end()) { //없으면 넣고
				si.insert(num);
			}
			else { //있으면 지운다
				si.erase(num);
			}
		}
		else if (ss[0] == 'a') { //all 다 바꿈
			for (int i = 1; i < 21; i++) {
				si.insert(i);
			}
		}
		else if (ss[0] == 'e') {
			si.clear();
		}
	}
	return 0;
}