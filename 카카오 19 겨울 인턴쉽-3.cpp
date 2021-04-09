#include<bits/stdc++.h>
using namespace std;

vector<string> tmps;
int bsize;
int answer;

//별 갯수를 기준으로 소팅을 하자.

bool checkps(vector<string>& b) {
	vector<bool> visited(bsize);
	vector<pair<int,string>> tmpb;
	for (int i = 0; i < bsize; i++) {
		int c = 0;
		for (int j = 0; j < b[i].length(); j++) {
			if (b[i][j] == '*') c++;
		}
		tmpb.push_back({ c,b[i] });
	}
	sort(tmpb.begin(), tmpb.end());

	for (int i = 0; i < bsize; i++) { visited[i] = false; }
	for (int i = 0; i < bsize; i++) {
		for (int j = 0; j < bsize; j++) { //한 단어씩
			bool check = false;
			if (tmps[j].length() != tmpb[i].second.length()) continue; //길이가 맞지않으면
			if (visited[j] == true) continue;
			for (int k = 0; k < tmps[j].length(); k++) { //한 글자씩
				if (tmps[j][k] == tmpb[i].second[k] || tmpb[i].second[k] == '*') {
					if (k == tmps[j].length() - 1) {
						visited[j] = true; //이 단어는 이미 선택되었슴
						check = true;
					}
					continue;
				}
				else { break; }
			}
			if (check == true) break;
		}
	}

	for (int i = 0; i < bsize; i++) { if (visited[i] == false) return false; }
	return true;
}
void makecase(int cnt,int index,vector<string> &userid, vector<string> &bid) {
	if (cnt == bsize) {
		if (checkps(bid)) { 
			cout << "\n";
			for (int i = 0; i < tmps.size(); i++) {
				cout << tmps[i] << "\n";
			}
			cout << "\n";
			answer++; }
		return;
	}
	for (int i = index; i < userid.size(); i++) {
		tmps.push_back(userid[i]);
		makecase(cnt + 1, i + 1, userid,bid);
		tmps.pop_back();
	}
	
}

int solution(vector<string> user_id, vector<string> banned_id) {
	bsize = banned_id.size();
	makecase(0,0,user_id,banned_id);
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	vector<string> ui;
	vector<string> bi;

	ui.push_back("frodo");
	ui.push_back("fradi");
	ui.push_back("crodo");
	ui.push_back("abc123");
	ui.push_back("frodoc");

	bi.push_back("fr*d*");
	bi.push_back("*rodo");
	bi.push_back("******");
	bi.push_back("******");
	cout << solution(ui, bi);

	return 0;
}