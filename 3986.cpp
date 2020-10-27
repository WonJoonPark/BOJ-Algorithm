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
		if (tmpstack.empty() == true) { tmpstack.push(input[i]); } //���������� �׳� ���ÿ� �ִ´�.
		else if (tmpstack.top() == input[i]) { tmpstack.pop(); } //���� ����
		else {//�ٸ� ���ڰ� ������ ��
			tmpstack.push(input[i]);
		 }
	}
	if(tmpstack.empty()==true){ //�� ¦�� �´ٴ� ��.
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