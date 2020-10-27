#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int ts;
struct queuedata {
	int importance;
	int document;
};
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int dnum;
	int wantresult;
	int count;
	int tmpimportance;
	cin >> ts;
	while (ts--) {
		queue<queuedata> dataarr;
		vector<int> imparr;
		queuedata tmpd;
		count = 1;
		cin >> dnum >> wantresult;
		for (int i = 1; i <= dnum; i++) {
			tmpd.document = i;
			cin >> tmpd.importance;
			imparr.push_back(tmpd.importance); // 중요도 소팅하자
			dataarr.push(tmpd);
		}
		sort(imparr.begin(), imparr.end(),greater<int>() ); //중요도만 내림차순으로 정리 되어 있는 상태
		int n = 0;
		while (1) {
			tmpd = dataarr.front();
			if (tmpd.importance == imparr[n]) { // 소팅되었으므로 즉 중요도가 뒤에 자신보다 더 높은 문서가 없을 경우
				dataarr.pop();
				n++;
				if (tmpd.document == wantresult+1) {
					cout << count << '\n';
					break ;
				}
				count++; //몇번째로 출력되는지를 알아야 하므로
			}
			else {//뒤에 더 높은 문서가 있을경우 맨뒤로 간다.
				dataarr.pop();
				dataarr.push(tmpd);
			}
		}
	}
	return 0;
}