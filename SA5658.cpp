#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstdio>
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T,n,k;
	cin >> T;
	for(int a=1;a<=T;a++) {
		cin >> n >> k;
		vector<char> tmpv(n);
		vector<string> results;
		vector<long long> output;
		
		for (int i = 0; i < n; i++) {
			cin >> tmpv[i];
		}
		int veclen = n / 4; // 한변의 길이 (수)
		int rotnum = n / 4;
		while (rotnum--) {
			// 계산
			for (int i = 0; i < 4; i++) {
				string tmps;
				for (int j = 0; j < veclen; j++) {
					tmps.push_back(tmpv[i*veclen + j]);
				}
				results.push_back(tmps); //현재는 중복포함
			}
			//회전 (시계방향)
			int tmpsave = tmpv[n - 1];
			for (int j = n - 2; j >= 0; j--) {
				tmpv[j + 1] = tmpv[j];
			}
			tmpv[0] = tmpsave;
		}


		for (int i = 0; i < results.size(); i++) {
			//16진수 char를 int형으로
			long long bi = 1;
			long long tmpi = 0;
			for (int j = results[i].length() - 1; j >= 0; j--) {
				int restoi=0;
				if (results[i][j] >= '0' && results[i][j] <= '9') restoi = results[i][j] - '0';
				else {
					restoi = 10 + (results[i][j] - 'A');
				}
				tmpi += (bi * restoi);
				bi *= 16;
			}

			bool excheck = false;
			for (int j = 0; j < output.size(); j++) {
				if (output[j] == tmpi) { excheck = true; break; }
			}
			if(excheck==false) output.push_back(tmpi);
		}
		sort(output.begin(), output.end(), greater<int>());
		cout <<"#"<<a<<" "<<output[k - 1] << "\n";
	}
	return 0;
}