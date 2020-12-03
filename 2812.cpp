#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
int N, K;
string inputs;
stack<char> results;
vector<char> output;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> K;
	cin >> inputs;
	for (int i = 0; i < inputs.size(); i++) {
		while (1) {
			if (results.empty() == true || inputs[i] <= results.top()||K==0) {
				results.push(inputs[i]);
				break;
			}
			else { results.pop(); K--; }
		}
	}
	if (K != 0) { for (int i = 0; i < K; i++) { results.pop(); } }
	int tmpsize = results.size();
	for (int i = 0; i < tmpsize; i++) {
		output.push_back(results.top());
		results.pop();
	}
	for (int i = output.size()-1; i >=0; i--) {
		cout << output[i];
	}

	return 0;
}