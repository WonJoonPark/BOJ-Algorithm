#include<iostream>
#include<vector>
#include<string>
using namespace std;

int N;
int counting = 0;
string word; //�Է� ���� �ܾ�
vector<char> checkreinput; // �ٽõ��� �ܾ����� Ȯ���ϱ� ����

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
		cin >> word;   //�Է��� �����鼭 üũ �Ұ�
		bool checking = false; 
		for (int j = 0; j < word.length(); j++) {
			if (j == 0) {
				checkreinput.push_back(word[j]); //ù��° ���ڴ� �׳� �־��ش�.
			}
			else if (word[j]!=word[j-1]) { //�ٷ��� ���ڿ� �ٸ����ο� ���ڰ� ���ð��
				if (checking_func(word[j]) == false) { checking = true; break; } //�̹� ���Դ� ��Ͽ� ������ �̰� �׷�ܾ �ƴϴ�
				else { checkreinput.push_back(word[j]); } //���Դ� ���ڰ� �ƴҰ�� �ߺ�üũ���Ϳ� �־���´�.
			}
			else { // ���ӵǴ¹��ڰ� ������ ���� ��� ���� ������ ���� ����.
				continue;
			}
		}
		if (checking == false) { counting++; } //��� Ȯ���ߴµ� �׷�ܾ��� ��� count�� �ϳ� ���������ش�.
		checkreinput.clear(); //���δٸ� �ܾ���� üũ����� �ϹǷ� �ʱ�ȭ !
	}
	cout << counting << '\n';
	return 0;
}