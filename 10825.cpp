#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int N;
struct studentscore {
	int kor; int eng; int mat;
	string name;
};
vector<studentscore> studentarr;

bool cmp(studentscore s1, studentscore s2) {
	if (s1.kor > s2.kor) { return true; }
	else if(s1.kor==s2.kor){
		if (s1.eng < s2.eng) return true;
		else if (s1.eng == s2.eng) {
			if (s1.mat > s2.mat) return true;
			else if (s1.mat == s2.mat) {
				if (s1.name< s2.name) return true;
				return false;
			}
			else return false;
		}
		else return false;
	}
	else return false;
}

void inputs() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		studentscore tmps;
		cin >> tmps.name >> tmps.kor >> tmps.eng >> tmps.mat;
		studentarr.push_back(tmps);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	inputs();
	sort(studentarr.begin(), studentarr.end(), cmp);
	for (int i = 0; i < studentarr.size(); i++) {
		cout << studentarr[i].name << "\n";
	}
	return 0;
}