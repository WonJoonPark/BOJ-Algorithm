#include<bits/stdc++.h>
using namespace std;

int T, n;
int studentarr[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		int teamcount = 0;
		int allcount = 0;
		for (int i = 1; i <= n; i++) {
			cin >> studentarr[i]; //������ ���� �ΰ� �;� �ϴ���.
		}
		for (int i = 1; i <= n; i++) {

			if (studentarr[i] == -1) continue;

			vector<int> tmpv;
			tmpv.push_back(i);
			int tmpi = studentarr[i];
			studentarr[i] = -1; 

			while (1) {
				bool c = false;
				int sindex;
				for (int j = 0; j < tmpv.size(); j++) {
					if (tmpi == tmpv[j]) { //����Ŭ�� �߻���
						c = true; 
					}
					if (c == true) {
						teamcount++;
					}
				}
				if (c == false) { //����Ŭ�� �߻����� ����
					tmpv.push_back(tmpi);
					int pretmpi = tmpi;
					tmpi = studentarr[tmpi];
					studentarr[pretmpi] = -1;
				}
				else break;
				if (tmpi == -1) break; // �̹� ���� �ɼ� ���� ����� ����
			}
		}
		cout << n - teamcount << "\n";
	}
	return 0;
}