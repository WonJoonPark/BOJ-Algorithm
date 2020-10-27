#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int peoplenum;
int fnumcount;
int teamnum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	vector<int> scarearr(n);
	for (int i = 0; i < n; i++) {
		cin >> scarearr[i];
	}
	sort(scarearr.begin(), scarearr.end());
	int index=0;
	fnumcount = scarearr[index];
	while(n--){
		peoplenum++;
		if (fnumcount < scarearr[index]) {
			fnumcount = scarearr[index];
		}
		if (peoplenum == fnumcount) { 
			teamnum++;
			peoplenum = 0; }
		index++;
	}
	cout << teamnum << "\n";
	return 0;
}