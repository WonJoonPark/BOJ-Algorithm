#include<bits/stdc++.h>
using namespace std;

int n;
long long cardset[100001];
int maxcount;
long long resultvalue;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cardset[i];
	}
	sort(cardset, cardset + n);
	maxcount = 1;
	resultvalue = cardset[0];
	int tmpcount = 1;
	for (int i = 1; i < n; i++) {
		if (cardset[i] == cardset[i - 1]) { 
			tmpcount++;
			if (i == n - 1) { //달라질때에만 값을 갱신하므로 , 마지막은 따로 계산해주어야함
				if (tmpcount > maxcount) { //같을때는 갱신하지 않는다.
					maxcount = tmpcount; resultvalue = cardset[i];
				}
			}
		}
		else {  
			if (tmpcount > maxcount) { //같을때는 갱신하지 않는다.
				maxcount = tmpcount; resultvalue = cardset[i - 1]; 
			}
			tmpcount = 1; }
	}
	cout << resultvalue;
	return 0;
}