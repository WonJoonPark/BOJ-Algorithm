#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

struct box {
	int start;
	int end;
	int weight;
};
int N,C; //마을의 수 , 트럭의 용량
int M; // 박스정보의 수
int x, y, weight;
int result;
int truck[2001]; //마을 별 트럭의 공간을 표시하기 위해서 (트럭에 올라가있는 박스의 상태)

bool compare(box &lhs, box &rhs) {
	if (lhs.end < rhs.end) return true;
	else if (lhs.end == rhs.end) {
		if (lhs.start <= rhs.start) return true;
		else return false;
	}
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> C; //마을 수 와 트럭의 용량
	cin >> M;
	vector<box> sendbox(M);
	for (int i = 0; i < M; i++) {
		cin >> sendbox[i].start >> sendbox[i].end>>sendbox[i].weight;
	}
	sort(sendbox.begin(), sendbox.end(), compare);

	for (int i = 0; i < M; i++) {
		int cnt = 0;
		for (int j = sendbox[i].start; j < sendbox[i].end; j++) {
			cnt = max(truck[j], cnt);
		}
		result += min(sendbox[i].weight, C - cnt); //박스를 올리자 (담을 수 있는 양이 더 적으면 그 만큼만 올릴 수 있다)
		for (int j = sendbox[i].start; j < sendbox[i].end; j++) { //그 만큼 지나가는 마을에서의 트럭의 용량에서 빼줌
			truck[j] += min(sendbox[i].weight, C - cnt);
		}
	}
	cout << result << "\n";
	return 0;
}