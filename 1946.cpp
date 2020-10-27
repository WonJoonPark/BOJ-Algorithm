#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct applicant {
	int paperscore;
	int facescore;
};
bool cmp(applicant a, applicant b) {
	if (a.paperscore < b.paperscore) { return true; }
	else { return false; }
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int ts;
	int N;

	cin >> ts;
	while (ts--) {
		vector<applicant> apparr;
		cin >> N;
		applicant tmp;
		for (int i = 0; i < N; i++) {
			cin >> tmp.paperscore >> tmp.facescore;
			apparr.push_back(tmp);
		}
		sort(apparr.begin(), apparr.end(), cmp);
		int totalnum = apparr.size();
		for (int i = 1; i < apparr.size(); i++) {
			for (int j = 0; j < i; j++) {
				if (apparr[i].facescore > apparr[j].facescore) {
					totalnum--;
					break;
				}
			}
		}
		cout << totalnum << '\n';
	}
	return 0;
}