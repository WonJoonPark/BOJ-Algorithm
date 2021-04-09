#include<bits/stdc++.h>
using namespace std;


//1~N 까지의 사람
// 체력은 100 기쁨은 0

int N;
int peopleL[21];
int peopleJ[21];
int happymaxvalue = -1;

void makecase(int index, int tmpl, int tmphappy) {
	for (int i = index; i <= N; i++) {
		if (tmpl - peopleL[i] <= 0) {
			if (tmphappy > happymaxvalue) {
				happymaxvalue = tmphappy;
			}
			return;
		}
		makecase(i+1,tmpl - peopleL[i], tmphappy + peopleJ[i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> peopleL[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> peopleJ[i];
	}
	makecase(1,100, 0);
	cout << happymaxvalue;
	return 0;
}