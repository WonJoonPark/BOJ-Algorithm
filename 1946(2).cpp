#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct applicant {
	int paperscore;
	int facescore;
};
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
		int totalnum = apparr.size();;
		for (int i = 0; i < apparr.size(); i++) {
			for (int j = 0; j < apparr.size(); j++) {
				if (i != j) {
					if (apparr[i].facescore > apparr[j].facescore&&apparr[i].paperscore > apparr[j].paperscore) {
						totalnum--;
						break;
					}
				}
			}
		}
		cout << totalnum << '\n';
	}
	return 0;
}