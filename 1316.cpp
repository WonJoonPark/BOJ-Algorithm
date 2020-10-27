#include<iostream>
#include<vector>
#include<string>
using namespace std;

int N;
int counting = 0;
string word; //입력 받을 단어
vector<char> checkreinput; // 다시들어온 단어인지 확인하기 위한

bool checking_func(char a) {
	for (int i = 0; i < checkreinput.size(); i++) {
		if (checkreinput[i] == a) { return false; }
	}
	return true;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;


	for (int i = 0; i < N; i++) {
		cin >> word;   //입력을 받으면서 체크 할것
		bool checking = false; 
		for (int j = 0; j < word.length(); j++) {
			if (j == 0) {
				checkreinput.push_back(word[j]); //첫번째 문자는 그냥 넣어준다.
			}
			else if (word[j]!=word[j-1]) { //바로전 문자와 다른새로운 문자가 들어올경우
				if (checking_func(word[j]) == false) { checking = true; break; } //이미 들어왔던 목록에 있으면 이건 그룹단어가 아니다
				else { checkreinput.push_back(word[j]); } //들어왔던 문자가 아닐경우 중복체크벡터에 넣어놓는다.
			}
			else { // 연속되는문자가 들어오고 있을 경우 딱히 수행할 일은 없다.
				continue;
			}
		}
		if (checking == false) { counting++; } //모두 확인했는데 그룹단어일 경우 count를 하나 증가시켜준다.
		checkreinput.clear(); //서로다른 단어들을 체크해줘야 하므로 초기화 !
	}
	cout << counting << '\n';
	return 0;
}