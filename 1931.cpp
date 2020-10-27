#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct conference {
	int starttime;
	int finishtime;
};
bool compare(conference a, conference b) {
	if (a.finishtime == b.finishtime) {
		return a.starttime < b.starttime;
	}
	else {
		return a.finishtime < b.finishtime;
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<conference> carr;
	conference tmpc;
	while (N--) {
		cin >> tmpc.starttime;
		cin >> tmpc.finishtime;
		carr.push_back(tmpc);
	}
	sort(carr.begin(), carr.end(), compare);
	int currenttime = 0;
	int resultcount = 0;
	for (int i = 0; i < carr.size(); i++) {
		if (carr[i].finishtime >= currenttime) {
			if (carr[i].starttime >= currenttime) {
				resultcount++;
				currenttime = carr[i].finishtime;}}
	}
	cout << resultcount << '\n';
	return 0;
}