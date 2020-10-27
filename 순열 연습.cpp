#include<iostream>
#include<vector>
using namespace std;

//가능한 모든 순서 출력하자 (순열) -- 브루트포스(모든 경우의 수)
int N;
vector<int> cardnumarr;
int wholenum = 0;//전체 몇가지 경우의 수가 나오는 지 확인하기 위해서

void swap(int index1, int index2) { //위치 바꾸어 주기
	int tem = cardnumarr[index1];
	cardnumarr[index1] = cardnumarr[index2];
	cardnumarr[index2] = tem;
}

void brute(int sizenum) {
	if (sizenum == 1) { //재귀 함수 종료조건
		for (int i = 0; i < N; i++) {
			cout << cardnumarr[i] << ' ';
		}
		wholenum++;
		cout << '\n';
	}
	for (int i = 0; i < sizenum; i++) {
		swap(i, sizenum-1); // sizenum 이지만 입력받은 벡터는 인덱스가 (0~sizenum-1) 이므로
		brute(sizenum - 1); // 하나는 선택한 상태 전체에서 하나뺀 만큼만 결정 하면된다.
		swap(sizenum-1, i);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp; cardnumarr.push_back(tmp);
	}
	brute(N);
	cout << wholenum << '\n';
	return 0;
}