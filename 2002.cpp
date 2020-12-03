#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<string> inarr;
vector<string> outarr;
vector<bool> incheck;
vector<bool> outcheck;
int resultcount = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	string tmps;
	for (int i = 0; i < N; i++) {
		cin >> tmps;
		inarr.push_back(tmps);
		incheck.push_back(false);
	}
	for (int i = 0; i < N; i++) {
		cin >> tmps;
		outarr.push_back(tmps);
		outcheck.push_back(false);
	}
	for (int i = 0; i < inarr.size(); i++) {
		if (incheck[i] == true) continue;
		for (int j = i; j < outarr.size(); j++) {
			if (inarr[i] == outarr[j]) { incheck[i] = true; outcheck[j] = true; break; }
			else {
				if(outcheck[j]==false){
					resultcount++;
					for (int k = i + 1; k < inarr.size(); k++) {
						if (inarr[k] == outarr[j]) {
							incheck[k] = true;
							outcheck[j] = true;
							break;
						}
					}
				}
			}
		}
	}
	cout << resultcount << "\n";

	return 0;
}