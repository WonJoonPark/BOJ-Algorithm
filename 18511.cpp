#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int n, k,tmp;
vector<int> numarr;
vector<int> resultarr; //nÀ» ÂÉ°³³õÀÚ

bool compare(int& lhs, int& rhs) {
	if (lhs > rhs) return true;
	else return false;
}

void makecase(int num,int cnt) {
	if (cnt!=0 && num <= n) { 
		resultarr.emplace_back(num);
	}
	if (num > n) return;
	for (int i = 0; i < k; i++) {
		if (cnt == 0) { makecase(num * numarr[i],cnt+1); }
		else makecase(num*10+numarr[i],cnt+1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	
	for (int i = 0; i < k; i++) {
		cin >> tmp;
		numarr.emplace_back(tmp);
	}
	sort(numarr.begin(), numarr.end(), compare);
	makecase(1,0);
	sort(resultarr.begin(), resultarr.end(), compare);
	cout << resultarr[0];
	return 0;
}
