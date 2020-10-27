#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

int N;
int goodword = 0;
void goodornot(string input){
	stack<char> tmpstack;
	for (int i = 0; i < input.length(); i++) {
		if (tmpstack.empty() == true) { tmpstack.push(input[i]); } //비어있을경우 그냥 스택에 넣는다.
		else if (tmpstack.top() == input[i]) { tmpstack.pop(); } //같은 글자
		else {//다른 글자가 들어왔을 떄
			tmpstack.push(input[i]);
		 }
	}
	if(tmpstack.empty()==true){ //다 짝이 맞다는 뜻.
		goodword++;
	}
	return;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	string word;
	for (int i = 0; i < N; i++) {
		cin >> word;
		goodornot(word);
	}
	cout << goodword << '\n';
	return 0;
}